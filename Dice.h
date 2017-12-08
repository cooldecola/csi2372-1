#include <iostream>
#include "Colour.h"

struct Dice_{

private:
    Colour dColour;

    // number of faces that are on the dice, min/max is 6
    int faces;

    // the value that is showed when rolled
    int value;

    Dice(Colour colour);

    int roll();
public:
    int getFaces() {return faces;} //simple getter function
    int roll(RandomDice rd) // returns value that shows
    {
        value = rand() % faces + 1;
        return value;
    }
    Dice() : faces(6) {}; // default constructor for dice, only 6 sides to a dice
    Dice(int size) : faces(size) {}; // create a dice of given size
    int roll(RandomDice& x){
        faces = x.Rand();
        std::cout <<"in function: " << faces << "\n";
        return faces;
    }

    //friend ostream& operator<< (ostream&, const Dice&);
};

std::ostream& operator<< (std::ostream& os, const Dice& d);
