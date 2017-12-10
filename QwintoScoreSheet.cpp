//
// Created by Natesh Kukreja on 2017-11-29.
//

#include "QwintoScoreSheet.h"

//yeezy just jumped over jumpman - Kanye West

ostream& QwintoScoreSheet::operator<<(ostream& os){

    //creating a string of dashes so I dont have to
    // type out 30 some dashes lol
    std::string dash = "-";

    //DASHES STRING!!!!!!
    for(int i = 0; i <31;i++){
        dash = dash+"-";
    }

    //to make it nice :)
    os<<dash;

    //adding all the scores to the output stream
    //to be printed
    redScore<<os;
    yellowScore<<os;
    blueScore<<os;

    //lol add the dashes to the stream too
    os<<"\n"<<dash;


    //print out the number of failed throws for the player
    //if the number of failed throws is >0 then it prints out
    // the number of fails. Otherwise nothing
    if(getNumFail()>0){
        os<<"\n Failed Throws: ";
        for(int i=0; i<getNumFail(); i++){
            os<< " "<<i<<" ";
        }
    }


    //new line to the stream
    os<<"\n";

    //print this out
    return os;

}

bool QwintoScoreSheet::operator!(){

    //return if the game is still active
    return checkIfGameOver();
}

bool QwintoScoreSheet::checkIfGameOver() {

    //count the amount of times each color has a zero in
    //their row. If two of them have 0, then the game is over
    int counterR = 0;
    int counterY = 0;
    int counterB = 0;

    //for loop for all the colors
    for(int i= 0; i<9; i++){
        if(redScore[i] == 0){
            counterR++;
        }
    }
    for(int i= 0; i<9; i++){
        if(yellowScore[i] == 0){
            counterY++;
        }
    }
    for(int i= 0; i<9; i++){
        if(blueScore[i] == 0){
            counterB++;
        }
    }

    //if the number of number of failed attempts by the user is 4
    //or if the user has two filled row, then end the game
    if((getNumFail() == 4)||((counterB==0 &&counterR==0)||(counterB==0 &&counterY==0)||(counterB==0 &&counterR==0))){
        return true;
    }
        //return false as the game is still being played
    else{return false;}

};

//helper method to get the score of the red row
int QwintoScoreSheet::getRedScore(){

    int zerosRed = 0;

    //calculate the zeros, if none, then the score is the
    //highest value in the array
    for(int i = 0; i<9; i++){
        if(redScore[i] ==0){
            zerosRed++;
        }
    }

    //return the highest value in the row if zeros == 0
    if(zerosRed == 0){
        return redScore[8];
    }
    else{
        //return 9 minus the number of zeros in the row
        return 9-zerosRed;
    }

};


//helper method to get the score of the yellow row
//same principle as the red row
int QwintoScoreSheet::getYellowScore(){

    int zerosYellow = 0;

    for(int i = 0; i<9; i++){
        if(yellowScore[i] ==0){
            zerosYellow++;
        }
    }

    if(zerosYellow == 0){
        return yellowScore[8];
    }
    else{
        return 9-zerosYellow;
    }

};

//helper method to get the score of the yellow row
//same principle as the red row
int QwintoScoreSheet::getBlueScore(){
    int zerosBlue = 0;

    for(int i = 0; i<9; i++){
        if(blueScore[i] ==0){
            zerosBlue++;
        }
    }

    if(zerosBlue == 0){
        return blueScore[8];
    }
    else{
        return 9-zerosBlue;
    }

};


int QwintoScoreSheet::getOverallScore() {

    //calculating the pentagon values
    //if the column is full, then return the value
    //in the pentagon the color is associated with
    //i.e., return redScore[1], redScore[5], yellowScore[7]
    // blueScore[2] and blueScore[9]

    //first red pentagon
    if((redScore[1]!=0)&&(yellowScore[2]!=0)&&(blueScore[3]!=0)){
        overallScore+=redScore[1];
    }

    //second red pentagon
    if((redScore[5]!=0)&&(yellowScore[6]!=0)&&(blueScore[7]!=0)){
        overallScore+=redScore[5];
    }

    //first yellow pentagon
    if((redScore[6]!=0)&&(yellowScore[7]!=0)&&(blueScore[8]!=0)){
        overallScore+=yellowScore[7];
    }

    //first blue pentagon
    if((redScore[0]!=0)&&(yellowScore[1]!=0)&&(blueScore[2]!=0)){
        overallScore+=blueScore[0];
    }

    //second blue pentagon
    if((redScore[7]!=0)&&(yellowScore[8]!=0)&&(blueScore[9]!=0)) {
        overallScore += redScore[1];
    }

    //get the values of each individual row and add them
    //subtract by the number of failed attempts
    overallScore+=getRedScore()+getYellowScore()+getBlueScore() - getNumFail()*(5);

    return overallScore;

};

bool QwintoScoreSheet::score(RollOfDice &rd, Colour c, int pos) {

    //create a temporary instance of RollOfDice to
    //use to check if the values can be added
    RollOfDice* rollOfDice;

    //depending on which color has been sent through
    //need to set the temporary instance of RollOfDice to
    //the appropriate row
    switch(c){
        case Colour::RED:
            rollOfDice = redScore.scoreList;
            break;
        case Colour::YELLOW:
            rollOfDice = yellowScore.scoreList;
            break;
        case Colour::BLUE:
            rollOfDice = blueScore.scoreList;
            break;
    }

    //the position provided by the user already has a value in it
    if(int(rollOfDice[pos])!=0){
        std::cout<<"You gave an incorrect position value\n"
                "Error: already a value in that position "<<pos<<"\n";
        return false;
    }

        //the position provided by the user is greater than or
        //less than the size of the row
    else if(pos<0 ||pos>8){
        std::cout<<"You gave an incorrect position value\n"
                "Error: the position you entered is greater than"
                "or less than the available positions"<<pos<<"\n";
        return false;
    }


    //iterating through the list of the dice to ensure that
    //the position the user entered is valid for entry
    //if not, then the method will return false and the
    // program will end
    //the limit is 'pos' because the value will not go behind
    // the given value. Also we know the values before are greater,
    // because at one point the highest position was given to input
    for(int i = 0; i<pos; i++){
        if(rollOfDice[i]!=0 &&((int(rollOfDice[i]))<=int(rd))){
            std::cout<<"You gave an incorrect position value\n"
                    "Error: the value you entered is less than"
                    "the values before the position"<<pos<< " "<<rd;
            return false;
        }
    }

    //everything above holds up, and the user entered position can
    //be used and the value is stored at that position in the list
    rollOfDice[pos] = rd;
    return true;

}

//
// Created by Natesh Kukreja on 2017-11-29.
//