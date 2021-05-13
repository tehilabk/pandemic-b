#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class Virologist: public Player{
     private:
        string my_role;
    public:
        Virologist(Board &gameBoard, City currCity):Player(gameBoard, currCity){
            my_role = "Virologist";
        }
        string role();
        Player& treat(City city);
};
}        