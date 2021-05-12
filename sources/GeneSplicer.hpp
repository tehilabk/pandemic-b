#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class GeneSplicer: public Player{
    public:
        GeneSplicer(Board& gameBoard, City currCity): Player(gameBoard, currCity) {}
        string role();
        Player& discover_cure(Color color);
};

}    