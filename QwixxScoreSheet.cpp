//
// Created by Natesh Kukreja on 2017-11-30.
//

#include "QwixxScoreSheet.h"

int QwixxScoreSheet::getOverallScore() {

    getBlueScore();
    getRedScore();
    getYellowScore();
    getGreenScore();
    return overallScore-(num_Failed*5);
};

void QwixxScoreSheet::getBlueScore(){
    for (int i : blue){
        if(i!=0){
            overallScore+overallScore+(i+1);
        }
    }
}
void QwixxScoreSheet::getRedScore(){
    for (int i : red){
        if(i!=0){
            overallScore+overallScore+(i+1);
        }
    }
}
void QwixxScoreSheet::getYellowScore(){
    for (int i : yellow){
        if(i!=0){
            overallScore+overallScore+(i+1);
        }
    }
}
void QwixxScoreSheet::getGreenScore(){
    for (int i : green){
        if(i!=0){
            overallScore+overallScore+(i+1);
        }
    }
}

bool QwixxScoreSheet::calcTotal(Color c, int val, int pos) {
    if(c == 'r'){
        if(val<redMax){
            return false;
        }
        else if(redMax == 0 || val>redMax){
            redMax = val;
            return true;
        }
    }
    else if(c == 'b'){
        if(val<blueMax){
            return false;
        }
        else if(blueMax == 0 || val>blueMax){
            blueMax = val;
            return true;
        }
    }
    else if(c == 'y'){
        if(val<yellowMax){
            return false;
        }
        else if(yellowMax == 0 || val>yellowMax){
            yellowMax = val;
            return true;
        }
    }
    else if(c == 'g'){
        if(val<greenMax){
            return false;
        }
        else if(greenMax == 0 || val>greenMax){
            greenMax = val;
            return true;
        }
    }
};

void QwixxScoreSheet::setTotal(Color c, int val, int pos){

    if(calcTotal(Color c, int val, int pos)){
        if(c == 'r'){
            red.at(pos) = val;
        }
        else if(c == 'y'){
            yellow.at(pos) = val;
        }
        else if(c == 'b'){
            it = blue.begin();
            int i =0;
            while(i!=pos){
                it++;
                i++;
            }
            blue.insert(it, val);
            it = blue.begin();
        }
        else if(c == 'g'){
            it = green.begin();
            int i =0;
            while(i!=pos){
                it++;
                i++;
            }
            green.insert(it, val);
            it = green.begin();
        }
    }
};
