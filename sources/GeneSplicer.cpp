#include "GeneSplicer.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic
{

    string GeneSplicer::role()
    {
        return my_role;
    }

    Player &GeneSplicer::discover_cure(Color color)
    {
        if (!(is_discovered(this->gameBoard,color)))
        {
            if (!(has_research(this->gameBoard,currCity)))
            {
                throw invalid_argument("can't discover_cure, need research in this city");
            }
            if (cards.size() < fiveCards)
            {
                throw invalid_argument("can't discover_cure, need five card in this color");
            }
            int i = 0;
            set<City> removCard;
            for (auto &card : cards)
            {
                if (i < 5)
                {
                    removCard.insert(card);
                    i++;
                }
            }
            for (auto &card : removCard)
            {
                cards.erase(card);
                colorNum[get_color(this->gameBoard,card)].erase(card);
            }

            discover_new_cure(this->gameBoard,color);
        }
        return *this;
    }
}