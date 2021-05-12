#include "OperationsExpert.hpp"
#include "string"
#include <typeinfo>

using namespace std;
using namespace pandemic;

namespace pandemic
{

    string OperationsExpert::role()
    {
        string name = typeid(OperationsExpert).name();
        return name;
    }

    Player &OperationsExpert::build()
    {
        this->gameBoard.build_research(currCity);
        return *this;
    }

}
