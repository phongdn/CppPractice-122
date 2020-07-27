#include <QCoreApplication>
#include "pa1.h"

int main(int argc, char *argv[])
{
    //remove line below if running program on an IDE that is not Qt Creator
    QCoreApplication a(argc, argv);
    ifstream file("../PA1/FitbitData.csv");
    string line;
    Fitbit data[1440];
    struct Fitbit current;
    int counter = 0;
    if(!file) {
        cout << "unable to open file" << endl;
        throw "Error opening file";
    }

    while(getline(file, line)) {
        //Skip title line.
        if(counter == 0) {
            counter = 1;
            continue;
        }
        //Remove if statement below. For testing purposes.
        if(counter == 70) {
            return 1;
        }
        tokenizeLine(line, &current);
        ++counter;
    }
    return 0;
}

void tokenizeLine(string lineToParse, Fitbit *current) {
    int hours, minutes, totalMinutes, arrayCounter = 0;
    string words[9];
    cout << lineToParse << endl;
    auto words_begin = sregex_iterator(lineToParse.begin(), lineToParse.end(), delim);
    auto words_end = sregex_iterator();

    for(sregex_iterator i = words_begin; i != words_end; ++i) {
        words[arrayCounter] = (*i).str();
        ++arrayCounter;
    }

    //words[0] = hours, words[1] = minutes
    totalMinutes = (stoi(words[0]) * 60 + stoi(words[1]));
    strcpy(current->minute, to_string(totalMinutes).c_str());
    cout << "Minute: " << current->minute << endl;
}
