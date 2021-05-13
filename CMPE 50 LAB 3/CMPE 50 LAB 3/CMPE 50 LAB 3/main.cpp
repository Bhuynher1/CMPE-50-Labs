#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
class Exercise1 {
public:
    void labinput1() {
        ifstream inputFile;
        ofstream outputFile;
        char array[100];
        int counter = 0;
        char character;

        inputFile.open("LabInput3-1.txt", ios::in);

        if (inputFile.fail()) {
            cout << "The file that you are trying to input does not exist." << endl;
            exit(1);
        }

        while (inputFile >> array[counter++]) {
        }

        inputFile.close();
        outputFile.open("LabOutput3-1.txt", ios::out);

        for (int i = 0; i < counter - 1; i++) {
            character = array[i];
            if (character != ' ' && character != '\n') {
                outputFile << (char)(toupper(character));
            }
        }

        outputFile.close();
        cout << "\nThe program has successfully outputted the file.";
        
    }
};

//Algorithm for Exercise 3:
//When the program is run, it will test if the file exists or not.
//If the file exists, the characters within the file will be inputted into the array,
//then for each character, make it upper case then take away all white spaces.
//If the file exists, output a file with the array printed.
//If the file does not exists, output an error to the user telling them the file doesnt exist.

//Output for Exercise 1:
//The program has successfully outputted the file.
//*The file LabOutput3-1.txt was created in the project folder.*

//Exercise 2-----------------------------------------------------------------------------------------
class Exercise2 {
public:
    void labinput2() {
        int num = 0, i = 0, k, counter, selection, index[50];
        char array[50];

        cout << "Please enter 1 for user input or 2 for file input: ";
        cin >> selection;

        if (selection == 1) {
            cout << "How many numbers would you like to enter? " << endl;
            cin >> num;
            cout << "Please enter the " << num << " integers please: ";

            for (i = 0; i < num; i++) {
                cin >> index[i];
                i++;
                num++;
            }
        }

        if (selection == 2) {
            cout << "\n Please enter the file name: ";
            cin >> array;
            ifstream inputFile(array);
            
            while (inputFile >> index[i]) {
                num++;
                i++;
            }
        }

        for (i = 0; i < num; i++) {
            for (k = 0; k <= i; k++) {
                if (index[i] > index[k]) {
                    int temp = index[i];
                    index[i] = index[k];
                    index[k] = temp;
                }
            }
        }

        cout << "\nN\tCount\n";

        for (i = 0; i < num; i++) {
            counter = 1;

            while (index[i] == index[i + 1] && i < num) {
                counter++;
                i++;
            }

            cout << index[i] << "\t" << counter << endl;
        }
    }
};

//Algorithm for Exercise 3:
//Ask the user if they want to input the numbers or select a file to import numbers
//If user wants to put in numbers, ask the user for the amount of numbers to be inputted.
//If the user wants to import numbers from a file, ask for file name then import numbers.
//The numbers inputted from either the user or the file will go into index[].
//While the numbers are being put into the index array, count the amount of each number.
//sort the numbers into decending numbers
//output a file that has the decending numbers on one side, then the count of each number next to it.

//Output for user input selection:
//Please enter 1 for user input or 2 for file input : 1
//How many numbers would you like to enter ?
//6
//Please enter the 6 integers please : -3 4 1 1 3 4
//
//N       Count
//4       2
//3       1
//1       2
//- 3      1

//Output for file selection:
//Please enter 1 for user input or 2 for file input : 2
//
//Please enter the file name : LabInput3 - 2.txt
//
//N       Count
//4       2
//3       1
//1       2
//- 3      1

//Exercise 3-----------------------------------------------------------------------------------------
class Exercise3 {
public:

    void labinput3() {
        ifstream inputFile1;
        ifstream inputFile2;
        ofstream outputFile;

        string inFileName1;
        string inFileName2;
        string outFileName;

        cout << "Enter the name of the first input file: ";
        cin >> inFileName1;

        cout << "Enter the name of the second input file: ";
        cin >> inFileName2;

        cout << "Enter the name of the output file: ";
        cin >> outFileName;

        inputFile1.open(inFileName1);
        if (inputFile1.fail()) {
            cout << inFileName1 << "There was an error in opening the file." << endl;
            system("pause");
            exit(1);
        }

        inputFile2.open(inFileName2);
        if (inputFile2.fail()) {
            cout << inFileName2 << "There was an error in opening the file." << endl;
            system("pause");
            exit(1);
        }

        outputFile.open(outFileName);
        if (outputFile.fail()) {
            cout << outFileName << "There was an error in opening the file." << endl;
            system("pause");
            exit(1);
        }

        sortFiles(inputFile1, inputFile2, outputFile);

        inputFile1.close();
        inputFile2.close();
        outputFile.close();

        cout << "\nYour file has been generated successfully!";
        cout << " " << endl;
        cout << " " << endl;
    }

    void sortFiles(ifstream& input1, ifstream& input2, ofstream& output) {
        int ifile1, ifile2;
        input1 >> ifile1;
        input2 >> ifile2;

        while (!input1.eof() && !input2.eof()) {
            if (ifile1 <= ifile2) {
                output << ifile1 << endl;
                input1 >> ifile1;
            }
            else {
                output << ifile2 << endl;
                input2 >> ifile2;
            }
        }

        if (ifile1 <= ifile2) {
            while (!input2.eof()) {
                output << ifile2 << endl;
                input2 >> ifile2;
            }
        }
        else {
            while (!input1.eof()) {
                output << ifile1 << endl;
                input1 >> ifile1;
            }
        }
    }
    
};

//Algorithm for Exercise 3:
//Open the two input files and the output file, check for opening errors
//input the numbers within each file to other integers to hold the numbers
//while reading both of the inputs,
//sort and export the numbers into the output file in ascending order.

//Output for Exercise 3:
//Enter the name of the first input file : LabInput3 - 3.txt
//Enter the name of the second input file : LabInput3 - 4.txt
//Enter the name of the output file : LabOutput3 - 3.txt
//
//Your file has been generated successfully!

int main()
{
    int selection, a, b, c;


    cout << "Which Program would you like to run?\n";
    cout << "Ex 3.1: Enter 1\n";
    cout << "Ex 3.2: Enter 2\n";
    cout << "Ex 3.3: Enter 3\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 charinput;
        charinput.labinput1();
    }

    if (selection == 2) {
        cout << " " << endl;
        Exercise2 intinput;
        intinput.labinput2();
    }

    if (selection == 3) {
        cout << " " << endl;
        Exercise3 fileInput;
        fileInput.labinput3();
    }

    return 0;

}

