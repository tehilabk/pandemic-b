#include "Researcher.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
   

    string Researcher::role() {
        string name = typeid(Researcher).name();
        return name;
    }

     Player& Researcher::discover_cure(Color color) {
        if (!(colorCured[color]))
        {
            if (colorNum.at(color).size() < fiveCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            while (i < 5)
            {
                auto deletCity = colorNum.at(color).begin();
                cards.erase(deletCity);
                colorNum.at(color).erase(deletCity);
                i++;
            }
            colorCured[color]=true;
        } 
        return *this;
    }
}