#include "Board.hpp"
#include "City.hpp"
#include <fstream>
using namespace std;
using namespace pandemic;

namespace pandemic{

    Board::Board(){
        ifstream cities{"cities_map.txt"};
        string city, color;
        while (cities >> city >> color){
            City city_name = stringToCity.find(city)->second;
            dataMap[city_name].cityToString = city;
            dataMap[city_name].diseaseLevel = 0;
            dataMap[city_name].research = false;
            dataMap[city_name].cure = false;
            Color city_color = stringToColor.find(color)->second;
            dataMap[city_name].colorToString = color;
            dataMap[city_name].color = city_color;
            string neighbor;
            while (cities.peek() != '\n' && cities >> neighbor){
                dataMap[city_name].neighbors.insert(stringToCity.find(neighbor)->second);
                neighbor = "";
            }
        }
        cities.close();
    }

    int& Board::operator[](const City& city){
        return dataMap[city].diseaseLevel;
    }
    ostream& operator<<(ostream& out, const Board& board){
        return out;
    }

    bool Board::is_clean(){
        for(auto city : dataMap){
            if(city.second.diseaseLevel != 0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        for(auto cities : dataMap){
            cities.second.cure = false;
        }
    }

    void Board::remove_stations(){
         for(auto cities : dataMap){
            cities.second.research = false;
        }
    }

}    