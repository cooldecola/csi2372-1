//
// Created by Natesh Kukreja on 2017-12-06.
//

#ifndef CPP_PROJECT_ROLLOFDICE_H
#define CPP_PROJECT_ROLLOFDICE_H

#include "vector";
#include "Dice.h";

using namespace std;

struct RollOfDice {

    //need to store the dice vales
    vector<Dice> diceList;

    //function to roll dice, returns value
    int roll();

    //returns a pair of
    static RollOfDice pair(Dice dice_1, Dice dice_2);

    //overloading operator
    operator int();

    //initial value of the dice
    static int value = 1;

    //print operator
    friend ostream& operator<< (ostream& os, const RollOfDice& rd);

};

struct Dice{

    Colour colourOfDice;

    // number of faces that are on the dice, min/max is 6
    int faces;


    //initializer with the color of the object
    Dice(Colour colour);

    //function to be implemented
    int roll();


};

struct RandomDice{
    //static instance variable
    static int value=1;
};


#endif //CPP_PROJECT_ROLLOFDICE_H
