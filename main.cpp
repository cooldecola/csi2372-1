#include <iostream>
#include <string>
#include <vector>

#include "QwintoPlayer.h"
#include "QwintoRow.h"


template <typename T>
inline void makeChoice(T& choice, const std::string& prompt);

// A TEMPLATE TO GET USER INPUT FOR DIFFERENT SITUATIONS
template <typename T>
inline void makeChoice(T& choice, const std::string& prompt){
    std::std::cout << prompt;
    std::cin >> choice;
}

//WINNER method that finds the winner of the game
//esskeetit !!
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

            //the GOAT becomes the [i] position of list of players
            leGoat = listOfPlayers[i].getName();

            leGoatScore = score;

        }

    }

    std::std::cout<<"THE GOAT AND THE WINNER OF THIS GAME IS *DRUM ROLL*\n "<<leGoat
             <<" AND THEY SCORED: "<<leGoatScore<< "WOOWOWOWOWOWOW";

    std::std::cout<<"game over, its yeezy time!";


}


//the game method for qwinto
//the game is played here after finding out how many
//people are playing the game and what game is being
//played in the main method
void Qwinto(int numPlayers_Qwixx){

    //create a list of QwintoPlayers that will be participating
    //playing the game
    vector<QwintoPlayer> listOfPlayers;

    //temporary variable for playing the game
    std::string player_Name;

    for(int i = 0; i<numPlayers_Qwixx; i++){
        std::std::cout<<"Please enter player number " << i <<"'s name:";
        cin>>player_Name;
        listOfPlayers.push_back(QwintoPlayer(player_Name, QwintoScoreSheet(player_Name)));
    }

    //now we play the game ----- esskeetit

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
            std::std::cout<<iter->getName()<<"'s Turn";

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
            std::std::cout<<iter->getName()<<", your roll is "<<int(rollOfDice)
                    <<" What is going to be your next step? "<<std::endl;

            //do the after roll steps
            iter->inputAfterRoll(&rollOfDice);

            //checks if the player is done the game
            //breaks the while loop if so
            if(iter->qwintoScoreSheet.checkIfGameOver()){
                isGameOver = true;
                std::std::cout<<"You lost the game!!!!!!! YOU COULD HAVE WON LOL";
                break;
            }


            for(iter = listOfPlayers.begin(); iter<listOfPlayers.end(); iter++){

                //this is for the non current players
                if(!iter->getIsCurrent()){
                    iter->qwintoScoreSheet;
                    iter->inputAfterRoll(&rollOfDice);

                    if(iter->qwintoScoreSheet.checkIfGameOver()){
                        isGameOver = true;
                        std::std::cout<<"You lost the game!!!!!!! YOU COULD HAVE WON LOL";
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







void playQwixx(int numPlayers_Qwixx){

  vector <QwixxPlayer> players; // Creating the vector of players
  vector <Colour> colourList; // Creating the vector of different colours
  colourList.push_back(red);
  colourList.push_back(yellow);
  colourList.push_back(green);
  colourList.push_back(blue); // initializing all the objects in the vector as different colours
  bool gameEnd = false;

  // A LOOP TO ADD PLAYERS INTO PLAYERS VECTOR
  for (int i = 0; i < numPlayers_Qwixx; i++){
    std::string playerName_Prompt = "\nPlease enter the name of player " + std::to_string(i+1) + ": ";
    makeChoice(userChoice_name, playerName_Prompt);
    players.push_back(QwixxPlayer(userChoice_name, QwixxScoreSheet(userChoice_name)));
  }

  // LOOP that runs while game end conditions havent been met
	while(!gameTerminator){
    RollOfDice rd; // creates roll of dice object for game
		vector<QwixxPlayer>::iterator Playercurrent; //Looping over the players


		for(Playercurrent = players.begin(); Playercurrent < players.end(); Playercurrent++){
			Playercurrent->isCurrent = true; // next player takes a turn i.e., becomes active
      std::std::cout << "Its your turn, " << Playercurrent -> name;
      RollOfDice rd; // creates roll of dice object for players

      // loops ofer the colour container to create game_dice for all colours (except white)
      for(int i = 0; i < colourList.size(); i++){
        rd.game_dice.push_back(Dice(colourList[i]));
      }

      // creating the two white dice
			rd.game_dice.push_back(Dice(Color::white));
			rd.game_dice.push_back(Dice(Color::white));

			RollOfDice whiteDice = RollOfDice::pair(rd.game_dice[0], rd.game_dice[1]);

			rd.roll();

      std::std::cout << "The Dices are Rolling... \n\n\n";
      std::std::cout << rd;
      std::std::cout << "The First White Dice is: " << rd.game_dice[0].face << " and the second white dice is: " << rd.game_dice[0].face << endl;
      std::std::cout << "The sum of the white dices are: " << int(whiteDice) << endl;

			for(vector<QwixxPlayer>::iterator i = players.begin(); i != players.end(); i++){
					std::cout<< i->scoreSheet <<endl; // the scoresheet is displayed
					i->inputBeforeRoll(whiteDice); //each player gives their input according to the game rules.

					// To check if the scoresheet is locked, it goes to the last entry to check if L or the equivelance of '0' is there
          // For the red row
					if(int(i->scoreSheet.redRow[11])!=0){
						if ( find(colourList.begin(), colourList.end(), red) != colourList.end() ){
							colourList.erase(remove(colourList.begin(), colourList.end(), red), colourList.end());
							std::cout << "The red dice is removed from the game" << endl;

						}
					}

          //for the yellow row
					if(int(i->scoreSheet.yellowRow[11])!=0){
						if ( find(colourList.begin(), colourList.end(), yellow) != colourList.end() ){
							colourList.erase(remove(colourList.begin(), colourList.end(), yellow), colourList.end());
							std::cout << "The yellow dice is removed from the game" << endl;
						}
					}

          //for green row
					if(int(i->scoreSheet.greenRow[11])!=0){
						if ( find(colourList.begin(), colourList.end(), green) != colourList.end() ){
							colourList.erase(remove(colourList.begin(), colourList.end(), green), colourList.end());
							std::cout << "The green dice is removed from the game" << endl;
						}
					}

          //for the blue row
					if(int(i->scoreSheet.blueRow[11])!=0){
						if ( find(colourList.begin(), colourList.end(), blue) != colourList.end() ){
							colourList.erase(remove(colourList.begin(), colourList.end(), blue), colourList.end());
							std::cout << "The blue dice is removed from the game" << endl;
						}
					}
			}

      std::cout << "Please choose a white dice (1 or 2) and a coloured dice" << endl;
      std::cout << Playercurrent -> scoreSheet << rd;
      Playercurrent -> inputAfterRoll(rd);

			if(int(Playercurrent->scoreSheet.redRow[11])!=0){
				if ( find(colourList.begin(), colourList.end(), red) != colourList.end() ){
					colourList.erase(remove(colourList.begin(), colourList.end(), red), colourList.end());
					std::cout << "The red dice is removed from the game" << endl;

				}
			}
			if(int(Playercurrent->scoreSheet.yellowRow[11])!=0){
				if ( find(colourList.begin(), colourList.end(), yellow) != colourList.end() ){
					colourList.erase(remove(colourList.begin(), colourList.end(), yellow), colourList.end());
					std::cout << "The yellow dice is removed from the game" << endl;
				}
			}
			if(int(Playercurrent->scoreSheet.greenRow[11])!=0){
				if ( find(colourList.begin(), colourList.end(), green) != colourList.end() ){
					colourList.erase(remove(colourList.begin(), colourList.end(), green), colourList.end());
					std::cout << "The green dice is removed from the game" << endl;
				}
			}
			if(int(Playercurrent->scoreSheet.blueRow[11])!=0){
				if ( find(colourList.begin(), colourList.end(), blue) != colourList.end() ){
					colourList.erase(remove(colourList.begin(), colourList.end(), blue), colourList.end());
					std::cout << "The blue dice is removed from the game" << endl;
				}
			}

			if(!Playercurrent->scoreSheet){ // End condition met by active player
				std::cout << "The red dice is removed from the game" << endl;
				gameTerminator = true;
				break;
			}

			vector<QwixxPlayer>::iterator inPlayercurrent;
			for(inPlayercurrent = players.begin(); inPlayercurrent<players.end(); inPlayercurrent++){
				if(!inPlayercurrent -> isCurrent){
					if(!inPlayercurrent->scoreSheet){
						std::cout << "ITS GAME OVER" << endl;
						gameTerminator = true;
					}
				}
			}
			Playercurrent->isCurrent = false; // remove the current player flag from the player
		}
	}
	/*
		GAME IS OVER
	*/
  int winnerScore = 0; // random temp number
	QwixxPlayer winner_player = players[0]; // placeholder value
	string winnerName = winner.name; // placeholder value
	int score = winnerScore; // placeholder value

	for(int i = 0; i <numPlayers_Qwixx; ++i){
		score = players[i].scoreSheet.setTotal(); // Calculate score for each player
		std::cout << players[i].scoreSheet; // Show score sheet for each player
		if(winnerScore < score){
			winnerScore = score;
			winner_player = players[i];
			winnerName = players[i].name;
		}
	}
	// Announce winner.
	std::cout << winnerName << " You won the Game!!! Your score was: " << winnerScore << endl;
	return;
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
    std::std::cout << std::endl;
    std::std::cout << "You picked version " << userChoice_version << "!\n" << std::endl;

    //basically if the value is 1 then qwinto is being played
    //if 0 then qwixx
    //int 0 correlates to False and 1 to True in C++
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

    //get the input from the user to see how many people want to play
    //this game!!!
    std::string numOfPlayers_Prompt = "Enter the number of players playing (1-3): ";
    makeChoice(userChoice_players, numOfPlayers_Prompt);
    while (userChoice_players < 1 || userChoice_players > 3){
        std::string numOfPlayers_Prompt = "Must be a valid number, between 1 and 3: ";
        makeChoice(userChoice_players, numOfPlayers_Prompt);
    }
    std::std::cout << std::endl;
    std::std::cout << "\nYou picked " << userChoice_players << " players\n";


    if(qwinto){
        Qwinto(userChoice_players);
    }

    else if(qwixx){
      Qwixx(userChoice_players);

    }
}
