#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "string"
#include "vector"
#include <stdio.h>

using namespace std;
namespace pandemic{

class Player{

    private:
        Board gameBoard;
        City currCity;
        vector<City> cards;

    public:
        Player(const Board& board, const City& city);
        ~Player(){};
        virtual Player& drive(const City& city);
        virtual Player& fly_direct(const City& city);
        virtual Player& fly_charter(const City& city);
        virtual Player& fly_shuttle(const City& city);
        virtual Player& build();               
        virtual Player& discover_cure(const Color& color);
        virtual Player& treat(const City& city);
        Player& take_card (const City& city);
        virtual std::string role () = 0;
    };
}    