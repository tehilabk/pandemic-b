#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "string"
#include <typeinfo>
using namespace std;
using namespace pandemic;

namespace pandemic{


    string FieldDoctor::role(){
       string name = typeid(FieldDoctor).name();
       return name;
    }
    
    Player& FieldDoctor::treat(City city){
        return *this;
    }


}    