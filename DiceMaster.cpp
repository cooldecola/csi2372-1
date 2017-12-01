#include <iostream>
#include <random>
#include "Colour.h"

struct RandomDice{
  int Rand(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static uniform_int_distribution<> dis(1,6);
    return dis(gen);
  }
};

struct Dice;
ostream& operator<< (ostream&, const Dice&);

struct Dice{
  int face;
  //const Colour colour

  int roll(RandomDice& x){
    face = x.Rand();
    std::cout <<"in function: " << face << "\n";
    return face;
  }

  friend ostream& operator<< (ostream&, const Dice&);
};

ostream& operator<< (ostream& os, const Dice& d){
  os << "The face is " << d.face << " and the colour is ";
  return os;
}

struct RollOfDice{
  //Dice dice;
  std::vector<Dice> dice_List;

  void roll(RandomDice& x){
    for (int i = 0; i < dice_List.size(); i++){
      dice_List[i].roll(x);
      std::cout << dice_List[i];
    }
  }
/*
  RollOfDice pair (Dice a, Dice b){
    //IDK LOL
  }
*/

};


int main(){
  RandomDice r;
  std::cout << "\n";
  std::cout <<"in main: " <<  r.Rand();
  std::cout << "\n";
  Dice i;
  int temp = i.roll(r);
  std::cout << temp;
  std::cout << i;
  Dice a;
  Dice b;
  Dice c;

  system ("PAUSE");

}
