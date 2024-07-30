/****************************************************************
# Author:           Gina Ferguson
# Assignment:       A09 Grade Calculator part 2, using pass by reference functions
# Date:             November 17, 2023 (Resubmitted/updated on Dec. 8, 2023)
# Description:      This program is designed to calculate a final
                    score of the letter grade for anyone in CS161A.
                    This calculation will include scores from
                    assignments and exams using weighted grade.
# Input:            coin (integer), choice (string), 
                    quantity (integer)
# Output:           balance (double), total (double)
# Sources:          Assignment 7 specifications & Zybooks     
#****************************************************************/

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
void ReadScore(const string& prompt, double &num);
double AssignAverage(int numAssigns);
void GetInput(double &midtermScore, double &finalExamScore);
double CalcFinalScore(double assignAvg, double midterm, double finalExamScore);
void CalcLetterGrade(double finalScore, char &letter);

// MAIN
int main() {
    WelcomeMessage();

    int numAssigns = ReadInt("Enter the number of assignments (0 to 10): ");
    double assignAvg = AssignAverage(numAssigns);

    cout << endl << endl;
  
    double midtermScore, finalExamScore;
    GetInput(midtermScore, finalExamScore);

    cout << endl << endl;

    double finalScore = CalcFinalScore(assignAvg, midtermScore, finalExamScore);
    char letterGrade;
    CalcLetterGrade(finalScore, letterGrade);

    cout << fixed << setprecision(1);
    cout << "Your Final Numeric Score is " << finalScore << endl;
    cout << "Your Final Grade is " << letterGrade << endl;
    cout << "\nThank you for using my Grade Calculator!\n";
    return 0;
}

// my function defs
void WelcomeMessage() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your" 
      "\nFinal Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4.\n\n" << endl;
}

int ReadInt(const string& prompt) {
    int input;
    do {
        cout << prompt;
        cin >> input;
        if (input < 0 || input > 10 || !cin) {
            cout << "Illegal Value! Please try again!!\n\n";
            cin.clear();
            cin.ignore(10000, '\n'); // Clear the input buffer
        }
    } while (input < 0 || input > 10 || !cin);
    return input;
}

void ReadScore(const string& prompt, double &num) {
    do {
        cout << prompt;
        cin >> num;
        if (num < 0 || num > 4 || !cin) {
            cout << "Illegal Score! Please try again!" << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // Clear the input buffer
        }
    } while (num < 0 || num > 4 || !cin);
}

double AssignAverage(int numAssigns) {
    double totalScore = 0.0;
    for (int i = 0; i < numAssigns; ++i) {
        double score;
        ReadScore("Enter score " + to_string(i+1) + ": ", score);
        totalScore += score;
    }
    return numAssigns > 0 ? totalScore / numAssigns : 0.0;
}

void GetInput(double &midtermScore, double &finalExamScore){
  ReadScore("Enter your midterm exam score: ", midtermScore);
  ReadScore("Enter your final exam score: ", finalExamScore);
}

double CalcFinalScore(double assignAvg, double midtermScore, 
double finalExamScore) {
    return (assignAvg * ASSIGNMENT_WEIGHT) + (midtermScore * 
      EXAM_WEIGHT) + (finalExamScore * EXAM_WEIGHT);
}

void CalcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3) letter = 'A';
    else if (finalScore >= 2.8) letter = 'B';
    else if (finalScore >= 2.0) letter = 'C';
    else if (finalScore >= 1.2) letter = 'D';
    else letter = 'F';
}