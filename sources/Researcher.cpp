#include "Researcher.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string Researcher::role()
    {
        return my_role;
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

            for (const auto &card : colorNum[color])
            {
                if (i < fiveCards)
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