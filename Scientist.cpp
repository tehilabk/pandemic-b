#include "Scientist.hpp"

#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Scientist::Scientist(const Board &board, const City &city, const int numOfCards): Player(board, city){
        this->numOfCards= numOfCards;
    }

    string Scientist::role() {
        string name = typeid(Scientist).name();
        return name;
    }

    Player& Scientist::discover_cure(const Color& color) {
        return *this;
    }
}