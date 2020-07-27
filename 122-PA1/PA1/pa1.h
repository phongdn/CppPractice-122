#ifndef PA1_H
#define PA1_H

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <sstream>
#include <charconv>

//Header file for main.cpp
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::sregex_iterator;
using std::stringstream;
using std::regex;
using std::stoi;
using std::to_string;
using std::to_chars;


const regex delim("[^,:]+");

enum sleep {
    NONE = 0,
    ASLEEP,
    AWAKE,
    REALLYAWAKE
};

struct Fitbit {
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    sleep sleepLevel;
};

void tokenizeLine(string lineToParse, Fitbit *currrent);

#endif // PA1_H
