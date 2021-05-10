#include "Researcher.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    Researcher::Researcher(const Board &board, const City &city): Player(board, city){
    }

    string Researcher::role() {
        string name = typeid(Researcher).name();
        return name;
    }

     Player& Researcher::discover_cure(const Color& color) {
        return *this;
    }
}