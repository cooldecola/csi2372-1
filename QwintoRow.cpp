//
// Created by Natesh Kukreja on 2017-12-07.
//

#include "QwintoRow.h"

template<Colour T> ostream& QwintoRow<T>::operator<<(ostream &os){

    std::cout<<"Player Name: ";

    //creating variables to help the printing method
    //need dashes, XX for cannot enter val and $ for pentagon
    std::string dash = "-";

    std::string block = "|XX|";

    std::string percentSign = "%";

    std::string line = "|";

    //creating a string of dashes to seperate rows
    //created a for loop because I didn't want to type
    // '-' 30 some times lol
    for(int i = 0; i<31; i++){
        dash = dash+"-";
    }

    if(T==Colour::RED){
        std::cout<<dash<<"\n"<<"RED";

        //iterate through the list of scores in scoreList
        for(int  i =0; i<9; i++){

            //if the value isn't zero then there is a value
            //in thr row
            if(scoreList[i] !=0){

                //the assignment page has 4 bonus points
                //for the red row in score sheet
                //the positions are 1, 2, 4, 5
                //if the i == any of these values,
                //include a % sign before printing the value in the position
                if(i == 1 || i == 2 || i == 4 || i ==5) {
                    os << percentSign << scoreList[i] << " ";

                }
                    //no value should be entered at this position
                    //as it is blocked, therefore if i==3,
                    // print the block sign
                else if(i == 3){
                    os<<block<<" ";
                }

                //just a regular value
                else{
                    os<<line<<scoreList[i]<<line<<" ";
                }

            }

            // if there is no score associated with that position in the
            // list, then print the symbols
            if(scoreList[i] == 0){
                if(i == 1 || i == 2 || i == 5 || i ==5){
                    os<<percentSign<<" ";
                }

                else if(i == 3){
                    os<<block<<" ";
                }

                else if(i == 8){
                    os<<line<<" "<<line;
                }

                else{
                    os<<line<<scoreList[i]<<" ";
                }
            }
        }

    }

        //this is the same thing as the red row
        //but just for the yellow row
        //difference is the position of the percent and
        //the block signs
    else if(T ==Colour::YELLOW){
        std::cout<<dash<<"\n"<<"YELLOW";

        //iterate through the list of scores in scoreList
        for(int  i =0; i<9; i++){

            if(scoreList[i] !=0){

                if(i == 6 || i == 7){
                    os<<percentSign<<scoreList[i]<<" ";
                }

                else if(i == 5){
                    os<<block<<" ";
                }

                else{
                    os<<line<<scoreList[i]<<" ";
                }

            }

            // if there is no score associated with that position in the
            // list, then print the symbols
            if(scoreList[i] == 0){
                if(i == 6 || i == 7){
                    os<<percentSign<<" ";
                }

                else if(i == 5){
                    os<<block<<" ";
                }
                else{
                    os<<line<<scoreList[i]<<" ";
                }
            }
        }

    }

        //this is the same thing as the red row
        //but just for the blue row
        //difference is the position of the percent and
        //the block signs
    else if(T ==Colour::BLUE){

        std::cout<<dash<<"\n"<<"BLUE";

        //iterate through the list of scores in scoreList
        for(int  i =0; i<9; i++){

            if(scoreList[i] !=0){

                if(i == 2 || i == 3){
                    os<<percentSign<<" ";
                }

                else if(i == 4){
                    os<<block<<" ";
                }
                else{
                    os<<line<<scoreList[i]<<" ";
                }

            }

            // if there is no score associated with that position in the
            // list, then print the symbols
            if(scoreList[i] == 0){
                if(i == 2 || i == 3){
                    os<<percentSign<<" ";
                }

                else if(i == 4){
                    os<<block<<" ";
                }
                else{
                    os<<line<<scoreList[i]<<" ";
                }
            }
        }

    }

    //return everything that has been added to the
    //output stream
    return os;
}

