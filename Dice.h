#include <iostream>
#include "Colour.h"
#include "RandomDice.h"
struct Dice {
  int num;
  const Colour colour;
  RandomDice random;

  int roll (RandomDice);
  friend std::ostream& operator<< (std::ostream&, const Dice&);
};

std::ostream& operator<< (std::ostream& os, const Dice& d);
