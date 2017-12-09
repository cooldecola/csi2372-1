//
// Created by Natesh Kukreja on 2017-12-01.
//

#ifndef UNTITLED1_QWINTOPLAYER_H
#define UNTITLED1_QWINTOPLAYER_H

#include "Player.h";
#include "RollOfDice.h";
#include "QwintoScoreSheet.h";

class QwintoPlayer: public Player {

public:

    //generic instance variable of qwintoScoreSheet created
    //for the object (the player -- whenever initialized)
    QwintoScoreSheet qwintoScoreSheet;

    //constructor method
    //simple initializer list
    QwintoPlayer(std::string n, QwintoScoreSheet qx):Player(n), qwintoScoreSheet(qx){};

    //methods to be implemented
    void inputBeforeRoll(RollOfDice *rollDice);
    void inputAfterRoll(RollOfDice *rollDice);


};

#endif //UNTITLED1_QWINTOPLAYER_H


