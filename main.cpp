#include <iostream>
#include <string>
#include <vector>

#include "QwintoPlayer.h"
#include "QwintoRow.h"


template <typename T>
inline void makeChoice(T& choice, const std::string& prompt);

template <typename T>
inline void makeChoice(T& choice, const std::string& prompt){
    std::cout << prompt;
    std::cin >> choice;
}

void whoIsTheWinnerWinnerChickenDinner(vector<QwintoPlayer> listOfPlayers){

    string leGoat = "";

    int leGoatScore = 0; //if its zero then hes not the goat LOLOLOLOL
    //lol for real just a temp value for the actual score of the winnter

    //temp variable that changes
    int score = 0;

    //this does stuff
    for(int i = 0; i<listOfPlayers.size();i++){

        score = listOfPlayers[i].qwintoScoreSheet.setTotal();

        //print the 'i' players scoresheet
        listOfPlayers[i].qwintoScoreSheet;

        //simple switcheroo
        if(leGoatScore < score){

            leGoat = listOfPlayers[i].getName();

            leGoatScore = score;

        }

    }

    std::cout<<"THE GOAT AND THE WINNER OF THIS GAME IS *DRUM ROLL*\n "<<leGoat
             <<" AND THEY SCORED: "<<leGoatScore<< "WOOWOWOWOWOWOW";

    std::cout<<"game over, its yeezy time!";


}

void Qwinto(int numberOfPlayers){

    //create a list of QwintoPlayers that will be participating
    //playing the game
    vector<QwintoPlayer> listOfPlayers;

    //temporary variable for playing the game
    std::string player_Name;

    for(int i = 0; i<numberOfPlayers; i++){
        std::cout<<"Please enter player number " << i <<"'s name:";
        cin>>player_Name;
        listOfPlayers.push_back(QwintoPlayer(player_Name, QwintoScoreSheet(player_Name)));
    }

    //now we play the game

    //bool flag to check if the game is over
    bool isGameOver = false;

    //keep running while the game is NOT over
    while(!isGameOver){


        //iterate through the list of players
        vector<QwintoPlayer>::iterator iter;

        //ITERATION
        for(iter = listOfPlayers.begin(); iter<listOfPlayers.end(); iter++){

            //set the iter player to the current player
            iter->setCurrent();

            //just a print statement, nothing special
            std::cout<<iter->getName()<<"'s Turn";

            //instance variable
            RollOfDice rollOfDice;

            //get the input before the roll
            iter->inputBeforeRoll(&rollOfDice);

            //roll
            rollOfDice.roll();

            //print statement for the scoresheet
            iter->qwintoScoreSheet;

            //confirmation or whatever
            //some extra styling stuff
            std::cout<<iter->getName()<<", your roll is "<<int(rollOfDice)
                    <<" What is going to be your next step? "<<std::endl;

            //do the after roll steps
            iter->inputAfterRoll(&rollOfDice);

            //checks if the player is done the game
            //breaks the while loop if so
            if(iter->qwintoScoreSheet.checkIfGameOver()){
                isGameOver = true;
                std::cout<<"You lost the game!!!!!!! YOU COULD HAVE WON LOL";
                break;
            }


            for(iter = listOfPlayers.begin(); iter<listOfPlayers.end(); iter++){

                //this is for the non current players
                if(!iter->getIsCurrent()){
                    iter->qwintoScoreSheet;
                    iter->inputAfterRoll(&rollOfDice);

                    if(iter->qwintoScoreSheet.checkIfGameOver()){
                        isGameOver = true;
                        std::cout<<"You lost the game!!!!!!! YOU COULD HAVE WON LOL";
                        break;
                    }

                }

            }
            //iter player is no longer the current player
            iter->isCurrent =false;

        }

    }
    //helper function to get the winner
    whoIsTheWinnerWinnerChickenDinner(listOfPlayers);
}




int main() {

    int userChoice_version;
    int userChoice_players;

    std::string userChoice_name;

    std::string version_Prompt = "Welcome to the game Qwinto! There are two"
            " versions of the game. \nFor Qwinto press 1 and enter \nFor Qwixx press"
            " 2 and enter \nPlease enter your choice: ";
    makeChoice(userChoice_version, version_Prompt);
    while (userChoice_version < 1 || userChoice_version > 2){
        std::string version_Prompt = "\nPlease pick a number between 1 and 2: ";
        makeChoice(userChoice_version, version_Prompt);
    }
    std::cout << std::endl;
    std::cout << "You picked version " << userChoice_version << "!\n" << std::endl;

    bool qwinto;
    bool qwixx;

    //game selection for the if statements below
    if(userChoice_version == 1){
        qwixx = false;
        qwinto = true;
    }
    else if(userChoice_version == 1){
        qwixx = true;
        qwinto = false;
    }

    std::string numOfPlayers_Prompt = "Enter the number of players playing (1-3): ";
    makeChoice(userChoice_players, numOfPlayers_Prompt);
    while (userChoice_players < 1 || userChoice_players > 3){
        std::string numOfPlayers_Prompt = "Must be a valid number, between 1 and 3: ";
        makeChoice(userChoice_players, numOfPlayers_Prompt);
    }
    std::cout << std::endl;
    std::cout << "\nYou picked " << userChoice_players << " players\n";


    if(qwinto){
        Qwinto(userChoice_players);
    }

    else if(qwixx){

    }
}
