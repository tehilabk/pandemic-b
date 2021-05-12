#include "Board.hpp"
#include "City.hpp"
#include <fstream>
using namespace std;
using namespace pandemic;

namespace pandemic
{

    Board::Board()
    {
        ifstream cities{"../cities_map.txt"};
        string city, color;
        while (cities >> city >> color)
        {
            City city_name = stringToCity.find(city)->second;
            dataMap[city_name].cityToString = city;
            dataMap[city_name].diseaseLevel = 0;
            dataMap[city_name].research = false;
            Color city_color = stringToColor.find(color)->second;
            dataMap[city_name].colorToString = color;
            dataMap[city_name].color = city_color;
            string neighbor;
            while (cities.peek() != '\n' && cities >> neighbor)
            {
                dataMap[city_name].neighbors.insert(stringToCity.find(neighbor)->second);
                neighbor = "";
            }
        }
        cities.close();
    }

    int &Board::operator[](City city)
    {
        return dataMap[city].diseaseLevel;
    }
    ostream &operator<<(ostream &out, Board &board)
    {
        return out;
    }

    bool Board::is_clean()
    {
        for (auto city : dataMap)
        {
            if (city.second.diseaseLevel != 0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures()
    {
    }

    void Board::remove_stations()
    {
        for (auto cities : dataMap)
        {
            cities.second.research = false;
        }
    }

    bool Board::is_neighbors(City src, City dest)
    {
        if (dataMap[src].neighbors.find(dest) == dataMap[src].neighbors.end())
        {
            return false;
        }
        return true;
    }

    bool Board::has_research(City city)
    {
        if (dataMap[city].research)
        {
            return true;
        }
        return false;
    }

    void Board::build_research(City city)
    {
        dataMap[city].research = true;
    }

    int Board::get_disease_level(City city)
    {
        return dataMap[city].diseaseLevel;
    }
    void Board::set_disease_level(City city, int levelDown)
    {
        if (dataMap[city].diseaseLevel >= levelDown)
        {
            dataMap[city].diseaseLevel -= levelDown;
        }
    }
    Color Board::get_color(City city){
        return dataMap[city].color;
    }

}