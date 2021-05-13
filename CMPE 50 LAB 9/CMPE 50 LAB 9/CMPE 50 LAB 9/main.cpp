//
//  main.cpp
//  CMPE 50 LAB 9
//
//  Created by Blake Huynh on 12/3/20.
//

#include <iostream>
#include "administrator.h"
#include "figure.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

void myDraw(Figure *fig) {
    fig ->draw();
    cout << "\n myDraw: Derived class object calling center(). \n";
    fig -> center();
}

class Exercise1 {
public:
    void ex1() {
        employeesavitch::Administrator admin("John Smith", "112233", 3200.00);
        admin.print();
        admin.print_check();
        system("pause");
    }
};

/*
 Algorithm for Exercise 1:
 
 */
/*
 Output for Exercise 1:
 Enter the administrator's title: CEO
 Enter the area of responsibility: Marketing
 Enter the immediate supervisor: Bob Jones
 Enter the Administrator's annual salary: 200000
 Details of the object
 Employee name: John Smith
 Employee ssn: 112233
 Employee net pay: 3200.00
 Employee salary: 3200.00
 Administrator's title: CEO
 Area of responsibility: Marketing
 Immediate supervisor: Bob Jones
 Administrator's annual salary: 200000.00

 Pay Check
 ________________________________________________________
 Pay to the order ofJohn Smith
 The sum of 16666.67Dollars
 ________________________________________________________
 Check Stub NOT NEGOTIABLE
 Employee Number: 112233
 Administrative Employee, Title: CEO
 Area of responsibility: Marketing
 ________________________________________________________
 */

class Exercise2 {
public:
    void ex2() {
        Figure *fig;
        Triangle *tri = new Triangle;
        
        fig = tri;
        fig -> draw();
        cout << "\n Derived class Triangle object calling center(). \n";
        fig -> center();
        
        myDraw(tri);
        
        Circle *cir = new Circle;
        fig = cir;
        fig -> draw();
        cout << "\n Derived class Circle object calling center(). \n";
        fig -> center();
        
        myDraw(cir);
        
    }
};

/*Algorithm for Exercise 2:
*
*/

/*Output for Exercise 2:
*
*/

int main()
{
    int selection;


    cout << "Which Program would you like to run?\n";
    cout << "Ex 9.1: Enter 1\n";
    cout << "Ex 9.2: Enter 2\n";

    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 admin;
        admin.ex1();
    }

    if (selection == 2) {
        cout << " " << endl;
        Exercise2 num;
        num.ex2();
    }

    return 0;

}
