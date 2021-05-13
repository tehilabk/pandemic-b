#include "Player.hpp"
#include <iostream>

using namespace std;
using namespace pandemic;

Player &Player::drive(City dest)
{
    if (currCity == dest)
    {
        throw invalid_argument("can't drive from city to itself");
    }
    if (is_neighbors(gameBoard,currCity, dest)== false)
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
    if (!((has_research(gameBoard,currCity)) && (has_research(gameBoard,dest))))
    {
        throw invalid_argument("can't fly_shuttle, need research in cities");
    }
    currCity = dest;
    return *this;
}

Player &Player::build()
{
    if (!(has_research(gameBoard,currCity)))
    {
        if (cards.find(currCity) == cards.end())
        {
            throw invalid_argument("can't build, need this city card");
        }
        build_research(gameBoard,currCity);
        cards.erase(currCity);
    }
    return *this;
}

Player &Player::discover_cure(Color color)
{
    if (!(is_discovered(gameBoard,color)))
    {
        if (!(has_research(gameBoard,currCity)))
        {
            throw invalid_argument("can't discover_cure, need research in this city");
        }
        if (colorNum.at(color).size() < fiveCards)
        {
            throw invalid_argument("can't discover_cure, need five card in this color");
        }
        int i = 0;
        set<City> removCard;

        for (auto card : colorNum[color])
        {
            if (i < 5)
            {
                removCard.insert(card);
                cards.erase(card);
                i++;
            }
        }
        for (auto card : removCard)
        {
            colorNum[get_color(gameBoard,card)].erase(card);
        }

        discover_new_cure(gameBoard,color);
    }
    return *this;
}
Player &Player::treat(City city)
{
    if (currCity != city)
    {
        throw invalid_argument("can't treat another city");
    }
    int disease_level = get_disease_level(gameBoard,city);
    if (disease_level == 0)
    {
        throw invalid_argument("can't treat, disease level=0");
    }
    if (is_discovered(gameBoard,get_color(gameBoard,city)))
    {
        set_disease_level(gameBoard,city, disease_level);
    }
    else
    {
        set_disease_level(gameBoard,city, 1);
    }
    return *this;
}
Player &Player::take_card(City city)
{
    cards.insert(city);
    colorNum[get_color(gameBoard,city)].insert(city);
    return *this;
}
void Player::remove_cards()
{
    cards.clear();
    colorNum.clear();
}
