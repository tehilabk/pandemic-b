#include "Board.hpp"
#include "City.hpp"
#include <fstream>
using namespace std;
using namespace pandemic;

namespace pandemic
{

    Board::Board()
    {
        ifstream cities{"cities_map.txt"};
        string city, color;
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

    int &Board::operator[](City city)
    {
        return this->dataMap[city].diseaseLevel;
    }
    ostream &operator<<(ostream &out, Board &board)
    {
        return out;
    }

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

    void Board::remove_cures()
    {
        for (auto &cure : this->curesExist)
        {
            cure.second = false;
        }
    }

    void Board::remove_stations()
    {
        for (auto &cities : this->dataMap)
        {
            cities.second.research = false;
        }
    }

    bool is_neighbors(Board &b,City src, City dest)
    {
        if (b.dataMap[src].neighbors.find(dest) == b.dataMap[src].neighbors.end())
        {
            return false;
        }
        return true;
    }

    bool has_research(Board &b,City city)
    {
        return (b.dataMap.at(city).research);
        
    }

    void build_research(Board &b,City city)
    {
        b.dataMap[city].research = true;
    }

    int get_disease_level(Board &b, City city)
    {
        return b.dataMap[city].diseaseLevel;
    }
    void set_disease_level(Board &b,City city, int levelDown)
    {
        if (b.dataMap[city].diseaseLevel >= levelDown)
        {
            b.dataMap[city].diseaseLevel -= levelDown;
        }
    }

    bool is_discovered(Board &b,Color color)
    {
        if (b.curesExist[color])
        {
            return true;
        }
        return false;
    }
    void discover_new_cure(Board &b,Color color)
    {
        b.curesExist[color] = true;
    }
    Color get_color(Board &b,City city)
    {
        return b.dataMap[city].color;
    }

    string to_string (Board &b,City city){
        return b.dataMap[city].cityToString;
    }


}