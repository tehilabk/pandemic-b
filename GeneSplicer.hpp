#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

class GeneSplicer: public Player{
    public:
        GeneSplicer(const Board& board, const City& city);
        string role();
        Player& discover_cure(const Color& color);
};

}    