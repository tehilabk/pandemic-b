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
        int disease_level = get_disease_level(this->gameBoard,city);
        if (disease_level == 0)
        {
            throw invalid_argument("can't treat, disease level=0");
        }
        if (is_discovered(this->gameBoard,get_color(this->gameBoard,city)))
        {
            set_disease_level(this->gameBoard,city, disease_level);
        }
        else
        {
            set_disease_level(this->gameBoard,city, 1);
        }
        return *this;
    }
}