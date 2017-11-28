#include "Dice.h"

Dice::roll (RandomDice random) {
  cout << random;
}

ostream& operator<< (ostream& os, const Dice& d) {
  os << "The number on dice is: " << d.num << " and the colour is" << d.colour;
  return os;
}
