//
// Created by Natesh Kukreja on 2017-12-01.
//

#ifndef UNTITLED1_QWIXXPLAYER_H
#define UNTITLED1_QWIXXPLAYER_H

#include "Player.h"
#include "QwixxScoreSheet.h"
#include "DiceMaster.h"

class QwixxPlayer: public Player {

private:
    QwixxScoreSheet qwixxScoreSheet;

public:
    QwixxPlayer():Player(){};
    QwixxScoreSheet qx = QwixxScoreSheet("");
    virtual void inputBeforeRoll(DiceMaster *rollDice);
    virtual void inputAfterRoll(DiceMaster *rollDice);
};


#endif //UNTITLED1_QWIXXPLAYER_H
