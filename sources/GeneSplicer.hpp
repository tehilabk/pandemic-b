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
     private:
        
        string my_role;
    public:
        GeneSplicer(Board& gameBoard, City currCity): Player(gameBoard, currCity) {
            my_role = "GeneSplicer";
        }
        string role();
        Player& discover_cure(Color color);
};

}    