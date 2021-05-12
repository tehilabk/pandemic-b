#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <stdio.h>
#include <fstream>
#include <map>
#include <set>
#include "string"

using namespace std;

namespace pandemic
{
    class Board
    {
    private:
        struct data
        {
            set<City> neighbors;
            int diseaseLevel;
            bool research;
            Color color;
            string cityToString;
            string colorToString;
        };
        map<City, data> dataMap;

    public:
        Board();
        int &operator[](City city);
        friend ostream &operator<<(ostream &out,Board &board);
        bool is_clean();
        void remove_cures();
        void remove_stations();
    
        bool is_neighbors(City src, City dest);
        bool has_research(City city);
        void build_research(City city);
        int get_disease_level(City city);
        void set_disease_level(City city, int levelDown);
        Color get_color(City city);
    };
}