#include "Virologist.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Virologist::Virologist(const Board &board, const City &city): Player(board, city){
    }

    string Virologist::role() {
        string name = typeid(Virologist).name();
        return name;
    }

    Player& Virologist::treat(const City& city) {
        return *this;
    }
}