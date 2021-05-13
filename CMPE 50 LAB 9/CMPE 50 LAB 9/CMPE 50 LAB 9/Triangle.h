//
//  Triangle.h
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//

#ifndef Triangle_h_
#define Triangle_h_

#include <iostream>
#include "figure.h"
using namespace std;

class Triangle : public Figure {
public:
    void draw();
    void erase();
};

void Triangle::draw() {
    cout << "Triangle::draw(): Called draw method in the Triangle class." << endl;
}

void Triangle::erase() {
    cout << "Triangle::erase(): Called erase method in the Triangle class." << endl;
}

#endif /* Triangle_h */
