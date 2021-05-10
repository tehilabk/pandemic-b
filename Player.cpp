#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Player::Player(const Board& board, const City& city){
        this->gameBoard = board;
        this->currCity = city;
    }

    Player &Player::drive(const City &city)
    {
        return *this;
    }
    Player &Player::fly_direct(const City &city)
    {
        return *this;
    }
    Player &Player::fly_charter(const City &city)
    {
        return *this;
    }
    Player &Player::fly_shuttle(const City &city)
    {
        return *this;
    }
    Player &Player::build()
    {
        return *this;
    }
    Player &Player::discover_cure(const Color &color)
    {
        return *this;
    }
    Player &Player::treat(const City &city)
    {
        return *this;
    }
    Player &Player::take_card(const City &city)
    {
        return *this;
    }

}