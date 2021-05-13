#include <iostream>
using namespace std;

class printSentence {
public:
    void printLine() {
        cout << "A fool thinks himself to be wise, but a wise man knows himself to be a fool.\n";
    }

    //The output of the Lab exercise 1.2 was
    // A fool thinks himself to be wise, but a wise man knows himself to be a fool.
};

class squareNumber {
public:
    void numberSquare() {
        int num, square;

        cout << "What is the number you wish to square?" << endl;
        cin >> num;

        square = num * num;
        cout << "The square of the number that you inputted is " << square << endl;
    }

//The output of the above program was
//What is the number you wish to square?
//
//25
//The square of the number that you inputted is 625
};

class primeNumber {
public:
    void primeNumbers() {
        int num, i, k, counter;
        cout << "This program will output all prime numbers from 3 till your input.\n" << endl;
        cout << "Enter a number greater than 2: ";
        cin >> k;

        cout << endl << "All prime numbers up to your input, " << k << ", are: " << endl;

        bool isPrime = true;
        if (2 == k || 3 == k) {
            cout << k << " is a prime number. " << endl;
        }

        for (num = 2; num <= k - 1; num++) {
            for (i = 2; i <= (num / 2); i++) {
                if (num % i == 0) {
                    i = num;
                    break;
                }
            }

            if (i != num) {
                cout << num << " is a prime number." << endl;
            }
        }
    }

    //This is the output of this program
    //
    //This program will output all prime numbers from 3 till your input.
    //
    //Enter a number greater than 2: 10
    //
    //All prime numbers up to your input, 10, are :
    //    3 is a prime number.
    //    5 is a prime number.
    //    7 is a prime number.
};

int main()
{

    int selection, a, b, c;
    

    cout << "Which Program would you like to run?\n";
    cout << "Ex 1.2: Enter 1\n";
    cout << "Ex 1.3: Enter 2\n";
    cout << "Ex 1.4: Enter 3\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;
   
    if (selection == 1) {
        cout << " " << endl;
        printSentence sentence;
        sentence.printLine();
    }
    
    if (selection == 2) {
        cout << " " << endl;
        squareNumber square;
        square.numberSquare();
    }

    if (selection == 3) {
        cout << " " << endl;
        primeNumber number;
        number.primeNumbers();
    }
    

    
    return 0;

}

