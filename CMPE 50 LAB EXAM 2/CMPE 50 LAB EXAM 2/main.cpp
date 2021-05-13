#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

string num1[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8" };
string numword1[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight" };

//Class Declaration
class Diner {
public:
    Diner();
    Diner(string& newdinerName, string& newdinerRating);
    Diner(string& dinerName, string& dinerRating, int Terrible, int Bad, int OK, int Good, int Great);

    string getDinerName();
    void setName(string newdinerName);

    string getDinerRating();
    void setRating(string newdinerRating);
    void collectRating(int rating);
    friend bool ratingCheck(Diner& diner1, Diner& diner2);

    void setAvg(double average);
    double getAvg();

private:
    string diner_Name;
    string diner_Rating;
    double AVG;
    int Terrible, Bad, OK, Good, Great;

};

//Function Declarations
void output(ostream& out, string line) {
    out << line << endl;
}
void spellNum();
void dinerStory();

int main()
{

    //Declaring variables
    int choice;
    string inputfile, outputfile;

    /* This while loop continues to execute
    * until the user chooses choice 3
    */

    while (true) {
        //displaying the menu
        cout << "\n1.Reading Numbers" << endl;
        cout << "2.Diner" << endl;
        cout << "3.Exit" << endl;

        //getting the choice entered by the user
        cout << "Enter Choice: ";
        cin >> choice;

        //Based on the user choice the corresponding case will be executed
        switch (choice) {
        case 1: {
            spellNum();

            continue;
        }
        case 2: {
            dinerStory();
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

// Function for changing the number in a sentence to a word
void spellNum()
{
    ifstream dataIn;
    ofstream dataOut;
    string infile;
    string outfile;

    cout << "Enter the name of the input file: ";
    cin >> infile;
    cout << " " << endl;
    cout << "Enter the name of the output file: ";
    cin >> outfile;
    cout << " " << endl;
    cout << " " << endl;

    dataIn.open(infile);
    if (dataIn.fail()) {
        cout << infile << "There was an error in opening the file." << endl;
        system("pause");
        exit(1);
    }

    dataOut.open(outfile);
    if (dataOut.fail()) {
        cout << outfile << "There was an error in opening the file." << endl;
        system("pause");
        exit(1);
    }

    while (!dataIn.eof()) {
        string string1;
        getline(dataIn, string1);

        while (true)
        {
            bool correct = false;
            for (int i = 0; i < 9; i++) {
                int number = 0;
                number = string1.find(num1[i]);
                if (number >= 0) {
                    string1.replace(number, 1, numword1[i]);
                    correct = true;
                }
            }
            if (!correct) {
                break;
            }
        }
        output(cout, string1);
        output(dataOut, string1);
    }

    cout << " " << endl;
    cout << "The Output file has been created.";

    dataIn.close();
    dataOut.close();
}

//Set of functions for the Diner Exercise
void dinerStory() {
    Diner res1;
    Diner res2;

    res1.setName("Olive Garden");
    res1.setRating("Bad");

    res1.collectRating(1);
    res1.collectRating(4);
    res1.collectRating(2);
    res1.collectRating(2);
    res1.collectRating(1);
    res1.collectRating(3);

    res2.setName("Ebisu Japanese Restaurant");
    res2.setRating("Great");

    res2.collectRating(4);
    res2.collectRating(4);
    res2.collectRating(5);
    res2.collectRating(5);
    res2.collectRating(5);
    res2.collectRating(5);

    cout << "\nRestaurant #1 info: " << endl;
    cout << "Restaurant Name: " << res1.getDinerName() << endl;
    cout << "Restaurant Rating: " << res1.getDinerRating() << endl;
    cout << "Customer Rating: " << res1.getAvg() << " stars" << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "Restaurant #2 info: " << endl;
    cout << "Restaurant Name: " << res2.getDinerName() << endl;
    cout << "Restaurant Rating: " << res2.getDinerRating() << endl;
    cout << "Customer Rating: " << res2.getAvg() << " stars" << endl;
    cout << endl;

    if (ratingCheck(res1, res2)) {
        cout << "The ratings of both restaurants are the same." << endl;
    }
    else {
        cout << "The ratings of both restaurants are not the same." << endl;
    }
}
bool ratingCheck(Diner& diner1, Diner& diner2) {
    return diner1.getAvg() == diner2.getAvg();
}

Diner::Diner() {
    diner_Name = "";
    diner_Rating = "";

    Terrible = 0;
    Bad = 0;
    OK = 0;
    Good = 0;
    Great = 0;
}
Diner::Diner(string& newDinerName, string& newDinerRating) {
    diner_Name = newDinerName;
    diner_Rating = newDinerRating;

    Terrible = 0;
    Bad = 0;
    OK = 0;
    Good = 0;
    Great = 0;
}
Diner::Diner(string& dinerName, string& dinerRating, int Terrible, int Bad, int OK, int Good, int Great)
{
    diner_Name = dinerName;
    diner_Rating = dinerRating;

    Terrible = Terrible;
    Bad = Bad;
    OK = OK;
    Good = Good;
    Great = Great;
}

string Diner::getDinerName()
{
    return diner_Name;
}
void Diner::setName(string newdinerName)
{
    diner_Name = newdinerName;
}

string Diner::getDinerRating()
{
    return diner_Rating;
}
void Diner::setRating(string newdinerRating)
{
    diner_Rating = newdinerRating;
}
void Diner::collectRating(int rating)
{
    if (rating < 1 || rating > 5)
    {
        cout << "Restaurant's rate can not be set.Please rate from 1-5 \n";
        exit(1);
    }
    switch (rating)
    {
    case 1:
        Terrible++;
        break;
    case 2:
        Bad++;
        break;
    case 3:
        OK++;
        break;
    case 4:
        Good++;
        break;
    case 5:
        Great++;
        break;
    }
}

void Diner::setAvg(double average) {
    AVG = average;
}
double Diner::getAvg()
{
    return (double)(Terrible * 1 + Bad * 2 + OK * 3 + Good * 4 + Great * 5) / (Terrible + Bad + OK + Good + Great);
}
