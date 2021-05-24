#include "Player.hpp"
#include <iostream>

using namespace std;
using namespace pandemic;


/*
--------------------------------------------
drive from city to another if they are connected 
--------------------------------------------
*/

Player &Player::drive(City dest)
{
    if (currCity == dest)
    {
        throw invalid_argument("can't drive from city to itself");
    }
    if (!(is_neighbors(gameBoard,currCity, dest)))
    {
        throw invalid_argument("can't drive, this cities not neighbors");
    }
    currCity = dest;
    return *this;
}

/*
--------------------------------------------
fly direct from city to another only with card of the city dest
--------------------------------------------
*/
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
    colorNum[get_color(gameBoard,dest)].erase(dest);
    currCity = dest;
    return *this;
}

/*
--------------------------------------------
fly charter from city to another only with card of current city
--------------------------------------------
*/
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
    cards.erase(currCity);
    colorNum[get_color(gameBoard,currCity)].erase(currCity);
    currCity = dest;
    return *this;
}


/*
--------------------------------------------
fly shuttle from city to another only if there is research station in current city and dest city 
--------------------------------------------
*/
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

/*
--------------------------------------------
build research station with card of current city
--------------------------------------------
*/
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
        colorNum[get_color(gameBoard,currCity)].erase(currCity);
    }
    return *this;
}

/*
--------------------------------------------
discover cure in a specified color:
1.there is a research station in current city
2.throw 5 cards with same color of discovered cure
--------------------------------------------
*/
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
            colorNum[get_color(gameBoard,card)].erase(card);
        }

        discover_new_cure(gameBoard,color);
    }
    return *this;
}

/*
--------------------------------------------
treat the disease of current city on one level 
1. if there is cure of city color - the city completly cured
2. if there is no disease - throw exeption
--------------------------------------------
*/
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

/*
--------------------------------------------
take city card
--------------------------------------------
*/
Player &Player::take_card(City city)
{
    
    colorNum[get_color(gameBoard,city)].insert(city);
    cards.insert(city);
    return *this;
}

/*
--------------------------------------------
removes all cards for this pleyer
--------------------------------------------
*/
void Player::remove_cards()
{
    this->cards.erase(this->cards.begin(), this->cards.end());
    colorNum.clear();
}
