#include "Scientist.hpp"

#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Scientist::Scientist(Board &gameBoard, City currCity, int numOfCards): Player(gameBoard, currCity){
        this->numOfCards= numOfCards;
    }

    string Scientist::role() {
        string name = typeid(Scientist).name();
        return name;
    }

    Player& Scientist::discover_cure(Color color) {
        if (!(colorCured[color])))
        {
            if (!(this->gameBoard.has_research(this->currCity)))
            {
                throw invalid_argument("can't discover_cure, need research in this city");
            }
            if (colorNum.at(color).size() < numOfCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            while (i < numOfCards)
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