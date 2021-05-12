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
    public:
        OperationsExpert(Board& gameBoard, City currCity);
        string role();
        Player& build();
};

}