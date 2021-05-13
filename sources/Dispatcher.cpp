#include "Dispatcher.hpp"
#include "Player.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Dispatcher::role()
    {
       return my_role;
    }

    Player &Dispatcher::fly_direct(City city)
    {
        if (currCity == city)
        {
            throw invalid_argument("can't fly_direct from city to itself");
        }
        if (has_research(this->gameBoard, currCity))
        {
            this->currCity = city;
        }
        else
        {
            return Player::fly_direct(city);
        }
        return *this;
    }

}