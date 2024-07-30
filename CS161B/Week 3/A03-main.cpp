/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A03 - Grades & Scores - Parallel Array Program
# Date:             1/30/24
# Description:      This program uses a user’s input of their grades 
#                   ( on a 0-4 scale) and shows the letter grade in a list next
#                   to the score upon output. There will also be a list 
#                   printed that shows the user the scores in ascending order, 
#                   and another line that shows the median score.
# Input:            * scores (double) - user can input scores in 0.0 format
# Output:           * grade(s) (char) - calculated by the user input for scores 
#                   variable (with many conditions)
#                   * count (integer) - used to count grades and use to display 
#                   lists for user and median 
#                   * medianScore (double) - used to store and display the 
#                   median score of all scores
# Sources:          Zybooks Chapter 11, Ms. Sengupta's Notes
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void welcome();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grade[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grade[], int count);
double median(double scores[], int count);

// main function
//     Steps I need to take here:
//       1. Welcome Message
//       2. Ask user for inputs of scores (double)
//       3. Validate those double inputs (error validation)
//       4. Then Calculate the letter grade
//       5. Fill another parallel aray
//       6. Print the two arrays as output
//          a. Sort the arrays by score
//          b. Calculate the median score
//          c. Output sorted and median in main()
int main() {
  // declare constant variable
  const int MAX_VALUES = 20;
  // declare other variables
  double scores[MAX_VALUES];
  char grades[MAX_VALUES];
  int count = 0;
  double medianScore;


  // Calling the functions
  welcome();
  readScores(scores, count);
  calcGrade(scores, grades, count);

  cout << "\nYour stats are as below: \n";
  printList(scores, grades, count);

  sort(scores, grades, count);

  cout << "\nThe list sorted by scores in ascending order";
  printList(scores, grades, count);

  medianScore = median(scores, count);
  
  cout << fixed << setprecision(2);
  cout << "\nThe median score is " << medianScore << "\n\n";

  cout << "Thank you for using my Parallel Arrays program!!\n";

  return 0;
}
// ---- FUNCTION DEFINITIONS BELOW ------
  //Name:   welcome()
  //Desc:   This function displays the welcome
  //        message
  //input:  None  
  //output: A welcome message (string)
  //return: None
  void welcome(){
  cout << "Welcome to my Parallel Arrays program!\n";
  cout << "Please enter the list of scores (-1 to end input:)\n"
    << "Valid scores are between 0 and 4 inclusive.\n";
};


//Name:   readScores(double scores[], int &count)
//Desc:   This function will read the count and scores (0-4 inclusive).
//        A "-1" indicates the end of the input, and is not stored in the array. Use an              appropriate loop! See example code: https://replit.com/@GDIyer/Sentinel-loop-              for-Array#main.cpp 
//input:  None
//output: Maybe error message
//return: 
// void readScores(double scores[], int &count) {
//   double score;
  
//   while (count < 20) {
//     // cout << ">> ";
//     if (!(cin >> score)) {
//       cout << "Invalid score! Please try again!!\n" << ">> ";
//       cin.clear();
//       cin.ignore(100, '\n');
//     } else {
//       if (score == -1) {
//         scores[count++] = score;
//         return; // Exit the function if -1 is encountered
//       } else if (score >= 0 && score <= 4) {
//         scores[count++] = score;
//       } else {
//         cout << "Invalid score! Please try again!!\n" << ">> ";
//       }
//     }
//   }
// }
void readScores(double scores[], int &count) {
    double score;

    cout << ">> ";
    while (count < 20) {
        if (!(cin >> score) || (score != -1 && (score < 0 || score > 4))) {
            cout << "Invalid score! Please try again!!\n>> "
              << endl;
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            if (score == -1) {
                scores[count++] = score;
                return; // Exit the function if -1 is encountered
            } else {
                scores[count++] = score;
            }
        }
    }
}




//Name:   readDouble(string prompt, double &num)
//Desc:   This function reads a double, validates and returns it
//input:  None
//output: Maybe error message
//return: FIX ME FIX ME FIX ME
void readDouble(string prompt, double &num) {
// ******* Catch all invalid data here such as characters, 
//      negative numbers other than -1, etc
  cout << prompt;

  while (!(cin >> num) || num < -1 || num > 4) {
    cout <<"Invalid input. Please enter a valid number: ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> num;
  }
  cin.ignore(10, '\n');
}





//Name:   calcGradedouble scores[], char grade[], int count)
//Desc:   This function
//input:  None
//output: 
//return: FIX ME FIX ME FIX ME
void calcGrade(double scores[], char grade[], int count) {
  for (int i = 0; i < count; i++) {
    if (scores[i] > 3.3 && scores[i]<= 4.0) {
      grade[i] = 'A';
    } else if (scores[i] > 2.7 && scores[i] <= 3.3) {
      grade[i] = 'B';
    } else if (scores[i] > 1.9 && scores[i] <= 2.7) {
      grade[i] = 'C';
    } else if (scores[i] > 1.1 && scores[i] <= 1.9) {
      grade[i] = 'D';
    } else if (scores[i] > 0.0 && scores[i] <= 1.1) {
      grade[i] = 'F';
    }
  }
}




//Name:   printList(double scores[], char grades[], int count);
//Desc:   This function prints the results of the grades input 
//input:  scores, grades, count
//output: string showing all of the grades, etc
//return: FIX ME FIX ME FIX ME
void printList(double scores[], char grades[], int count) {
  int i;
  for(i = 0; i < count; i++)
    {
      cout << fixed << setprecision(1) << scores[i] << " "
        << grades[i] << endl;
    }
}




//Name:   sort(double scores[], char grade[], int count);
//Desc:   This function 
//input:  None
//output: 
//return: FIX ME FIX ME FIX ME
void sort(double scores[], char grade[], int count){
  for (int i = 0; i < count - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < count; j++) {
      if (scores[j] < scores[minIndex]) {
        minIndex = j;
      }
    }
    // Swap the scores
    double tempScore = scores[minIndex];
    scores[minIndex] = scores[i];
    scores[i] = tempScore;

    // Swap grades
    char tempGrade = grade[minIndex];
    grade[minIndex] = grade[i];
    grade[i] = tempGrade;
  }
}





//Name:    median(double scores[], int count);
//Desc:   This function 
//input:  None
//output: 
//return: FIX ME FIX ME FIX ME
double median(double scores[], int count) {
  if (count % 2 == 1) {
    return scores[count / 2];
  } else {
    int mid = count / 2;
    return (scores[mid - 1] + scores[mid]) / 2.0;
  }
}
