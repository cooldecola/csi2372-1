#include <iostream> 
#include "ScoreSheet.h"

class QwixxScoreSheet : public ScoreSheet {
  QwixxRow<std::vector<RollOfDice>, red> RedRow;
  QwixxRow<std::vector<RollOfDice>, yellow> YellowRow;
  QwixxRow<std::list<RollOfDice>, blue> BlueRow;
  QwixxRow<std::list<RollOfDice>, green> GreenRow;

  bool score (RollOfDice &rd, Colour c, int position);
  int setTotal();
  int calcTotal();
  checkIfGameOver();

  ostream operator<< (ostream& os);
};
