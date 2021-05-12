#include "Player.hpp"

using namespace std;
using namespace pandemic;



    Player &Player::drive(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't drive from city to itself");
        }
        if (!(gameBoard.is_neighbors(currCity, dest)))
        {
            throw invalid_argument("can't drive, this cities not neighbors");
        }
        currCity = dest;
        return *this;
    }

    Player &Player::fly_direct(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_direct from city to itself");
        }
        if (cards.find(dest) == cards.end())
        {
            throw invalid_argument("can't fly_direct, need the city card");
        }
        cards.erase(dest);
        currCity = dest;
        return *this;
    }
    Player &Player::fly_charter(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_charter from city to itself");
        }
        if (cards.find(currCity) == cards.end())
        {
            throw invalid_argument("can't fly_charter, need this city card");
        }
        cards.erase(dest);
        currCity = dest;
        return *this;
    }
    Player &Player::fly_shuttle(City dest)
    {
        if (currCity == dest)
        {
            throw invalid_argument("can't fly_shuttle from city to itself");
        }
        if (!((gameBoard.has_research(currCity)) && (gameBoard.has_research(dest))))
        {
            throw invalid_argument("can't fly_shuttle, need research in cities");
        }
        currCity = dest;
        return *this;
    }

    Player &Player::build()
    {
        if (!(gameBoard.has_research(currCity)))
        {
            if (cards.find(currCity) == cards.end())
            {
                throw invalid_argument("can't build, need this city card");
            }
            gameBoard.build_research(currCity);
            cards.erase(currCity);
        }
        return *this;
    }

    Player &Player::discover_cure(Color color)
    {
        if (!(colorCured[color]))
        {
            if (!(gameBoard.has_research(currCity)))
            {
                throw invalid_argument("can't discover_cure, need research in this city");
            }
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
            colorCured[color] = true;
        }
        return *this;
    }
    Player &Player::treat(City city)
    {
         if (currCity != city)
        {
            throw invalid_argument("can't treat another city");
        }
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
    Player &Player::take_card(City city)
    {
        cards.insert(city);
        colorNum[gameBoard.get_color(city)].insert(city);
        return *this;
    }
    void Player::remove_cards()
    {
        cards.clear();
        colorNum.clear();
    }

