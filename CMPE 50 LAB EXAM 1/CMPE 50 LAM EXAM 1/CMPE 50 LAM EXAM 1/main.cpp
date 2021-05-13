#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Exercise 2-----------------------------------------------------------------------------------------
class Ex2 {
public:
    void grocery() {
        ifstream inputFile;
        double expense[12], annual_expense = 0, high, low, grocery;
        int counter = 1;

        inputFile.open("LabExamInput1-2.txt", ios::in);

        if (inputFile.fail()) {
            cout << "The file that you are trying to input does not exist." << endl;
            exit(1);
        }

        while (inputFile >> expense[counter++]) {
        }
        inputFile.close();
       
        for (int i = 0; i < counter - 1; i++) {
            grocery = expense[i];
            if (i == 1) {
                high = low = grocery;
            }
            else if (grocery > high) {
                high = grocery;
            }
            else if (grocery < low) {
                low = grocery;
            }

            annual_expense += grocery;
        }

        cout << "\nAnnual grocery expenses: $" << annual_expense << endl;
        cout << "The highest grocery expense was: $" << high << endl;
        cout << "The lowest grocery expense was: $" << low << endl;
        cout << "Average monthly grocery expense: $" << annual_expense / 12 << endl;
    }
};

//Exercise 3-----------------------------------------------------------------------------------------
class Ex3 {
public:

    void sort(char letters[], int integers[], int counter);

    void swap(char& char1, char& char2, int& int1, int& int2);

    void input2() {
        const int charmax = 50;
        int num = 0, i = 0, k, counter = 0, selection, index, integers[charmax] = {0};
        char characters, infile[50], letters[charmax] = {'\0'};

        ofstream outputFile;
        outputFile.open("LabExamOutput1-3.txt", ios::out);

        cout << "Please enter 1 for user input or 2 for file input: ";
        cin >> selection;

        if (selection == 1) {
            cout << "How many characters would you like to enter? " << endl;
            cin >> num;
            cout << "Please enter the " << num << " characters please: ";
            cin >> characters;

            while (characters != '.' || counter < charmax) {
                for (i = 0; i < num; i++) {
                    if (isalpha(characters)) {
                        index = 0;
                        while (index < counter) {
                            if (letters[index] == characters) {
                                break;
                            }
                            else {
                                index++;
                            }
                        }
                        if (index < counter) {
                            integers[index] + 1;
                        }
                        else {
                            letters[index] = characters;
                            integers[index] = 1;
                            counter++;
                        }

                        cin >> characters;
                    }
                }
            }

            sort(letters, integers, counter);
            outputFile << "\nLetter\tNumber Of Occurances" << endl;
            outputFile << "------------------------------" << endl;

            for (int i = 0; i < counter; i++) {
                outputFile << letters[i] << "\t\t" << integers[i] << endl;
            }

         }

        if (selection == 2) {
            cout << "\n Please enter the file name: ";
            cin >> infile;
            ifstream inputFile(infile);
            cin >> characters;

            while (characters != '.' || counter < charmax) {
                for (i = 0; i < num; i++) {
                    if (isalpha(characters)) {
                        index = 0;
                        while (index < counter) {
                            if (letters[index] == characters) {
                                break;
                            }
                            else {
                                index++;
                            }
                        }

                        if (index < counter) {
                            integers[index] + 1;
                        }
                        else {
                            letters[index] = characters;
                            integers[index] = 1;
                            counter++;
                        }

                        cin >> characters;
                    }
                }
            }


            sort(letters, integers, counter);
            outputFile << "\nLetter\tNumber Of Occurances" << endl;
            outputFile << "------------------------------" << endl;

            for (int i = 0; i < counter; i++) {
                outputFile << letters[i] << "\t\t" << integers[i] << endl;
            }
        }

        outputFile.close();
        cout << "\nThe program has successfully outputted the file.";
    }

    void sort(char letters[], int integers[], int counter) {
        for (int i = 0; i < counter - 1; i++) {
            int j = largest_index(integers, i, counter);
            swap(letters[i], letters[j], integers[i], integers[j]);
        }
    }

    void swap(char& char1, char& char2, int& int1, int& int2) {
        char temp_character = char1;
        char1 = char2;
        char2 = temp_character;

        int temp_int = int1;
        int1 = int2;
        int2 = temp_int;
    }

    int largest_index(const int integers[], int first, int counter) {
        int max_integer = integers[first];
        int max_integer_index = first;

        for (int i = first + 1; i < counter; i++) {
            if (integers[i] > max_integer) {
                max_integer = integers[i];
                max_integer_index = i;
            }
        }
        return max_integer_index;
    }
};




int main()
{
    int selection, a, b, c;

    cout << "Which Program would you like to run?\n";
    cout << "LAB EXAM 1 Exercise 2: Enter 1\n";
    cout << "LAB EXAM 1 Exercise 3: Enter 2\n";
    cout << "To Exit the Program: Enter 3\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Ex2 expense;
        expense.grocery();
    }

    if (selection == 2) {
        cout << " " << endl;
        Ex3 charinput;
        charinput.input2();
    }

    if (selection == 3) {
        cout << " " << endl;
        exit(1); // or break;
    }

    return 0;

}
