#include <iostream>
#include "RollOfDice.h";

using namespace std;

class Player {
public:

    //helper variable to check if the user is current or not
    bool isCurrent = false;

    //name of the player
    std::string name="";

    //added constructor and getter methods - Natesh
    Player(std::string n):name(n){};

    //methods to be implemented in each individual method
    virtual void inputBeforeRoll(RollOfDice *rollDice)=0;
    virtual void inputAfterRoll(RollOfDice *rollDice)=0;

    //helper getter and setter for the current player
    //
    bool getIsCurrent(){return isCurrent;};
    void setCurrent(){isCurrent = true;};

    //helper
    std::string getName(){return name;};

};