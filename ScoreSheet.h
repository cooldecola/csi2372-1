//
// Created by Natesh Kukreja on 2017-11-29.
//

#ifndef UNTITLED1_SCORESHEET_H
#define UNTITLED1_SCORESHEET_H

#include <iostream>

static const int g_height = 3;
static const int g_width = 14;

class ScoreSheet {

protected:

    std::string player_Name;
    int numFailed = 0;
    int overallScore;
    virtual bool score(int& x, RollOfDice rd, Color c, int pos = -1) = 0;

private:
    int score_Red[];
    int score_Yellow[];
    int score_Blue[];
    int score_White[];

    int allColorsScore[g_height][g_width];

    int scoreOverall = 0;
    int num_Failed=0;



    ScoreSheet(const std::string& name):player_Name(name){};

public:
    virtual int setTotal(...) = 0;

    virtual bool calcTotal() = 0;
    virtual bool operator!(...);
};


#endif //UNTITLED1_SCORESHEET_H
