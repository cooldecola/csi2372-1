#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

template <typename T>
inline void makeChoice(T& choice, const std::string& prompt);

template <typename T>
inline void makeChoice(T& choice, const std::string& prompt){
  std::cout << prompt;
  std::cin >> choice;
}


int main() {

  int userChoice_version;
  int userChoice_players;
  std::string nom = "usie";
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

  std::string numOfPlayers_Prompt = "Enter the number of players playing (1-3): ";
  makeChoice(userChoice_players, numOfPlayers_Prompt);
  while (userChoice_players < 1 || userChoice_players > 3){
    std::string numOfPlayers_Prompt = "Must be a valid number, between 1 and 3: ";
    makeChoice(userChoice_players, numOfPlayers_Prompt);
  }
  std::cout << std::endl;
  std::cout << "\nYou picked " << userChoice_players << " players\n";

  std::vector<Player> player_List;
  for (int i = 0; i < userChoice_players; i++) {
    std::string playerName_Prompt = "\nPlease enter the name of player " + std::to_string(i+1) + ": ";
    makeChoice(userChoice_name, playerName_Prompt);
    player_List.push_back(Player(false, userChoice_name));
  }
  system ("PAUSE");
}
