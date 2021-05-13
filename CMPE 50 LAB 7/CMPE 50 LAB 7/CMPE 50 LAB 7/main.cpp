#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
class Exercise1 {
public:
    void displaySeat(char** matrix, int n, ostream& output) {
        output << "\nThe seating selection is now:\n\n";
        for (int i = 0; i < n; i++) {
            output << i + 1 << " ";
            for (int j = 0; j < 4; j++)
                output << matrix[i][j] << " ";
            output << "\n";
        }
        output << "\n";
    }

    void bookingProgram(istream& input, ostream& output) {
        output << "Please enter the number of rows in the plane: ";
        int rowSize, colSize = 4;
        input >> rowSize;

        char** seats = new char* [rowSize];
        for (int i = 0; i < rowSize; ++i)
            seats[i] = new char[colSize];

        for (int i = 0; i < rowSize; i++)
            for (int j = 0; j < 4; j++)
                seats[i][j] = 'A' + j;

        displaySeat(seats, rowSize, output);
        string str;
        output << "Please Enter in the seat or type end to stop: ";

        while (input >> str) {
            if (str == "end") {
                system("pause");
                exit(1);
            }

            int len = str.length();
            char pos = str[len - 1];
            string num = str.substr(0, len);
            int row = stoi(num);
            int column = pos - 'A';
            if (row - 1 < rowSize && column < 4 && seats[row - 1][column] == 'X')
                cout << "This seat has already been booked.\n";
            else {
                seats[row - 1][column] = 'X';
                displaySeat(seats, rowSize, output);
            }
            output << "\nPlease Enter in the seat or type end to stop: ";
        }

        for (int i = 0; i < rowSize; ++i)
            delete[] seats[i];
        delete[] seats;
    }

    int airline() {
        cout << "\t Welcome to the Airline Booking Program\n";
        cout << "\n1. User Input \n2. File Input \n3. Exit Program \nSelection: ";
        int choice;
        cin >> choice;
        if (choice == 1) {

            bookingProgram(cin, cout);
        }
        else if (choice == 2) {

            ifstream infile;
            cout << "Input the file name:";
            string s;
            cin >> s;
            infile.open(s.c_str());
            if (infile.fail()) {
                cout << "There was an error in opening the file." << endl;
                system("pause");
                exit(1);
            }

            bookingProgram(infile, cout);

            infile.close();
        }
        else if (choice == 3) {
            cout << "Thank you for using the Airline Booking Program\n\n";
            exit(1);
        }
        else {
            cout << "Invalid Choice\n";
        }
    }
};

/*Algorithm for Exercise 1:
* The program will ask the user if they want to input through the user or file.
* it will then ask the user for the amount of rows in the plane.
* the program will then take  the user or file input and subtract the letter from the input.
* it will then convert the string into an integer through std::stoi.
* It will continue to repeat until there are no more seats available or that the user will type end.
*
*/

/*Output for Exercise 1:
         Welcome to the Airline Booking Program

1. User Input
2. File Input
3. Exit Program
Selection: 1
Please enter the number of rows in the plane: 7

The seating selection is now:

1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D

Please Enter in the seat or type end to stop: 6A

The seating selection is now:

1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 X B C D
7 A B C D


Please Enter in the seat or type end to stop: 4B

The seating selection is now:

1 A B C D
2 A B C D
3 A B C D
4 A X C D
5 A B C D
6 X B C D
7 A B C D


Please Enter in the seat or type end to stop: 7D

The seating selection is now:

1 A B C D
2 A B C D
3 A B C D
4 A X C D
5 A B C D
6 X B C D
7 A B C X


Please Enter in the seat or type end to stop: 2A

The seating selection is now:

1 A B C D
2 X B C D
3 A B C D
4 A X C D
5 A B C D
6 X B C D
7 A B C X


Please Enter in the seat or type end to stop: 1A

The seating selection is now:

1 X B C D
2 X B C D
3 A B C D
4 A X C D
5 A B C D
6 X B C D
7 A B C X
*/


//Exercise 2-----------------------------------------------------------------------------------------
class Exercise2 {
public:
    void charinput() {
        char array1[] = "to be or not to be";
        int size = sizeof(array1);

        printarray(array1, size);

        cout << "After deleting the duplicates" << endl;
        char* newarray1 = delete_repeats(array1, size);

        printarray(newarray1, size);
    }

    void printarray(char* array1, int size) {
        for (int i = 0; i < size; ++i) {
            cout << array1[i];
        }
        cout << endl;
    }

    char* delete_repeats(char* array1, int& size) {
        char* newarray1 = new char[size];
        int count = 0;

        for (int i = 0; i < size; ++i) {
            int flag = 0;
            for (int j = 0; j < i; ++j) {
                if (array1[i] == array1[j]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                newarray1[count++] = array1[i];
            }
        }
        size = count;
        return newarray1;
    }

};

/*Algorithm for Exercise 2:
*This program will take in the statement "to be or not to be" and put into array1.
* the array will then be printed and then sent to delete_repeats.
* It will then take each letter and put into a 2nd array. it will check if both arrays
* at each element is equal to each other then it will break to stop the new array from
*  having the repeated letter.
* then it will return the new array to be outputted.
*
*/

/*Output for Exercise 2:
to be or not to be
Deleting the duplicates...
to bern
*/


int main()
{
    int selection, a, b, c;

    cout << "Which Program would you like to run?\n";
    cout << "Ex 7.1: Enter 1\n";
    cout << "Ex 7.2: Enter 2\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 booking;
        booking.airline();
    }

    if (selection == 2) {
        cout << " " << endl;
        Exercise2 delet;
        delet.charinput();
    }

    return 0;
}
