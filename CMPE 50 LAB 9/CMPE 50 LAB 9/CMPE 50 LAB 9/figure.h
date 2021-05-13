//
//  figure.h
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//

#ifndef PROTECT_FIGURE_H_
#define PROTECT_FIGURE_H_

#include <iostream>
using namespace std;

class Figure {
public:
    //member functions
    virtual void erase();
    virtual void draw();
    virtual void center();
};

void Figure::erase() {
    cout << "Figure: erase(): Called erase function in the Figure class." << endl;
}

void Figure::draw() {
    cout << "Figure: draw(): Called draw function in the Figure class." << endl;
}

void Figure::center() {
    cout << "Figure: center(): Called center function in the Figure class." << endl;
    erase();
    draw();
}


#endif /* figure_h */
