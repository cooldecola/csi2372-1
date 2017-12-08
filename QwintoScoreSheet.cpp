//
// Created by Natesh Kukreja on 2017-11-29.
//

#include "QwintoScoreSheet.h"

ostream& QwintoScoreSheet::operator<<(ostream& os){

    std::string dash = "-";

    for(int i = 0; i <31;i++){
        dash = dash+"-";
    }

    redScore<<os;
    yellowScore<<os;
    blueScore<<os;

    os<<"\n"<<dash;

    int failedThrows = 0;

    if(getNumFail()>0){
        os<<"\n Failed Throws: ";
        for(int i=0; i<getNumFail(); i++){
            os<< " "<<i<<" ";
        }
    }

    os<<"\n";

    return os;

}


bool QwintoScoreSheet::checkIfGameOver() {

    int counterR = 0;
    int counterY = 0;
    int counterB = 0;

    for(int i= 0; i<9; i++){
        if(redScore[i] == 0){
            counterR++;
        }
    }
    for(int i= 0; i<9; i++){
        if(yellowScore[i] == 0){
            counterY++;
        }
    }
    for(int i= 0; i<9; i++){
        if(blueScore[i] == 0){
            counterB++;
        }
    }

    if((numFail == 4)||((counterB==0 &&counterR==0)||(counterB==0 &&counterY==0)||(counterB==0 &&counterR==0))){
        return true;
    }
    else{return false;}

};

int QwintoScoreSheet::getRedScore(){

    int zerosRed = 0;

    for(int i = 0; i<9; i++){
        if(redScore[i] ==0){
            zerosRed++;
        }
    }

    if(zerosRed == 0){
        return redScore[8];
    }
    else{
        return 9-zerosRed;
    }

};

int QwintoScoreSheet::getYellowScore(){

    int zerosYellow = 0;

    for(int i = 0; i<9; i++){
        if(yellowScore[i] ==0){
            zerosYellow++;
        }
    }

    if(zerosYellow == 0){
        return yellowScore[8];
    }
    else{
        return 9-zerosYellow;
    }

};

int QwintoScoreSheet::getBlueScore(){
    int zerosBlue = 0;

    for(int i = 0; i<9; i++){
        if(blueScore[i] ==0){
            zerosBlue++;
        }
    }

    if(zerosBlue == 0){
        return blueScore[8];
    }
    else{
        return 9-zerosBlue;
    }

};


int QwintoScoreSheet::getOverallScore() {

    return getRedScore()+getYellowScore()+getBlueScore() + getNumFail()*5;

};

bool QwintoScoreSheet::score(RollOfDice &rd, Colour c, int pos) {

    RollOfDice* rollOfDice;

    switch(c){
        case Colour::RED:
            rollOfDice = redScore.scoreList;
            break;
        case Colour::YELLOW:
            rollOfDice = yellowScore.scoreList;
            break;
        case Colour::BLUE:
            rollOfDice = blueScore.scoreList;
            break;
    }

    if(int(rollOfDice[pos])!=0){
        std::cout<<"You gave an incorrect position value\n"
                "Error: already a value in that position "<<pos<<"\n";
        return false;
    }

    else if(pos<0 ||pos>8){
        std::cout<<"You gave an incorrect position value\n"
                "Error: the position you entered is greater than"
                "or less than the available positions"<<pos<<"\n";
        return false;
    }

    for(int i = 0; i<9; i++){
        if((int(rollOfDice[i]))<=int(rollOfDice)){
            
        }
    }

    rollOfDice[pos] = rd;
    return true;

}

//
// Created by Natesh Kukreja on 2017-11-29.
//

