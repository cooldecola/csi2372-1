//
// Created by Natesh Kukreja on 2017-11-30.
//

#ifndef UNTITLED1_QWIXXSCORESHEET_H
#define UNTITLED1_QWIXXSCORESHEET_H

#include <iostream>
#include<list>
#include <vector>

#include "ScoreSheet.h"

class QwixxScoreSheet : public ScoreSheet {

private:

    std::vector<int> red = {0,0,0,0,0,0,0,0,0,0,0}, yellow= {0,0,0,0,0,0,0,0,0,0,0};
    std::list<int> blue= {0,0,0,0,0,0,0,0,0,0,0}, green= {0,0,0,0,0,0,0,0,0,0,0};
    std::list<int>::iterator it;
    int redMax = 0, yellowMax = 0, greenMax = 0, blueMax = 0;

public:
    QwixxScoreSheet(const std::string& name):ScoreSheet(name){};
    virtual bool calcTotal(Color c, int val, int pos){};
    virtual void setTotal(Color c, int val, int pos){};
    virtual int getOverallScore(){};
    void getRedScore(){};
    void getYellowScore(){};
    void getBlueScore(){};
    void getGreenScore(){};
};


#endif //UNTITLED1_QWIXXSCORESHEET_H
