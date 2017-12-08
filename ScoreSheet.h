#ifndef UNTITLED1_SCORESHEET_H
#define UNTITLED1_SCORESHEET_H

#include <iostream>
#include "RollOfDice.h";
#include "Colour.h"

static const int g_height = 3;
static const int g_width = 14;

template <class T>
class ScoreSheet {


private:
    std::string player_Name;

    ostream& operator<<(ostream& os, T& sheet);

public:
    //constructor for the class
    //same constructor for qwixx and qwinto
    ScoreSheet(const std::string& name):player_Name(name){};

    //when constructed
    int overallScore = 0;

    //returns the overall score of the player
    //helper function
    int getOverallScore(){return overallScore;};

    //pure virtual methods to be implemented in
    //QwintoScoreSheet QwixxScoreSheet

    virtual int setTotal(...) = 0;
    virtual int calcTotal() = 0;

    //
    virtual bool score(RollOfDice &rd, Colour c, int pos = -1) = 0;

    //overriding not operator
    virtual bool operator!() = 0;
};


#endif //UNTITLED1_SCORESHEET_H
