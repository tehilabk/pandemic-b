#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class Researcher: public Player{
    public:
        Researcher(Board& gameBoard, City currCity): Player(gameBoard, currCity){}
        string role();
        Player& discover_cure(Color color);
};

}    