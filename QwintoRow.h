//
// Created by Natesh Kukreja on 2017-12-07.
//

#ifndef CPP_PROJECT_QWINTOROW_H
#define TEST_ROW
#define CPP_PROJECT_QWINTOROW_H
#include <iostream>
#include "Colour.h"
#include "RollOfDice.h"


using namespace std;

template <Colour T> class QwintoRow{
public:

    //overriding operator and returns the
    //index at the score list
    RollOfDice& operator[] (const int index){
        return scoreList[index];
    };


    //create a row of size 9 containing
    //RollOfDice
    //New row created for each object that is sent through
    RollOfDice scoreList[9];

    ostream& operator<<(ostream &os);


};

int main(){

    RollOfDice rd;
    rd.roll();
    QwintoRow<Colour::RED> red;
    red[2] = rd;

}


#ifndef TEST_ROW

#endif //CPP_PROJECT_QWINTOROW_H
