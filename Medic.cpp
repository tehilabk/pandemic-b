#include "Medic.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Medic::Medic(const Board &board, const City &city): Player(board, city){
    }

    string Medic::role() {
        string name = typeid(Medic).name();
        return name;
    }

    Player& Medic::treat(const City& city) {
        return *this;
    }
}