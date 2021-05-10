#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class Researcher: public Player{
    public:
        Researcher(const Board& board, const City& city);
        string role();
        Player& discover_cure(const Color& color);
};

}    