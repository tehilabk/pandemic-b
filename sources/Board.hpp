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
        map<Color,bool>curesExist;
        map<City, data> dataMap;


    public:
        Board();
        int &operator[](City city);
        friend ostream &operator<<(ostream &out,Board &board);
        bool is_clean();
        void remove_cures();
        void remove_stations();
    
        friend bool is_neighbors(Board &b,City src, City dest);
        friend bool has_research(Board &b,City city);
        friend void build_research(Board &b,City city);
        friend int get_disease_level(Board &b,City city);
        friend void set_disease_level(Board &b,City city, int levelDown);
        friend bool is_discovered(Board &b,Color color);
        friend void discover_new_cure(Board &b,Color color);
        friend Color get_color(Board &b,City city);
        friend string to_string (Board &b,City city);
    };
}