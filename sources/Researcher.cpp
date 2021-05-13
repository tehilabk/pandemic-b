#include "Researcher.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Researcher::role()
    {
        string name = typeid(Researcher).name();
        return name;
    }

    Player &Researcher::discover_cure(Color color)
    {
        if (!(is_discovered(this->gameBoard,color)))
        {
            if (colorNum[color].size() < fiveCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            set<City> removCard;

            for (auto &card : colorNum[color])
            {
                if (i < 5)
                {
                    removCard.insert(card);
                    cards.erase(card);
                    i++;
                }
            }
            for (auto &card : removCard)
            {
                colorNum[get_color(this->gameBoard,card)].erase(card);
            }
            discover_new_cure(this->gameBoard,color);
        }
        return *this;
    }
}