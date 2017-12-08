#include "Dice.h"
#include <iostream>;

using namespace std;

int Dice::roll(RandomDice random) {
    return 1;
}

ostream& operator<< (ostream& os, const Dice& d) {
    os << "The number on dice is: ";// << d.num << " and the colour is" << d.colour;
    return os;
}
