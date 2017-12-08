//
// Created by Natesh Kukreja on 2017-12-01.
//

#include "QwixxPlayer.h"

using namespace std;

void QwixxPlayer::inputBeforeRoll(RollOfDice *rollDice) {

    std::string dash = "-"*36;

    cout<<"Player name:" << name<<cout;
    cout<<dash<<endl;
    std::string red ="";
    std::string yellow ="";
    for(int i:qwixxScoreSheet.getRedList()){
        red = red+"| "+std::to_string(i);
    }
    cout<<"Red"<<red<<"U";
    for(int i:qwixxScoreSheet.getYellowList()){
        yellow = yellow+"| "+std::to_string(i);
    }
    cout<<"Yellow"<<yellow<<"U";

    std::list<int>::iterator it;
    it = blue.begin();
    std::string blue = "";
    while(it!=11){
        blue = blue+"| "+std::to_string(it);
        it++;
    }
    cout<<"Blue"<<it<<"U";

    it = green.begin();
    std::string green = "";
    while(it!=11){
        green = green+"| "+std::to_string(it);
        it++;
    }
    cout<<"Green"<<it<<"U";

};

void QwixxPlayer::inputAfterRoll(RollOfDice *rollDice) {

    //input value and then print//

    inputBeforeRoll(rollOfDice);


    if(this->isCurrent){
        int pos;
        cout<<"How many positions would you like to fill";
        cin>>pos;
    }

}
