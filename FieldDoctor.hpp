
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
    public:
        FieldDoctor(Board& board, City city);
        string role();
        Player& treat(City city);
};
}        