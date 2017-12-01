//
// Created by Natesh Kukreja on 2017-11-29.
//

#ifndef UNTITLED1_QWINTOSCORESHEET_H
#define UNTITLED1_QWINTOSCORESHEET_H

#include <iostream>
#include "ScoreSheet.h"

class QwintoScoreSheet : public ScoreSheet {

public:
    QwintoScoreSheet(const std::string& name):ScoreSheet(name){};
    virtual bool calcTotal(Color c, int val, int pos){};
    virtual int setTotal(Color c, int val, int pos){};
    virtual int getOverallScore(){};
    void getRedScore(){};
    void getYellowScore(){};
    void getBlueScore(){};
};


#endif //UNTITLED1_QWINTOSCORESHEET_H
