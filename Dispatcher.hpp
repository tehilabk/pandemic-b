#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;


namespace pandemic{

class Dispatcher: public Player{
    public:
        Dispatcher(Board& gameBoard, City currCity);
        string role();
        Player& fly_direct(City city);
};

}    