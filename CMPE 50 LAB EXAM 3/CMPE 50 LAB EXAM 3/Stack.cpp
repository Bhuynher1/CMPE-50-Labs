//
//  Stack.cpp
//  CMPE 50 LAB EXAM 3
//
//  Created by Blake Huynh on 11/23/20.
//

#include"Stack.h"
#include<iostream>

using namespace std;

//default constructor
Stack::Stack()
{
    maxSize = 10;
    value = new double[maxSize];
    size = 0;
}

//parameterized constructor
Stack::Stack(int s)
{
    maxSize = s;
    value = new double[maxSize];
    size = 0;
}

//copy constructor
Stack::Stack(const Stack& obj)
{
    maxSize = obj.maxSize;
    value = new double[maxSize];
    size = obj.size;
    for (int i = 0; i < size; i++)
    {
        value[i] = obj.value[i];
    }
}

//destructor
Stack::~Stack()
{
    delete value;
}

// = operator overloading
Stack& Stack::operator=(const Stack& obj)
{
    maxSize = obj.maxSize;
    value = new double[maxSize];
    size = obj.size;
    for (int i = 0; i < size; i++)
    {
        value[i] = obj.value[i];
    }

    return *this;
}

//add an item to the list
void Stack::addLast(double item)
{
    if (size == maxSize)
    {
        maxSize = 2 * maxSize;
        double* temp = new double[maxSize];
        for (int i = 0; i < size; i++)
            temp[i] = value[i];

        value = temp;
    }
    value[size] = item;
    size++;
}

//return the last item
double Stack::getLast()
{
    if (!isEmpty())
        return value[size - 1];
    else
        return -1;
}

//delete the last item
double Stack::deleteLast()
{
    if (!isEmpty())
        return value[--size];
    else
        return -1;
}

//check empty or not
bool Stack::isEmpty()
{
    return size == 0;
}

// insertion operator overloading
ostream& operator<<(ostream& os, const Stack& obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        os << obj.value[i] << " ";
    }
    os << endl;
    return os;
}

