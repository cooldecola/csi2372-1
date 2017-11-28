#include <iostream>
using namespace std;

class Player {
public:
  bool isCurrent;
  std::string name;
  Player();
  Player(bool isCurrent, std::string name);
  //inputBeforeRoll(RollOfDice *rollDice)=0;
  //inputAfterRoll(RollOfDice *rollDice)=0;
};
