#include "Medic.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Player &Medic::drive(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't drive from city to itself");
        }
        if (!(is_neighbors(this->gameBoard,currCity, dest)))
        {
            throw invalid_argument("can't drive, this cities not neighbors");
        }
        if (is_discovered(this->gameBoard,get_color(this->gameBoard,dest)))
        {
            int disease_level = get_disease_level(this->gameBoard,dest);
            set_disease_level(this->gameBoard,dest, disease_level);
        }
        Player::drive(dest);
        return *this;
    }
    Player &Medic::fly_direct(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_direct from city to itself");
        }
        if (cards.find(dest) == cards.end())
        {
            throw invalid_argument("can't fly_direct, need the city card");
        }
        if (is_discovered(this->gameBoard,get_color(this->gameBoard,dest)))
        {
            int disease_level = get_disease_level(this->gameBoard,dest);
           set_disease_level(this->gameBoard,dest, disease_level);
        }
        Player::fly_direct(dest);
        return *this;
    }
    Player &Medic::fly_charter(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_direct from city to itself");
        }
        if (cards.find(dest) == cards.end())
        {
            throw invalid_argument("can't fly_direct, need the city card");
        }
        if (is_discovered(this->gameBoard,get_color(this->gameBoard,dest)))
        {
            int disease_level = get_disease_level(this->gameBoard,dest);
            set_disease_level(this->gameBoard,dest, disease_level);
        }
        Player::fly_charter(dest);
        return *this;
    }
    Player &Medic::fly_shuttle(City dest) {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_shuttle from city to itself");
        }
        if (!((has_research(this->gameBoard,currCity)) && (has_research(this->gameBoard,dest))))
        {
            throw invalid_argument("can't fly_shuttle, need research in cities");
        }
        if (is_discovered(this->gameBoard,get_color(this->gameBoard,dest)))
        {
            int disease_level = get_disease_level(this->gameBoard,dest);
            set_disease_level(this->gameBoard,dest, disease_level);
        }
        Player::fly_shuttle(dest);
        return *this;
    }

    string Medic::role()
    {
        string name = typeid(Medic).name();
        return name;
    }

    Player &Medic::treat(City city)
    {
        if (currCity != city)
        {
            throw invalid_argument("can't treat another city");
        }
        int disease_level = get_disease_level(this->gameBoard,city);
        if (disease_level == 0)
        {
            throw invalid_argument("can't treat, disease level=0");
        }
        set_disease_level(this->gameBoard,city, disease_level);
        return *this;
    }
}