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
    static int numFail=0;
    int position = -1;
    //constructor for the class
    //same constructor for qwixx and qwinto
    ScoreSheet(const std::string& name):player_Name(name){};
    virtual bool score(RollOfDice &rd, Colour c, int position) = 0;

    //when constructed
    int overallScore = 0;



    //returns the overall score of the player
    //helper function
    int getOverallScore(){return overallScore;};

    //pure virtual methods to be implemented in
    //QwintoScoreSheet QwixxScoreSheet

    virtual int setTotal() = 0;
    virtual int calcTotal() = 0;



    //overriding not operator
    virtual bool operator!() = 0;

    virtual bool checkIfGameOver() = 0;

    int getNumFail(){return numFail;};
    void setNumFail(){numFail++;};
};


#endif //UNTITLED1_SCORESHEET_H
