#include "GeneSplicer.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic{

    GeneSplicer:: GeneSplicer(const Board& board, const City& city):Player(board, city){}

    string GeneSplicer::role(){
        string name = typeid(GeneSplicer).name();
        return name;
    }

    Player& GeneSplicer::discover_cure(const Color& color){
        return *this;
    }
}