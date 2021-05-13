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
    private:
        string my_role;
    public:
        Dispatcher(Board& gameBoard, City currCity): Player(gameBoard, currCity) {
            my_role = "Dispatcher";
        }
        string role();
        Player& fly_direct(City city);
};

}    