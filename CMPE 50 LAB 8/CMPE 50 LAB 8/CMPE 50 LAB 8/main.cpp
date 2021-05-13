#include<iostream>
#include "Complex.h"
#include "Complex.cpp"
#include "polynomial.h"
#include "polynomial-partial.cpp"

using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
class Exercise1 {
public:
    void ex1() {
        int constant = 5;
        double att_cfa[] = { 6.1,8.4,2.9 };
        double att_cfb[] = { 4.3,0.3 };
        Polynomial a(att_cfa, 2);
        Polynomial b(att_cfb, 1);

        cout << "Polynomial + Polynomial\n";
        cout << a << endl;
        cout << "+\n";
        cout << b << endl;
        cout << "=\n";
        cout << a + b << endl << endl;

        cout << "Constant + Polynomial\n";
        cout << constant << endl;
        cout << "+\n";
        cout << a << endl;
        cout << "=\n";
        cout << constant + a << endl << endl;

        cout << "Polynomial + Constant" << endl;
        cout << a << endl;
        cout << "+\n";
        cout << constant << endl;
        cout << "=\n";
        cout << a + constant << endl << endl;

        cout << "Polynomial - Polynomial" << endl;
        cout << a << endl;
        cout << "-\n";
        cout << b << endl;
        cout << "=\n";
        cout << a - b << endl << endl;

        cout << "Constant - Polynomial" << endl;
        cout << constant << endl;
        cout << "-\n";
        cout << a << endl;
        cout << "=\n";
        cout << constant - a << endl << endl;

        cout << "Polynomial - Constant" << endl;
        cout << a << endl;
        cout << "-\n";
        cout << constant << endl;
        cout << "=\n";
        cout << a - constant << endl << endl;

        cout << "Polynomial * Polynomial" << endl;
        cout << a << endl;
        cout << "*\n";
        cout << b << endl;
        cout << "=\n";
        cout << a * b << endl << endl;

        cout << "Constant * Polynomial" << endl;
        cout << constant << endl;
        cout << "*\n";
        cout << a << endl;
        cout << "=\n";
        cout << constant * a << endl << endl;

        cout << "Polynomial * Constant" << endl;
        cout << a << endl;
        cout << "*\n";
        cout << constant << endl;
        cout << "=\n";
        cout << a * constant << endl << endl;

        cout << "Evaluate polynomial at a value point." << endl;
        cout << "a(5.2) = " << a.evaluate(5.2) << endl;
    }
};

/*Algorithm for Exercise 1:
* The interface file will define all of the operations and functions that will be needed for the polynomials.
* the implementation file will implement the arithmetic operations as well as the stream operations needed to output results.
* It will then take in the numbers from the program application and will output all of the combinations between the constant and polynomial
* and with each arithmetic operator.
*
*
*/

/*Output for Exercise 1:
*Polynomial + Polynomial
2.9*x^2 + 8.4*x^1 + 6.1*x^0
+
0.3*x^1 + 4.3*x^0
=
2.9*x^2 + 8.7*x^1 + 10.4*x^0

Constant + Polynomial
5
+
2.9*x^2 + 8.4*x^1 + 6.1*x^0
=
2.9*x^2 + 8.4*x^1 + 11.1*x^0

Polynomial + Constant
2.9*x^2 + 8.4*x^1 + 6.1*x^0
+
5
=
2.9*x^2 + 8.4*x^1 + 11.1*x^0

Polynomial - Polynomial
2.9*x^2 + 8.4*x^1 + 6.1*x^0
-
0.3*x^1 + 4.3*x^0
=
2.9*x^2 + 8.4*x^1 + 6.1*x^0

Constant - Polynomial
5
-
2.9*x^2 + 8.4*x^1 + 6.1*x^0
=
-2.9*x^2 + -8.4*x^1 + -6.1*x^0

Polynomial - Constant
2.9*x^2 + 8.4*x^1 + 6.1*x^0
-
5
=
2.9*x^2 + 8.4*x^1 + 6.1*x^0

Polynomial * Polynomial
2.9*x^2 + 8.4*x^1 + 6.1*x^0
*
0.3*x^1 + 4.3*x^0
=
0.87*x^3 + 14.99*x^2 + 37.95*x^1 + 26.23*x^0

Constant * Polynomial
5
*
2.9*x^2 + 8.4*x^1 + 6.1*x^0
=
14.5*x^2 + 42*x^1 + 30.5*x^0

Polynomial * Constant
2.9*x^2 + 8.4*x^1 + 6.1*x^0
*
5
=
14.5*x^2 + 42*x^1 + 30.5*x^0

Evaluate polynomial at a value point.
a(5.2) = 128.196
*
*
*/


//Exercise 2-----------------------------------------------------------------------------------------
class Exercise2 {
public:
    void ex2() {
        const Complex i(0, 1);

        Complex in1;
        cin >> in1;
        cout << "The 1st complex number: " << in1;
        cout << "\n\n";

        Complex in2;
        cin >> in2;
        cout << "The 2nd complex number: " << in2;
        cout << "\n\n";

        Complex in3 = in1 + in2;
        cout << "\nThe sum of two complex numbers: " << in3.toString() << endl;

        Complex in4 = in1 - in2;
        cout << "\nThe difference of two complex numbers: " << in4.toString() << endl;

        Complex in5 = in1 * in2;
        cout << "\nThe product of two complex numbers: " << in5.toString() << endl;

        cout << "\nAre the two complex numbers equal? " << (in1 == in2) << endl;
    }
};

/*Algorithm for Exercise 2:
*The implementation file sets the different operations and functions to take the complex numbers.
* The interface files will organize and define the different operations and functions for the implementation file.
* The program will then go through the Complex.h file to call these methdos and functions for the main app.
* It will ask for the first complex number and the 2nd complex number, then it will output the sum, difference
* product and if the two complex numbers are equal.
*
*
*/

/*Output for Exercise 2:
*Please enter the real number value: 1
Please enter the imaginary number value: 2
The 1st complex number: (1 + 2i)

Please enter the real number value: 3
Please enter the imaginary number value: 4
The 2nd complex number: (3 + 4i)


The sum of two complex numbers: 4 + 6i

The difference of two complex numbers: -2 - 2i

The product of two complex numbers: -5 + 10i

Are the two complex numbers equal? 0
*
*
*/

int main()
{
    int selection, a, b, c;


    cout << "Which Program would you like to run?\n";
    cout << "Ex 3.1: Enter 1\n";
    cout << "Ex 3.2: Enter 2\n";

    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 poly;
        poly.ex1();
    }

    if (selection == 2) {
        cout << " " << endl;
        Exercise2 num;
        num.ex2();
    }

    return 0;

}
