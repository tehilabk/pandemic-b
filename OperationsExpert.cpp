#include "OperationsExpert.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{
    OperationsExpert::OperationsExpert(const Board &board, const City &city): Player(board, city){}

    string OperationsExpert::role() {
        string name = typeid(OperationsExpert).name();
        return name;
    }

    Player& OperationsExpert::build() {
        return *this;
    }
}