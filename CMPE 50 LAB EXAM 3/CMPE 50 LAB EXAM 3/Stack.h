//
//  Stack.h
//  CMPE 50 LAB EXAM 3
//
//  Created by Blake Huynh on 11/23/20.
//

#ifndef Stack_H_
#define Stack_H_

#include<iostream>

using namespace std;

class Stack
{
private:
    int maxSize;

    int size;

    double* value;

public:
    Stack();

    Stack(int s);

    Stack(const Stack& obj);

    ~Stack();

    Stack& operator=(const Stack& obj);

    void addLast(double item);

    double getLast();

    double deleteLast();

    bool isEmpty();

    friend ostream& operator<<(ostream& os, const Stack& obj);

};


#endif // Stack_H_
