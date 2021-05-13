#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class OperationsExpert: public Player{
    private:
        string my_role;
    public:
        OperationsExpert(Board& gameBoard, City currCity): Player(gameBoard, currCity) {
            my_role = "OperationsExpert";
        }
        string role();
        Player& build();
};

}