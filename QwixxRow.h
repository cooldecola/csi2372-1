#include <iostream>

template <typename T, Colour c>

class QuixxRow(){
public:
  bool lockChecker; 
  RollOfDice scoreList[13];
  QwixxRow<T, C>& operator+= (RollOfDice rd);
  RollOfDice& operator[] (const int numColumn);
  ostream& operator<< (ostream& os);
};
