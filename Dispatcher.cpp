#include "Dispatcher.hpp"
#include "Player.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic{

    Dispatcher::Dispatcher(const Board& board, const City& city):Player(board, city){}
    
    string Dispatcher::role(){
       string name = typeid(Dispatcher).name();
       return name;
    }

    Player& Dispatcher::fly_direct(const City& city){
        return *this;
    }

}    