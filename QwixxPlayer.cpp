#include <string>
#include <vector>
#include <algorithm>

template <typename T>
inline void makeChoice(T& choice, const std::string& prompt);

template <typename T>
inline void makeChoice(T& choice, const std::string& prompt){
  std::cout << prompt;
  std::cin >> choice;
}


QwixxPlayer::QwixxPlayer(std::string name, QwixxScoreSheet sheet){
  name = name;
  sheet = sheet;
}

void QwixxPlayer::inputBeforeRoll(RollOfDice &rollDice){
  int userChoice_whiteDice;
  std::string whitePrompt = "Would you like to use the white dice: ";
  makeChoice(userChoice_whiteDice, whitePrompt);
  while (userChoice_diceColour < 1 || userChoice_diceColour > 1){
    whitePrompt = "Wrong input, try again: ";
    makeChoice(userChoice_whiteDice, whitePrompt);
  }

  if (userChoice_whiteDice == 1){
    std::string userChoice_colourPlusWhite;
    std::string colourPlusWhitePrompt = "Which colour would you like to add it to?: "
    makeChoice(userChoice_colourPlusWhite, colourPlusWhitePrompt);
    while (userChoice_colourPlusWhite != "red" || userChoice_colourPlusWhite != "yellow" || userChoice_colourPlusWhite != "green" || userChoice_colourPlusWhite != "blue"){
      colourPlusWhitePrompt = "wrong input, try again: ";
      makeChoice(userChoice_whiteDice, whitePrompt);
      
    }

  }


  /*
  vector<std::string> all_selections;
  int userChoice_numOfDice;
  std::string dicePrompt = "How many Dices would you like to play with?: ";
  makeChoice(userChoice_numOfDice, dicePrompt);
  while (userChoice_numOfDice < 1 || userChoice_numOfDice > 3){
    dicePrompt = "Wrong input Please try again: "
    makeChoice(userChoice_numOfDice, dicePrompt);
  }

  for (int i = 0; i < userChoice_numOfDice; i++){
    std::string userChoice_diceColour;
    std::string colourPrompt = "What colour would you like for dice" << userChoice_numOfDice+1 << "?: ";
    makeChoice(userChoice_diceColour, colourPrompt);
    colour_selections.push_back(userChoice_diceColour);
  }

  for (int i = 0; i < userChoice_numOfDice; i++){


  }
  */
