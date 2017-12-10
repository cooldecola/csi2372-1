#ifndef UNTITLED1_QWINTOSCORESHEET_H
#define UNTITLED1_QWINTOSCORESHEET_H

#include <iostream>
#include "ScoreSheet.h"
#include "QwintoRow.h"

class QwintoScoreSheet : public ScoreSheet<QwintoScoreSheet> {

public:
    QwintoScoreSheet(const std::string& name):ScoreSheet(name){};

    QwintoRow<Colour::RED> redScore;
    QwintoRow<Colour::YELLOW> yellowScore;
    QwintoRow<Colour::BLUE> blueScore;

    //implementing the virtual method created in the parent
    //class, ScoreSheet
    //method returns if the score can be inputed or not
    bool score(RollOfDice& rd, Colour c, int pos = -1);

    //implementing the pure virtual method that was
    //initialized in the parent class, ScoreSheet
    //method sets the total score per user

    int setTotal(){
        this->overallScore = calcTotal();
        return overallScore;
    };

    int getRedScore();
    int getYellowScore();
    int getBlueScore();

    //returns true if there are two rows in the that
    //are filled. If true, the game is over
    bool twoFilledRows();

    //implementing pure virtual method that was
    //initialized in the parent class ScoreSheet
    //method calculates the total score of each
    //player
    int calcTotal();

    //helper method
    int getOverallScore(){return overallScore;};

    bool checkIfGameOver();

    //overriding the not operator
    //virtual function that was initilized in the parent class
    //implemented here
    bool operator!();

    ostream& operator<<(ostream& os);

};


#endif //UNTITLED1_QWINTOSCORESHEET_H