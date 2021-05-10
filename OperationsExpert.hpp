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
        OperationsExpert(const Board& board, const City& city);
        string role();
        Player& build();
};

}