#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
class Exercise1 {
public:
        double Add(double num1, double num2) {
            return num1 + num2;
        }
        
        int Add(int num3, int num4) {
            return num3 + num4;
        }
        
        void Add(char char1[50], char char2[50]) {
            cout << char1;
            cout << char2;
        }

        void Addition() {
            int selection;

            cout << "Would you like to add two doubles, two ints or a two character array? " << endl;
            cout << "Please type, 1 for double, 2 for int, or 3 for char array: " << endl;
            cin >> selection;

            switch (selection) {
            case 1:
                double num1, num2;
                cout << "What are the two doubles that you would like to add?" << endl;
                cout << "Number 1: " << endl;
                cin >> num1;
                cout << "Number 2: " << endl;
                cin >> num2;
                cout << "The sum of adding the two doubles were: " << Add(num1, num2) << endl;
                break;


            case 2:
                int num3, num4;
                cout << "What are the two integers that you would like to add?" << endl;
                cout << "Number 1: " << endl;
                cin >> num3;
                cout << "Number 2: " << endl;
                cin >> num4;
                cout << "The sum of adding the two integers were: " << Add(num3, num4) << endl;
                break;

            case 3:
                char char1[50], char2[50];
                cout << "What are the two characters that you would like to add?" << endl;
                cout << "Char 1: " << endl;
                cin >> char1;
                cout << "Char 2: " << endl;
                cin >> char2;
                cout << "The sum of adding the two characters were: ";
                Add(char1, char2);
                break;

            default:
                cout << "Not A selection" << endl;
                break;
            }
    }
};
//Algorithm for Exercise 1:
//Ask the user for which mode they would like to add
//take in input and then output the selected add function based on user input
//take the two numbers and place them into either a double, int, or char array
//add the two number/arrays then output it

//Output for Exercise 1:
//Would you like to add two doubles, two ints or a two character array ?
//Please type, 1 for double, 2 for int, or 3 for char array :
//    1
//    What are the two doubles that you would like to add ?
//   Number 1 :
//    2.50
//    Number 2 :
//    3.50
//    The sum of adding the two doubles were : 6

//Exercise 2-----------------------------------------------------------------------------------------
class Exercise2 {
    public:
        void reverse() {
            char input[10];
            cout << "Please enter in 10 characters that you want to reverse: " << endl;
            int i, counter = 1;

            for (i = 0; i <= 11; i++)
            {
                cout << "Please enter in number " << counter << +": ";
                cin >> input[i];

                counter++;

                if (input[i] == '.' || counter == 11)
                {
                    break;
                }
            }

            cout << "The final reverse of your inputs is: ";
            for (int k = i - 1; k >= 0; k--)
            {
                cout << input[k];
            }
    }
};
//Algorithm for Exercise 2:
//Output line to ask for the 10 char to reverse
//the user will tab each letter into the character array
//if there is a period or where the character array hits the limit of 10
//the program will output the reverse of the input before the period,
//or if the user inputs characters past 10,
//it will stop taking inputs and output the reverse

//Output for Exercise 2:
//Please enter in 10 characters that you want to reverse :
//Please enter in number 1 : 1
//Please enter in number 2 : 2
//Please enter in number 3 : 3
//Please enter in number 4 : 4
//Please enter in number 5 : 5
//Please enter in number 6 : .
//The final reverse of your inputs is : 54321
//Exercise 3-----------------------------------------------------------------------------------------

