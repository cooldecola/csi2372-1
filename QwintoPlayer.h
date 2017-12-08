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

    QwintoScoreSheet qwintoScoreSheet;

    QwintoPlayer(std::string n, QwintoScoreSheet qx):Player(n), qwintoScoreSheet(qx){};
    void inputBeforeRoll(RollOfDice *rollDice);
    void inputAfterRoll(RollOfDice *rollDice);


};

#endif //UNTITLED1_QWINTOPLAYER_H


