//
// Created by Natesh Kukreja on 2017-12-06.
//

#include "RollOfDice.h"

RollOfDice RollOfDice::pair(Dice dice_1, Dice dice_2) {

    //create an instance of RollOfDice to be returned
    RollOfDice rd;

    //add the pair of dices sent as arguments to
    //the back of the list to be returned
    rd.diceList.push_back(dice_1);
    rd.diceList.push_back(dice_2);

    return rd;
}

int RollOfDice::roll(){
    int roll = 0;

    //temperory iterator to go through the list of dices
    vector<Dice>::iterator iter;

    //1. Set iter equal to the first element in the list
    //2. Iterate until iter is equal to the last element (iterate
    //   though that as well)
    //3. Increment
    for(iter = diceList.begin(); iter!=diceList.end(); iter++){

        //create a temporary roll to store values
        Dice tempDice = *iter;
        //roll the dice and get a value to add to the result
        roll = tempDice.roll();
    }

    return roll;

}


int RandomDice(){

}

ostream& operator<<(ostream& os, RollOfDice& rollOfDice){


    //OK LETS BREAK THIS DOWN

    //WE FIRST GONNA CHECK IF THE COLOUR OF THE DICE AT THE INDEX
    //i IS EQUAL TO RED, IF SO, PRINT ALL THE FACES RED HAS ASSOCIATED
    //TO IT AND ITS USER

    //IF NOT THEN PRINT THE OTHER COLOURS!!!!

    //OK GOOD LETS DO THIS
    for(int i =0;i<diceList.size();i++){
        if(rollOfDice.diceList[i].colourOfDice == Colour::RED){
            os<<"Red Dices: "<<rollOfDice.diceList[i].faces<<endl;
        }
        if(rollOfDice.diceList[i].colourOfDice == Colour::YELLOW){
            os<<"Yellow Dices: "<<rollOfDice.diceList[i].faces<<endl;
        }
        if(rollOfDice.diceList[i].colourOfDice == Colour::BLUE){
            os<<"Blue Dices: "<<rollOfDice.diceList[i].faces<<endl;
        }

    }

    return os;


}

//conversion opertor that needs to be overwritten
RollOfDice::operator int(){
    int sum = 0;

    vector<Dice>::iterator iter;

    for(iter = diceList.begin(); iter!=diceList.end(); iter++){

        Dice tempDice = *iter;
        sum = sum+tempDice.faces;

    }
}

Dice::Dice(Colour colour) {

    //set the instance variable to the colour sent by the user
    colourOfDice = colour;
    //set faces as the value returned by RandomDice()
    faces = RandomDice();

}

int Dice::roll(){

    faces = RandomDice();
    return faces;

}