//Exercise 3-----------------------------------------------------------------------------------------
class Exercise3 {
public:
    void homework(){
        double array[2][5], high1, low1, avg1 = 0, high2, low2, avg2 = 0;
        bool failOrPass = true;
        bool statusOfAvg = false;
        string fail_pass_status;
        int counter = 1;
        cout << "Please enter in the scores of the student's work: " << endl;

        for (int i = 0; i < 2; i++) {
            for (int k = 0; k < 5; k++) {
                cout << "Score " << counter << ": ";
                cin >> array[i][k];
                counter++;
            }

        }

        high1 = array[0][0];
        high2 = array[0][0];
        low1 = array[0][0];
        low2 = array[0][0];

        for (int j = 0; j < 5; j++) {
            if (array[0][j] > high1) {
                high1 = array[0][j];
            }

            if (array[0][j] < low1) {
                low1 = array[0][j];
            }

            avg1 = avg1 + array[0][j];
        }

        for (int j = 0; j < 5; j++) {
            if (array[1][j] > high2) {
                high2 = array[1][j];
            }

            if (array[1][j] < low2) {
                low2 = array[1][j];
            }

            avg2 = avg2 + array[1][j];
        }

        cout << "\t1\t2\t3\t4\t5\tBEST\tWORST\tAVG" << endl;
        cout << "\t**************************************************************" << endl;

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                cout << "HW\t";
                for (int k = 0; k < 5; k++) {
                    cout << fixed << setprecision(2) << array[i][k] << "\t";
                }
                cout << fixed << setprecision(2) << high1 << "\t" << low1 << "\t" << avg1 / 5;
            }

            if (i == 1)
            {
                cout << "LAB\t";
                for (int k = 0; k < 5; k++) {
                    cout << array[i][k] << setprecision(2) << "\t";
                }
                cout << fixed << setprecision(2) << high2 << "\t" << low2 << "\t" << avg2 / 5;

            }
            cout << endl;
        }

        if (avg1 <= 50) {
            failOrPass = true;
            fail_pass_status = "your homework papers";

        }
        else if (avg2 <= 50) {
            failOrPass = true;
            fail_pass_status = "your lab classes";

        }

        double overall = 0;
        avg1 = 0;
        cout << endl << "AVG\t";

        for (int i = 0; i < 5; i++)
        {
            for (int k = 0; k < 2; k++) {
                avg1 = avg1 + array[k][i];
            }
            cout << avg1 / 2 << "\t";
            if (avg1 / 2 < 50) {
                failOrPass = false;
                statusOfAvg = true;
            }
            overall = overall + avg1 / 2;
            avg1 = 0;
        }

        cout << "Overall: " << overall / 5 << endl;

        if (failOrPass == true) {
            cout << "Congratulations, you have passed the class!" << endl;
        }

        else {
            if (statusOfAvg) {
                cout << "I am sorry to inform that you have failed the class. Your performance in "
                    << fail_pass_status << " was less than 50%. Please try again next semester.";
            }
            else {
                cout << "I am sorry to inform you that you have failed the class because of your ";
                cout << "performance in your subjects was below 50%. Please try again next semester.";
            }
        }
    }
};

//Algorithm for Exercise 3:
//The program will first askthe user for the score inputs.
//once the user has inputted 10 scores,
//the program will put the scores into array[i][k] for the scores.
//we then have arrays high1[], high2[], low1[], low2[] to sort the scores and also average the scores for the HW and lab
//it will then base the output by checking the averages
//the program will then output the scores correctly and tell the user if they have passed
//or failed while stating the reason why they failed.

//Output for Exercise 3:
//Please enter in the scores of the student's work:
//Score 1: 90
//Score 2 : 80
//Score 3 : 70
//Score 4 : 100
//Score 5 : 100
//Score 6 : 100
//Score 7 : 100
//Score 8 : 80
//Score 9 : 90
//Score 10 : 70
//1       2       3       4       5       BEST    WORST   AVG
//* *************************************************************
//HW      90.00   80.00   70.00   100.00  100.00  100.00  70.00   88.00
//LAB     100.00  100.00  80.00   90.00   70.00   100.00  70.00   88.00
//
//AVG     95.00   90.00   75.00   95.00   85.00   Overall: 88.00
//Congratulations, you have passed the class!
int main()
{
    int selection, a, b, c;


    cout << "Which Program would you like to run?\n";
    cout << "Ex 2.1: Enter 1\n";
    cout << "Ex 2.2: Enter 2\n";
    cout << "Ex 2.3: Enter 3\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 adding;
        adding.Addition();
    }

    if (selection == 2) {
        cout << " " << endl;
        Exercise2 turnitaround;
        turnitaround.reverse();
    }

    if (selection == 3) {
        cout << " " << endl;
        Exercise3 score;
        score.homework();
    }

    return 0;

}
