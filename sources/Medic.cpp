#include "Medic.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
   

    string Medic::role() {
        string name = typeid(Medic).name();
        return name;
    }

    Player& Medic::treat(City city) {
        if (currCity != city)
        {
            throw invalid_argument("can't treat another city");
        }
        int disease_level = gameBoard.get_disease_level(city);
        if (disease_level == 0)
        {
            throw invalid_argument("can't treat, disease level=0");
        }
        
        gameBoard.set_disease_level(city, disease_level);
        return *this;
        
    }
}