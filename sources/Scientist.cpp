#include "Scientist.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Scientist::role()
    {
        return my_role;
    }

    Player &Scientist::discover_cure(Color color)
    {
        if (!(is_discovered(this->gameBoard,color)))
        {
            if (!(has_research(this->gameBoard,currCity)))
            {
                throw invalid_argument("can't discover_cure, need research in this city");
            }
            if (colorNum[color].size() < numOfCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            set<City> removCard;

            for (const auto &card : colorNum[color])
            {
                if (i < numOfCards)
                {
                    removCard.insert(card);
                    cards.erase(card);
                    i++;
                }
            }
            for (const auto &card : removCard)
            {
                colorNum[get_color(this->gameBoard,card)].erase(card);
            }

            discover_new_cure(this->gameBoard,color);
        }
        return *this;
    }
}