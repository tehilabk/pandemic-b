#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "string"
#include <set>
#include <map>
#include <stdio.h>

using namespace std;
namespace pandemic{

const int fiveCards = 5;

class Player{

    protected:
        Board& gameBoard;
        City currCity;
        set<City> cards;
        map<Color,set<City>> colorNum;
       

    
    public:
        Player(Board& board, City city):gameBoard(board), currCity(city){}
        virtual Player& drive(City dest);
        virtual Player& fly_direct(City dest);
        virtual Player& fly_charter(City dest);
        virtual Player& fly_shuttle(City dest);
        virtual Player& build();               
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);
        Player& take_card (City city);
        virtual std::string role () = 0;
        void remove_cards();
    };
}    