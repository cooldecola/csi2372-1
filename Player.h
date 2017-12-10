#include <iostream>
#include "RollOfDice.h";

using namespace std;

class Player {
public:


    bool isCurrent = false;
    std::string name="";
    //added constructor and getter methods - Natesh
    Player(std::string n):name(n){};
    virtual void inputBeforeRoll(RollOfDice *rollDice)=0;
    virtual void inputAfterRoll(RollOfDice *rollDice)=0;
    bool getIsCurrent(){return isCurrent;};
    void setCurrent(){isCurrent = true;};
    std::string getName(){return name;};

};