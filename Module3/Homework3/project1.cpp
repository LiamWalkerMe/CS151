/* project1.cpp - Dynamic Allocation of an Array
    Name: Liam Walker
    Module: 3
    Project: 1
    
    Problem Statement: Write a program which dynamically allocates an array 
    large enough to hold a user-defined number of quiz or test scores.  
    Once all scores are entered, the array should be passed to a function 
    that sorts them in ascending order using a sorting algorithm that you 
    write yourself.  Another function (again, one which you should write) 
    should be called that calculates the average score.  The program should 
    then display the sorted list of scores and the average with appropriate 
    headings. Using the first project as a starting point, modify the program 
    to allow the user to enter name-score pairs using a class that you define.
    For each student taking the quiz or test, the user should enter a string
    representing name of the student, followed by an integer representing the
    student's score.  The name and score for each student should be stored in
    an object of a class in the array.  (To keep things simple, this class can
    be defined in the same file as your  main  function.)  In the class, make
    your instance variables private, so you'll also need to supply getters and setters.

    Algorithm / Plan:
    1. Gather input from user on number of students and store score and name variables into Student Object
    2. Sort by gathering the score of the first object, compare to next object, and swap if second is lower. Repeat for whole array.
    3. Print out scores and names with proper formatting.

*/
#include <iostream>
#include <iomanip>
using namespace std;

class Student {
    private:
        string name;
        int score;

    public:
        //Default Constructor
        Student() {
            name = "";
            score = 0;
        }
        //Constructor
        Student(string n, int s) {
            name = n;
            score = s;
        }

        //Getters
        string getName() {
            return name;
        }

        int getScore() {
            return score;
        }

        //Setters
        void setName(string n) {
            name = n;
        }

        void setScore(int s) {
            score = s;
        }
};

void scoreSort(Student *ptr, int numStudents);
double scoreAverage(Student *ptr, int numStudents);

int main() {

    //Initialize variable to hold number of students
    int numStudents;

    
    //Gather number of students
    cout << "Please enter the number of students: ";
    cin >> numStudents;

    //Dynamically allocate an array to hold the scores of the students
    Student* arr = new Student[numStudents];
    Student *ptr = arr;

    //Loop through the number of students and gather name and score for each student
    for (int i = 0; i < numStudents; i++) {
        string name = "";
        int score = 0;

        cout << "Please enter student " << i + 1 << "'s name: ";
        cin >> name;

        cout << "Please enter " << name << "'s score: ";
        cin >> score;

        if(score < 0) {
            cout << "Invalid score. Please enter a score greater than or equal to 0." << endl;
            i--;
        } else {
            (ptr + i)->setName(name);
            (ptr + i)->setScore(score);
        }
    }
    
    
    //Sort the scores in ascending order
    scoreSort(ptr, numStudents);

    cout << endl <<  "Sorted Scores: " << endl;
    cout << "--------------" << endl;
    cout << setw(10) << left << "Name: ";
    cout << setw(10) << left << "Score: " << endl;


    //Display the sorted scores
    for (int i = 0; i < numStudents; i++) {
        cout << setw(10) << left << (ptr + i)->getName();
        cout << setw(10) << left << (ptr + i)->getScore() << endl;
    }

    //Calculate and display the average score
    cout << "--------------" << endl;
    cout << "Average: " << scoreAverage(ptr, numStudents) << endl << endl;

    delete[] arr;

    arr = nullptr;
    ptr = nullptr;

    return 0;
}



void scoreSort(Student *ptr, int numStudents) {

    //Sort the array in ascending order
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if ((ptr + j)->getScore() > (ptr + j + 1)->getScore()) {
                Student temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

}

double scoreAverage(Student *ptr, int numStudents) {
    int sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += (ptr + i)->getScore();
    }
    return (double)sum / numStudents;
} 