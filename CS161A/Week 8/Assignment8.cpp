#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constants
const double ASSIGNMENT_WEIGHT = 0.60;
const double EXAM_WEIGHT = 0.20; // mid-term & final exam have the same weight

// Function definitions
void WelcomeMessage();
int ReadInt(const string& prompt);
double ReadScore(const string& prompt);
double AssignAverage(int numAssigns);
double CalcFinalScore(double assignAvg, double midterm, double finalExam);
char CalcLetterGrade(double finalScore);

// MAIN
int main() {
    WelcomeMessage();
    cout << endl << endl;
  
    int numAssigns = ReadInt("Enter the number of assignments (0 to 10): ");
    cout << endl << endl;
    double assignAvg = AssignAverage(numAssigns);
    cout << endl << endl;
    double midterm = ReadScore("Enter your midterm exam score: ");
    cout << endl << endl;
    double finalExam = ReadScore("Enter your final exam score: ");
    cout << endl << endl;
    double finalScore = CalcFinalScore(assignAvg, midterm, finalExam);
    char letterGrade = CalcLetterGrade(finalScore);

    cout << fixed << setprecision(1);
    cout << "Your Final Numeric Score is " << finalScore << endl;
    cout << "Your Final Grade is " << letterGrade << endl;
    cout << "\nThank you for using my Grade Calculator!" << endl;
    return 0;
}

// Implement other functions here
void WelcomeMessage() {
    cout << "Welcome to the Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your" 
      "\nFinal Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int ReadInt(const string& prompt) {
    int input;
    do {
        cout << prompt;
        cin >> input;
        if (input < 0 || input > 10 || !cin) {
            cout << "Illegal Value! Please try again!!" << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // Clear the input buffer
        }
    } while (input < 0 || input > 10 || !cin);
    return input;
}

double ReadScore(const string& prompt) {
    double score;
    do {
        cout << prompt;
        cin >> score;
        if (score < 0 || score > 4 || !cin) {
            cout << "Illegal Score! Please try again!" << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // Clear the input buffer
        }
    } while (score < 0 || score > 4 || !cin);
    return score;
}

double AssignAverage(int numAssigns) {
    double totalScore = 0.0;
    for (int i = 0; i < numAssigns; ++i) {
        totalScore += ReadScore("Enter score for assignment " + to_string(i+1) + ": ");
    }
    return totalScore / numAssigns;
}

double CalcFinalScore(double assignAvg, double midterm, double finalExam) {
    return (assignAvg * ASSIGNMENT_WEIGHT) + (midterm * EXAM_WEIGHT) + (finalExam * EXAM_WEIGHT);
}

char CalcLetterGrade(double finalScore) {
    if (finalScore >= 3.3) return 'A';
    else if (finalScore >= 2.8) return 'B';
    else if (finalScore >= 2.0) return 'C';
    else if (finalScore >= 1.2) return 'D';
    else return 'F';
}