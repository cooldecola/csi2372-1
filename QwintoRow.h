//
// Created by Natesh Kukreja on 2017-12-07.
//

#ifndef CPP_PROJECT_QWINTOROW_H
#define CPP_PROJECT_QWINTOROW_H
#include <iostream>
#include "Colour.h"
#include "RollOfDice.h"

using namespace std;

template <Colour T> class QwintoRow{

public:

    QwintoRow(){
        RollOfDice& operator[] (const int index);
        //ostream& operator<<(operator& os);
    }

};



#endif //CPP_PROJECT_QWINTOROW_H
