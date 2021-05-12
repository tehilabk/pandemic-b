#include "GeneSplicer.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic
{

    GeneSplicer::GeneSplicer(Board &gameBoard, City currCity) : Player(gameBoard, currCity) {}

    string GeneSplicer::role()
    {
        string name = typeid(GeneSplicer).name();
        return name;
    }

    Player &GeneSplicer::discover_cure(Color color)
    {
        if (!(colorCured[color]))
        {
            if (!(gameBoard.has_research(currCity)))
            {
                throw invalid_argument("can't discover_cure, need research in this city");
            }
            if (cards.size() < fiveCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            set<City> removCard;
            for (auto card : cards)
            {
                if (i < 5)
                {
                    removCard.insert(card);
                    cards.erase(card);
                    i++;
                }
                for (auto card : removCard)
                {
                    colorNum[gameBoard.get_color(card)].erase(card);
                }
            }
            colorCured[color] = true;
        }
        return *this;
    }
}