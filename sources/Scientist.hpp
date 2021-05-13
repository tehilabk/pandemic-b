#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <typeinfo>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic
{

    class Scientist : public Player
    {
    private:
        int numOfCards;
        string my_role;


    public:
        Scientist(Board &gameBoard, City currCity, int numOfCards) : Player(gameBoard, currCity)
        {
            this->numOfCards = numOfCards;
            my_role = "Scientist";
        }
        string role();
        Player &discover_cure(Color color);
    };
}