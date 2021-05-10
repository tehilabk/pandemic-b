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
            bool cure;
            string cityToString;
            string colorToString;
        };
        map<City, data> dataMap;

    public:
        Board();
        int &operator[](const City &city);
        friend ostream &operator<<(ostream &out, const Board &board);
        bool is_clean();
        void remove_cures();
        void remove_stations();
    };
}