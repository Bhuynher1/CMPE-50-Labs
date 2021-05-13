#include<iostream>

using namespace std;

//Exercise 1-----------------------------------------------------------------------------------------
/* class Exercise1 {
#include<iostream>
#include<string>

    using namespace std;

    const int class_size = 5;

    class StudentRecord {


    private:
        int studentID;
        double quiz1, quiz2, midterm, final, avg;
        char grade;

    public:
        void studentData(StudentRecord& student);
        void calculateGrade(StudentRecord& student);
        void studentResult(const StudentRecord student);
    };

    int main() {
        StudentRecord student[class_size];

        for (int i = 0; i < class_size; i++) {
            student[i].studentData(student[i]);
        }

        for (int i = 0; i < class_size; i++) {
            student[i].calculateGrade(student[i]);
            student[i].studentResult(student[i]);
            cout << endl;
        }

        system("pause");
        return 0;
    }

    void StudentRecord::studentData(StudentRecord& student) {
        cout << "Please enter in the student number: ";
        cin >> student.studentID;

        cout << "Please enter the scores for the 2 quizes: " << endl;
        cin >> student.quiz1 >> student.quiz2;

        cout << "Please enter the scores for the midterm and final: " << endl;
        cin >> student.midterm >> student.final;
    }

    void StudentRecord::calculateGrade(StudentRecord& student) {
        double quizAvg = (student.quiz1 + student.quiz2) / 2.0;
        double realQuizAvg = quizAvg * 10;

        student.avg = student.final * 0.5 + student.midterm * 0.25 + realQuizAvg * 0.25;

        char grade[] = "FFFFFFDCBAA";
        int index = static_cast<int>(student.avg / 10);
        if (index < 0 || 10 <= index) {
            cout << "The number inputted has an error: " << student.avg
                << endl << "Exiting program.\n";
            exit(1);
        }
        student.grade = grade[index];
    }

    void StudentRecord::studentResult(const StudentRecord student) {
        cout << "Student ID number: " << student.studentID << endl;
        cout << "The quiz grades are: " << student.quiz1
            << " and " << student.quiz2 << endl;
        cout << "The midterm and final grades are: " << student.midterm
            << " and " << student.final << endl;

        cout << "The average of the scores is: " << student.avg << endl;
        cout << "The grade that you recieved was: " << student.grade << endl;
    }
};
*/

/* OUTPUT for Exercise 1:
Please enter in the student number: 1
Please enter the scores for the 2 quizes:
8
7
Please enter the scores for the midterm and final:
78
89
Please enter in the student number: 2
Please enter the scores for the 2 quizes:
9
8
Please enter the scores for the midterm and final:
67
89
Please enter in the student number: 3
Please enter the scores for the 2 quizes:
7
8
Please enter the scores for the midterm and final:
78
98
Please enter in the student number: 4
Please enter the scores for the 2 quizes:
7
8
Please enter the scores for the midterm and final:
67
78
Please enter in the student number: 5
Please enter the scores for the 2 quizes:
5
10
Please enter the scores for the midterm and final:
78
87
Student ID number: 1
The quiz grades are: 8 and 7
The midterm and final grades are: 78 and 89
The average of the scores is: 82.75
The grade that you recieved was: B

Student ID number: 2
The quiz grades are: 9 and 8
The midterm and final grades are: 67 and 89
The average of the scores is: 82.5
The grade that you recieved was: B

Student ID number: 3
The quiz grades are: 7 and 8
The midterm and final grades are: 78 and 98
The average of the scores is: 87.25
The grade that you recieved was: B

Student ID number: 4
The quiz grades are: 7 and 8
The midterm and final grades are: 67 and 78
The average of the scores is: 74.5
The grade that you recieved was: C

Student ID number: 5
The quiz grades are: 5 and 10
The midterm and final grades are: 78 and 87
The average of the scores is: 81.75
The grade that you recieved was: B
*/

/* Algorithm of Exercise1
The program uses a class named StudentRecord to hold all member variables and make it private.
it privates the member variables that will be used as arguments from the user.
member functions will take in the data from the arguments and use the data to calculate the scores
of both the quizes, midterm, and final all together as an average for that student ID.
The first member function studentData will get input data from the user and place into respective
member variables to hold the data for that student ID. The next member function calculateGrade will
calculate the scores and average them. With the average, it will then select the letter grade for
the respective average. The final member function studentResult will output the data for the user
and output the quiz scores, midterm, final, average, and final letter grade.
*/


//Exercise 2-----------------------------------------------------------------------------------------
/*class Exercise2 {

#include<iostream>

using namespace std;

class CounterType {
public:
    CounterType();
    void setCounter(int);
    void increment();
    void decrement();
    int getCounter();
    void displayCounter();

private:
    int counter;
};

CounterType::CounterType() {
    counter = 0;
}

void CounterType::setCounter(int count) {
    counter = count;
}

void CounterType::increment() {
    counter = counter + 1;
}

void CounterType::decrement() {
    if (counter < 1) {
        cout << "The counter value is negative." << endl;
        system("pause");
        exit(1);
    }
    counter = counter - 1;
}

int CounterType::getCounter() {
    return counter;
}

void CounterType::displayCounter() {
    cout << "Counter: " << getCounter();
}

int main() {
    CounterType counter1;
    int input;

    cout << "Please enter the initial value of the counter: ";
    cin >> input;

    if (input < 1) {
        cout << "The counter value cannot be 0 or negative." << endl;
        system("pause");
        exit(1);
    }

    counter1.setCounter(input);
    counter1.increment();
    cout << "The value of your input after the increment.\n";

    counter1.displayCounter();
    counter1.decrement();
    cout << "\nThe value of your input after the decrement.\n";

    counter1.displayCounter();
    cout << endl;

    system("pause");
    return 0;
}
};
*/

/* Output for Exercise 2
Please enter the initial value of the counter: 6
The value of your input after the increment.
Counter: 7
The value of your input after the decrement.
Counter: 6
Press any key to continue . . .
------------------------------------------------- output if the input is 0 or less
Please enter the initial value of the counter: 0
The counter value cannot be 0 or negative.
Press any key to continue . . .
*/

/* Algorithm for Exercise 2
The CounterType class will contain the default contstructor CounterType which holds member functions
setCounter, increment, decrement, displayCounter. The member variables in CounterType are private.
CounterType contstructor will set the counter to 0 before user input. setCounter will take an input
and set the counter variable to the user input. The increment member function will increment the
given user input by 1. The decrement member function will take the counter variable value and
decrement the number by 1. The displayCounter function will return and output the current
counter value. Within the main function, there is a check for a user input that is 0 or less than 0
as per specified by the problem.
*/

int main()
{
    int selection, a, b, c;


    cout << "Which Program would you like to run?\n";
    cout << "Ex 5.1: Enter 1\n";
    cout << "Ex 5.2: Enter 2\n";
    cout << "What is your selection? ";
    cin >> selection;
    cout << " " << endl;

    //if (selection == 1) {
    //    cout << " " << endl;
    //    Exercise1 charinput;
    //    charinput.studentrecord();
    //}

    //if (selection == 2) {
    //    cout << " " << endl;
    //    Exercise2 intinput;
    //    intinput.labinput2();
    //}

    return 0;

}

