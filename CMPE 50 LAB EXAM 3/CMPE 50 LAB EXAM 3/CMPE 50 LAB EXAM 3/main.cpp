#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Stack.h"
using namespace std;

//Function Declarations
void reverse();
void reverseString(char*);
void stacks();

int main()
{
    //Declaring variables
    int choice;

    while (true) {
        cout << "\n1.Reverse String" << endl;
        cout << "2.Stacks" << endl;
        cout << "3.Exit" << endl;

        //getting the choice entered by the user
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            reverse();

            continue;
        }
        case 2: {
            stacks();
            continue;
        }
        case 3: {
            cout << "Exiting Program..." << endl;
            system("pause");
            exit(1);
        }
        default: {
            cout << "There is an error in the choice selection" << endl;
            continue;
        }
        }
        break;
    }

    return 0;
}

//Functions for reversing string input from user
void reverse()
{
    const int size = 150;
    char charArray[size];

    cout << "Please enter in the string that you want to reverse "
        << "without spaces or line breaks.\n";
    cout << "Reverse Input: ";
    cin >> charArray;
    charArray[size - 1] = '\0';
    cout << "Your input was: " << charArray << endl;
    reverseString(charArray);
    cout << "The reversed stirng of your input is:\n" << charArray << endl;
}
void reverseString(char* str) {
    char* front, * rear;
    char temp;
    front = str;
    rear = str + strlen(str) - 1;
    while (front < rear) {
        temp = *front;
        *front = *rear;
        *rear = temp;
        front++;
        rear--;
    }
}

//Function for the Stack Exercise
void stacks() {
    Stack stk1;

    //add values from 1 to 20
    for (int i = 1; i <= 20; i++)
        stk1.addLast(i);

    cout << "First Stack: " << stk1 << endl;

    //create object with copy constructor
    Stack stk2(stk1);

    //create object with default constructor
    Stack stk3;
    cout << "Second stack: " << stk2 << endl;

    while (!stk2.isEmpty())
    {
        double item = stk2.deleteLast();
        stk3.addLast(item);
    }

    stk1 = stk3;

    //print stacks in reverse order
    cout << "First stack part 2: " << stk1 << endl;
    cout << "Third stack: " << stk3 << endl;
}

//Outputs for Lab exam question 2:
/*
1.Reverse String
2.Stacks
3.Exit
Enter Choice: 1
Please enter in the string that you want to reverse without spaces or line breaks.
Reverse Input: 123456789
Your input was: 123456789
The reversed stirng of your input is:
987654321

1.Reverse String
2.Stacks
3.Exit
Enter Choice: 1
Please enter in the string that you want to reverse without spaces or line breaks.
Reverse Input: Saturday
Your input was: Saturday
The reversed stirng of your input is:
yadrutaS


1.Reverse String
2.Stacks
3.Exit
Enter Choice: 1
Please enter in the string that you want to reverse without spaces or line breaks.
Reverse Input: wednesday
Your input was: wednesday
The reversed stirng of your input is:
yadsendew
*/

//Output for Lab exam question 3:
/*
1.Reverse String
2.Stacks
3.Exit
Enter Choice: 2
First Stack: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

Second stack: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

First stack part 2: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

Third stack: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/




