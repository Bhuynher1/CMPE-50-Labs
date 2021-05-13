//
//  Circle.h
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//

#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "figure.h"

using namespace std;

class Circle : public Figure {
public:
    void erase();
    void draw();
};

void Circle::erase() {
    cout << "Circle::erase(): Called erase function in the Circle class." << endl;
}

void Circle::draw() {
    cout << "Circle::draw(): Called erase function in the Circle class." << endl;
}

#endif /* Circle_h */
