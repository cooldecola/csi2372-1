#include <iostream>

class QwixxPlayer : public Player {
  QwixxScoreSheet scoresheet;
  QwixxPlayer(std::string name, QwixxScoreSheet sheet);
  void inputBeforeRoll(RollOfDice &rollDice);
  void inputAfterRoll (RollOfDice &rollDice);
};
