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
        Medic(Board &gameBoard, City currCity);
        string role();
        Player& treat(City city);
};
}        