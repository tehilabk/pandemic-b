#include "Virologist.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Virologist::role() {
        string name = typeid(Virologist).name();
        return name;
    }

    Player& Virologist::treat(City city) {
        int disease_level = gameBoard.get_disease_level(city);
        if (disease_level == 0)
        {
            throw invalid_argument("can't treat, disease level=0");
        }
        if (colorCured[gameBoard.get_color(city)])
        {
            gameBoard.set_disease_level(city, disease_level);
        }
        else
        {
            gameBoard.set_disease_level(city, 1);
        }
        return *this;
    }
}