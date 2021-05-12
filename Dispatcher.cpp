#include "Dispatcher.hpp"
#include "Player.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic{

    Dispatcher::Dispatcher(Board& gameBoard, City currCity):Player(gameBoard, currCity){}
    
    string Dispatcher::role(){
       string name = typeid(Dispatcher).name();
       return name;
    }

    Player& Dispatcher::fly_direct(City city){
        this->currCity = city;
        return *this;
    }

}    