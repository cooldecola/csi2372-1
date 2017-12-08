#include "QwintoPlayer.h"
#include "RollOfDice.h"

using namespace std;

void QwintoPlayer::inputBeforeRoll(RollOfDice *rd) {


    //create a flag for the while statement
    //will stop while statement when set to false
    bool flag = true;

    //create a vector full of the user input
    vector<string> userSelection;

    while(flag){
        //clear the vector storing the user selection
        userSelection.clear();

        //print statement to inform user to input
        std::cout<<"Which dice(s) would you like to use? \nPlease type 'r' for Red"
                ", 'y' for Yellow and 'b' for blue.\n When finished, please enter 'ok'";

        std::string userInput = "";

        //keep taking input until the userInput is equal to "ok"
        //code snippet same as lab 1
        while(userInput !="ok"){
            cin>>userInput;
            userSelection.push_back(userInput);
        }

        

    }


};

void QwintoPlayer::inputAfterRoll(RollOfDice *rollDice) {

    //input value and then print//

    inputBeforeRoll(rollDice);


    if(this->isCurrent){
        int pos;
        cout<<"How many positions would you like to fill";
        cin>>pos;
    }

}