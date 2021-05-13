#pragma once
#include <map>
#include "string"
#include <stdio.h>
using namespace std;

namespace pandemic{

    enum class Color{
        Blue,
        Yellow,
        Black,
        Red
    };
    static const map<std::string , Color> stringToColor ={
        {"Yellow",Color::Yellow},
        {"Red",Color::Red},
        {"Blue",Color::Blue},
        {"Black",Color::Black},
    };
}        