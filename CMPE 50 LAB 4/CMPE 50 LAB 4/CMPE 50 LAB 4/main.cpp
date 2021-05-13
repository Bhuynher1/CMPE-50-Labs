#include<iostream>
#include<string>
#include<cstring>


using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
class Exercise1 {
public:

    bool isWhiteSpace(char character) {
        if (character == ' ' || character == '\t' || character == '\n' || character == '\r') {
            return true;
        }

        return false;
    }

    string convert(string string1) {
        string str = "";
        bool is_firstblank = false;
        int i = 0;

        while (isWhiteSpace(string1[i])) {
            i++;
        }

        char fLetter = toupper(string1[i]);
        str = str + fLetter;
        i++;
        int sentence;
        sentence = string1.size();

        for (i;  i < sentence; i++) {
            if (isWhiteSpace(string1[i])) {
                if (is_firstblank == false) {
                    str = str + " ";
                    is_firstblank = true;
                }
            }
            else {
                is_firstblank = false;
                char temp = string1[i];
                temp = tolower(temp);
                str = str + temp;
            }
        }

        return str;
    }

    void readsen() {
        string line = "a";
        string result;

        cout << "Please enter the test you want to format:\n";
        while (result.size() < 100) {
            getline(cin, line);
            result = result + " " + line;
            if (line[line.size()] == '.')
                break;
        }

        cout << endl;
        cout << "The formatted statement is: ";
        cout << convert(result);
        cout << endl;
    }
};

//The output of the program is:
//Which Program would you like to run?
//Ex 4.1: Enter 1
//Ex 4.2 : Enter 2
//What is your selection ? 1
//
//
//Please enter the test you want to format :
//  noW  iS   thE    TiMe  fOr  aLl
//          gOOD MEN TO  ComE TO   tHe
//      aId
//oF
//
//
//  ThE  CounTRY.
//
//The formatted statement is : Now is the time for all good men to come to the aid of the country.

//The algorithm for this program is:
//bool isWhiteSpace will check for a whitespace, \t, \n , and \r.
//string convert will go through each character input and check for white spaces,
//if there are are no white spaces in the input, it will return false then add the character.
//if it is the first character that isnt a whitespace, it will uppercase it with toupper.
//it will convert the first whitespace after a letter character into a regular space,
//and any other consecutive whitespace will be omitted.
//it will then check each input for whitespace and if its not a whitespace,
//it will put it into tolower if it is not the first initial character.
//The program will then repeat over and over until a '.' is found to stop the string input.
//the program will then output the finished line, with the first letter being uppercased.


//Exercise 2-----------------------------------------------------------------------------------------
class Exercise2 {
#include<iostream>
#include<string>

    using namespace std;

    string bad1[] = { "he", "him","his" };
    string good1[] = { "she", "her","hers" };
    string bad2[] = { "she or he","her or him", "hers or his" };

    bool IsAlphabet(char ch)
    {
        if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
            return true;
        return false;
    }

    string replaceStrWord(string word)
    {
        string replace = "";

        for (int i = 0; i < 3; i++)
        {
            if (bad1[i] == word)
            {
                replace = bad2[i];
            }

        }

        if (replace.compare("") == 0)
            replace = word;
        return replace;
    }

    int main()
    {
        while (true) {
            cout << "What is the sentence that you want to input? " << endl;
            string output = "";
            char next_symbol;
            string word = "";
            output = "";

            do {
                word = "";
                //Loop to get word
                while (true) {
                    cin.get(next_symbol);
                    if (IsAlphabet(next_symbol)) {
                        word += next_symbol;
                    }
                    else {
                        break;
                    }
                };

                if (word.compare("done") == 0)
                    break;

                output = output + replaceStrWord(word);
                output = output + next_symbol;

            } while (next_symbol != '\n');

            cout << endl;
            cout << "The gender neutral sentence is: " << endl;
            cout << output << endl;

            string userdone = "";
            cout << "Do u want to continue (Y/N): ";
            cin >> userdone;

            if (userdone == "n" || userdone == "N" || userdone == "no") {
                break;
            }
            if (userdone == "y" || userdone == "Y" || userdone == "yes") {
                cin.ignore();
            }
            else if (userdone != "n" || userdone != "N" || userdone != "y" || userdone != "Y") {
                cout << "It was a simple yes or no." << endl;
                system("pause");
                exit(1);
            }

        }

        return 0;
    }
};
//Output for this program
//What is the sentence that you want to input?
//See an adviser, talk to him, and listen to him.
//
//The gender neutral sentence is :
//See an adviser, talk to her or him, and listen to her or him.
//
//Do u want to continue (Y / N) : y
//What is the sentence that you want to input?
//See an adviser, talk to her or him, and listen to her or him.
//
//The gender neutral sentence is :
//See an adviser, talk to her or him, and listen to her or him.


//Algorithm for this program
//Ask the user for an input sentence, in terms of of the project "See an advisor, talk to him, and listen to him".
//It will then go through the string, check against the alphabet and concatenate it to the string word.
//There is a word bank that contains the sexist words and its replacements. It will then come over and replace it.
//it will then output the gender neutral sentence and then ask the user if they want to input another sentence.
// For some reason I was not able to get it to run in this class. It works in its own .cpp file.

int main()
{
    int selection;

    cout << "Which Program would you like to run?\n";
    cout << "Ex 4.1: Enter 1\n";
    cout << "Ex 4.2: Enter 2\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    if (selection == 1) {
        cout << " " << endl;
        Exercise1 sentence;
        sentence.readsen();
    }

  //  if (selection == 2) {
  //      cout << " " << endl;
  //      Exercise2 replace;
  //      replace.wronglingo();
  //}

    return 0;
}
