//
// Created by Natesh Kukreja on 2017-12-01.
//

#ifndef UNTITLED1_QWINTOPLAYER_H
#define UNTITLED1_QWINTOPLAYER_H


class QwintoPlayer: public Player {

private:
    QwintoScoreSheet qwintoScoreSheet;

public:
    QwintoPlayer():Player(){};
    QwintoScoreSheet qx = QwintoScoreSheet("");
    virtual void inputBeforeRoll(DiceMaster *rollDice);
    virtual void inputAfterRoll(DiceMaster *rollDice);
};

#endif //UNTITLED1_QWINTOPLAYER_H
