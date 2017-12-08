//
// Created by Natesh Kukreja on 2017-11-29.
//

#include "QwintoScoreSheet.h"

int QwintoScoreSheet::setTotal(Colour c, int val, int pos) {

    return 0;

};

bool QwintoScoreSheet::isGameOver(){

    if(ScoreSheet::getFailed()){
        return true;
    }
    return false;

};

bool QwintoScoreSheet::calcTotal(Colour c, int val, int pos) {

};

void QwintoScoreSheet::getRedScore(){
    int zeros = 0;

    for(int i = 2; i<12; i++){

        if(i == 5){}
        else if(score_Red[i] == 0){
            zeros++;
        }
    }
    if(zeros == 0){
        overallScore = overallScore+score_Red[11];
        zeros = 0;
    }
    else{
        overallScore = overallScore + (12-zeros);
        zeros = 0;
    }
    if(score_Red[3]!=0&&score_Yellow[3]!=0&&score_Blue[3]!=0){
        int max = score_Red[3];
        if(score_Red[3]<score_Blue[3]){
            max = score_Blue[3];
            if(score_Blue[3]<score_Yellow[3]){
                max = score_Yellow[3];
            }
        }
        else if(score_Red[3]<score_Yellow[3]){
            max = score_Yellow[3];
        }
        overallScore = max+overallScore;
    }
    if(score_Red[7]!=0&&score_Yellow[7]!=0&&score_Blue[7]!=0){
        int max = score_Red[7];
        if(score_Red[7]<score_Blue[7]){
            max = score_Blue[7];
            if(score_Blue[7]<score_Yellow[7]){
                max = score_Yellow[7];
            }
        }
        else if(score_Red[7]<score_Yellow[7]){
            max = score_Yellow[7];
        }
        overallScore = max+overallScore;
    }
};

void QwintoScoreSheet::getYellowScore(){
    int zeros = 0;
    for(int i = 1; i<11; i++){
        if(i == 6){}
        else if(score_Yellow[i] == 0){
            zeros++;
        }
    }
    if(zeros == 0){
        overallScore = overallScore+score_Yellow[10];
        zeros = 0;
    }
    else{
        overallScore = overallScore + (12-zeros);
        zeros = 0;
    }
    if(score_Red[8]!=0&&score_Yellow[8]!=0&&score_Blue[8]!=0){
        int max = score_Red[8];
        if(score_Red[8]<score_Blue[8]){
            max = score_Blue[8];
            if(score_Blue[8]<score_Yellow[8]){
                max = score_Yellow[8];
            }
        }
        else if(score_Red[8]<score_Yellow[8]){
            max = score_Yellow[8];
        }
        overallScore = max+overallScore;
    }
};

void QwintoScoreSheet::getBlueScore(){
    int zeros = 0;
    for(int i = 0; i<10; i++){
        if(i == 4){}
        else if(score_Blue[i] == 0) {
            zeros++;
        }
    }
    if(zeros == 0){
        overallScore = overallScore+score_Blue[9];
        zeros = 0;
    }
    else{
        overallScore = overallScore + (12-zeros);
        zeros = 0;
    }

    if(score_Red[2]!=0&&score_Yellow[2]!=0&&score_Blue[2]!=0){
        int max = score_Red[2];
        if(score_Red[2]<score_Blue[2]){
            max = score_Blue[2];
            if(score_Blue[2]<score_Yellow[2]){
                max = score_Yellow[2];
            }
        }
        else if(score_Red[2]<score_Yellow[2]){
            max = score_Yellow[2];
        }
        overallScore = max+overallScore;
    }

    if(score_Red[9]!=0&&score_Yellow[9]!=0&&score_Blue[9]!=0){
        int max = score_Red[9];
        if(score_Red[9]<score_Blue[9]){
            max = score_Blue[9];
            if(score_Blue[9]<score_Yellow[9]){
                max = score_Yellow[9];
            }
        }
        else if(score_Red[9]<score_Yellow[9]){
            max = score_Yellow[9];
        }
        overallScore = max+overallScore;
    }

};

int QwintoScoreSheet::getOverallScore() {

    getRedScore();
    getYellowScore();
    getBlueScore();

    return overallScore + num_Failed*5;

};

//
// Created by Natesh Kukreja on 2017-11-29.
//

