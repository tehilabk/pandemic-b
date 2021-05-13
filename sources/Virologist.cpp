#include "Virologist.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Virologist::role()
    {
        return my_role;
    }

    Player &Virologist::treat(City city)
    {
        if (currCity == city)
        {
            return Player::treat(city);
        }
        else if (cards.find(city) == cards.end())
        {
            throw invalid_argument("can't fly_direct, need the city card");
        }
    
        int disease_level = get_disease_level(this->gameBoard, city);
        if (disease_level == 0)
        {
            throw invalid_argument("can't treat, disease level=0");
        }
        if (is_discovered(this->gameBoard, get_color(this->gameBoard, city)))
        {
            set_disease_level(this->gameBoard, city, disease_level);
        }
        else
        {
            set_disease_level(this->gameBoard, city, 1);
        }
        return *this;
    }
}