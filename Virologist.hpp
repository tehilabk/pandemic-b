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
    public:
        Virologist(const Board& board, const City& city);
        string role();
        Player& treat(const City& city);
};
}        