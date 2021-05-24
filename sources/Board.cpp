#include "Board.hpp"
#include "City.hpp"
#include <fstream>
using namespace std;
using namespace pandemic;

namespace pandemic
{
/*
--------------------------------------------
init cities and neighbors frome map game
--------------------------------------------
*/
    Board::Board()
    {
        ifstream cities{"cities_map.txt"};
        string city;
        string color;
        while (cities >> city >> color)
        {
            City city_name = stringToCity.find(city)->second;
            this->dataMap[city_name].cityToString = city;
            this->dataMap[city_name].diseaseLevel = 0;
            this->dataMap[city_name].research = false;
            Color city_color = stringToColor.find(color)->second;
            this->dataMap[city_name].colorToString = color;
            this->dataMap[city_name].color = city_color;
            string neighbor;
            while (cities.peek() != '\n' && cities >> neighbor)
            {
                this->dataMap[city_name].neighbors.insert(stringToCity.find(neighbor)->second);
                neighbor = "";
            }
        }
        cities.close();
    }
/*
--------------------------------------------
set disease level in a specified city
--------------------------------------------
*/
    int &Board::operator[](City city)
    {
        return this->dataMap[city].diseaseLevel;
    }

/*
--------------------------------------------
print the current game status
--------------------------------------------
*/
    ostream &operator<<(ostream &out, Board &board)
    {
        out << "***********************Game Board!***********************\n"<< endl;

        out << "----------------------Disease Status:----------------------\n"<< endl;
        for (auto &city : board.dataMap)
        {
            out << "City: " << city.second.cityToString << ", Disease Level :" << city.second.diseaseLevel << endl;
        }
        out << "----------------------Cures Discovered:----------------------\n"<< endl;
        for (auto &cure : board.curesExist)
        {
            if(cure.second == true){
                for (auto &city : board.dataMap)
                {
                    if(cure.first == city.second.color){
                        out << "Color: " << city.second.colorToString <<endl;
                    }
                }
            }

        }
        out << "----------------------Research Stations:----------------------\n"<< endl;
         for (auto &city : board.dataMap)
        {
            if(city.second.research){
            out << "City : " << city.second.cityToString<< endl;
        }
        }

        return out;
    }
    
/*
--------------------------------------------
return if board is clean from diseases
--------------------------------------------
*/
    bool Board::is_clean()
    {
        for (auto &city : this->dataMap)
        {
            if (city.second.diseaseLevel > 0)
            {
                return false;
            }
        }
        return true;
    }

/*
--------------------------------------------
remove all cures in discovered in the game
--------------------------------------------
*/
    void Board::remove_cures()
    {
        for (auto &cure : this->curesExist)
        {
            cure.second = false;
        }
    }

/*
--------------------------------------------
remove all research stations in the game
--------------------------------------------
*/
    void Board::remove_stations()
    {
        for (auto &cities : this->dataMap)
        {
            cities.second.research = false;
        }
    }
    

//*************** Help Functions***************


/*
--------------------------------------------
returns if City src and City dest is neighbors
--------------------------------------------
*/

    bool is_neighbors(Board &b, City src, City dest)
    {
        return !(b.dataMap[src].neighbors.find(dest) == b.dataMap[src].neighbors.end());
    }
/*
--------------------------------------------
returns if there is research station in a specified city
--------------------------------------------
*/

    bool has_research(Board &b, City city)
    {
        return (b.dataMap.at(city).research);
    }
/*
--------------------------------------------
build research station in a specified city
--------------------------------------------
*/
    void build_research(Board &b, City city)
    {
        b.dataMap[city].research = true;
    }
/*
--------------------------------------------
returns the disease_level in a specified city
--------------------------------------------
*/
    int get_disease_level(Board &b, City city)
    {
        return b.dataMap[city].diseaseLevel;
    }
/*
--------------------------------------------
set the disease_level in a specified city
--------------------------------------------
*/   
    void set_disease_level(Board &b, City city, int levelDown)
    {
        if (b.dataMap[city].diseaseLevel >= levelDown)
        {
            b.dataMap[city].diseaseLevel -= levelDown;
        }
    }
/*
--------------------------------------------
returns if there is cure for spesified color
--------------------------------------------
*/
    bool is_discovered(Board &b, Color color)
    {
        return (b.curesExist[color]);
    }

/*
--------------------------------------------
discoveres new cure for spesified color
--------------------------------------------
*/    
    void discover_new_cure(Board &b, Color color)
    {
        b.curesExist[color] = true;
    }
/*
--------------------------------------------
returns the color of spesified city
--------------------------------------------
*/    
    Color get_color(Board &b, City city)
    {
        return b.dataMap[city].color;
    }


}