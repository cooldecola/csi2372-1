#include "QwintoPlayer.h"
#include "RollOfDice.h"

using namespace std;

void QwintoPlayer::inputBeforeRoll(RollOfDice *rd) {


    //create a flag for the while statement
    //will stop while statement when set to false
    bool flag = true;

    //create a vector full of the user input
    vector<std::string> userSelection;

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

        //create iterator to go through the user selection vector
        vector<std::string>::iterator iter;

        for(iter = userSelection.begin();iter!=userSelection.end();iter++){

            if(*iter =="r"){
                Dice tempDice = Dice(Colour::RED);
                rd->diceList.push_back(tempDice);
            }
            else if(*iter=="y"){
                Dice tempDice = Dice(Colour::YELLOW);
                rd->diceList.push_back(tempDice);
            }
            else if(*iter == "b"){
                Dice tempDice = Dice(Colour::BLUE);
                rd->diceList.push_back(tempDice);
            }

        }
        bool input;
        //iterate to print all the rolls to confirm
        for(iter = userSelection.begin(); iter!=userSelection.end(); iter++){

            //confirming the roll of the user
            //if confirmed, then flag = false;
            cout<<"You're rolling, "<< static_cast<std::string>(*iter);

            cout<<"Enter 0 to confirm your selection or 1 to redo\n";

            //take in input
            cin>>input;

        }
        //if 0, then flag is equal to false and while loop is finised
        //if 1, then the while loop will be done again
        flag = input;

    }

};

//
void QwintoPlayer::inputAfterRoll(RollOfDice *rollDice) {

    //create boolean references to check if the user has the following dice
    bool redFlag = false;
    bool yellowFlag = false;
    bool blueFlag = false;

    vector<Dice>::iterator diceIter;

    for(diceIter = rollDice->diceList.begin(); i!=rollDice->diceList.end(); diceIter++){
        Dice d = *diceIter;

        switch (d.colourOfDice){
            case Colour ::BLUE:
                blueFlag = true;
                break;
            case Colour ::YELLOW:
                yellowFlag = true;
                break;
            case Colour ::RED:
                redFlag = true;
                break;
        }

    }

    //user input for the answers they select
    std::string userInput="";

    //helper variable to check and see if the response they
    //entered is valid
    bool validResponse = false;

    //vector to store the user selection
    vector<std::string> userSelection;

    //vector iterator to see the inputs the user chose
    vector<std::string>::iterator iter;

    cout<<"What would you like to do?\n If you would like to enter a score, "
            "please enter a row color (i.e. 'r' for red) \n and column number"
            "(i.e. 9). If you cannot enter anywhere, \nenter 'fail' (only if "
            "you are the active player)."
            "Type in 'ok' when you are done.";


    //if the player is the current player they have to enter a value or
    //they will get a strike
    if(isCurrent){
        std::cout<<"Enter the Color and position number to enter your score\n"
                "if you cannot, enter 'skip' to be given a penalty.";
    }

    //if the player is not current, if they decide not to enter a score
        // no strike will be give to them
    else if (!isCurrent){
        std::cout<<"If you would like to enter a score, please enter a \n"
                "Colour and position. If you cannot, enter 'skip' and no penalty will be given";
    }

    while(!validResponse){

        while(userInput!="ok"){
            cin>>userInput;
            if(!isCurrent&& userInput == "skip"){
                validResponse = true;
            }


            //player is the current user, they cannot enter a value
            //failed throw is increased by one
            if(isCurrent && userInput == "skip"){
                qwintoScoreSheet.setNumFail();
                validResponse = true;
            }


            userSelection.push_back(userInput);
        }

        // the user response should be along the following lines
        // the size should be greater than or equal to 3
        // this means that the user has filled out the entire
        // COLOUR POSITION ACTION
        //i.e. RED 2 SKIP
        // process is to (TRUST THE PROCESS jk) iterate through the list, and
        // the value at [0] = RED, [1] = 2, [2] = SKIP
        // use the values as arguments and iteration tools



        if(userSelection.size()>=3){

            int x = static_cast<int>(userSelection[1]);

            if(userSelection[1] == Colour::RED && redFlag){
                if(qwintoScoreSheet.score(*rollDice, Colour::RED, x));
            }
        }

    }





}