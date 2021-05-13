
#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;
namespace pandemic{

class FieldDoctor: public Player{
    private:
        string my_role;
    public:
        FieldDoctor(Board& gameBoard, City currCity): Player(gameBoard, currCity) {
            my_role = "FieldDoctor";
        }
        string role();
        Player& treat(City city);
};
}        