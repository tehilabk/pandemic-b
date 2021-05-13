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
    private:
        string my_role;
    public:
        Researcher(Board& gameBoard, City currCity): Player(gameBoard, currCity){
            my_role = "Researcher";
        }
        string role();
        Player& discover_cure(Color color);
};

}    