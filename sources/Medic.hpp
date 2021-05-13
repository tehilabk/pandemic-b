#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class Medic: public Player{
    public:
        Medic(Board &gameBoard, City currCity): Player(gameBoard, currCity) {}
        Player& drive(City dest);
        Player& fly_direct(City dest);
        Player& fly_charter(City dest);
        Player& fly_shuttle(City dest);
        string role();
        Player& treat(City city);
};
}        