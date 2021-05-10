#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class Scientist: public Player{
    private:
        int numOfCards;
    public:
        Scientist(const Board& board, const City& city, const int numOfCards);
        string role();
        Player& discover_cure(const Color& color);
};
}    