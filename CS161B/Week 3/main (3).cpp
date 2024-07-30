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
#                   * scores[MAX_VALUES] (double) - an array for scores
#                   * &count (integer) - represents # of elements in the arrays
#                                        that updates as scores are read
# Output:           * grades (char) - calculated by the user input for scores 
#                                       variable (with many conditions)
#                   * grades[MAX_VALUES] - array storing grades that correspond
#                                          with scores
#                   * count (integer) - used to count grades and use to display 
#                                       lists for user and median 
#                   * medianScore (double) - used to store and display the 
#                                            median score of all scores
# Sources:          Zybooks Chapter 11, Ms. Sengupta's Notes, Zain math tutor,
#                      and Ms. Sengupta's suggestion in email for readScores()
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

const int MAX_VALUES = 20;

int main() {
   double scores[MAX_VALUES];
   char grades[MAX_VALUES];
   int count = 0;
   double medianScore = 0.0;

   welcome();
   readScores(scores, count);
   calcGrade(scores, grades, count);

   cout << "\nYour stats are as below: \n\n";
   cout << "\nThe list of scores and their grades are:\n";
  
   printList(scores, grades, count);
   sort(scores, grades, count);
   printList(scores, grades, count);

   medianScore = median(scores, count);
  
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
};

//Name:   readScores()
//Desc:   This function prompts user to input scores, and utilizes the
//        readDouble() function to validate the data
//input:  None  
//output: A user prompt (string)
//return: if score/input = -1, return to the main function, used per tutor Zain
void readScores(double scores[], int &count) {
   double score = 0.0;
  
   cout << "Please enter the list of scores (-1 to end input:)\n"
    << "Valid scores are between 0 and 4 inclusive.\n";

   // Read the first score
   readDouble(">> ", score);

   while (score != -1 && count < MAX_VALUES) {
      // Store the current score
      scores[count++] = score;

      // Check if the array is full
      if (count < MAX_VALUES) {
        // Read the next score
        readDouble(">> ", score);
        
      } 
      else {
         cout << "List is now full!" << endl;
      }
   }
}

//Name:   readDouble(string prompt, double &num)
//Desc:   This function reads a double, validates and returns it
//input:  num (double) - stores user input that is being validated
//output: Maybe error message
//return: None
void readDouble(string prompt, double &num) {
   cout << prompt;
   cin >> num;
   while (!cin || (num < 0 && num != -1) || num > 4) {
     cout <<"Invalid score! Please try again!!\n" << ">> ";
     cin.clear();
     cin.ignore(100, '\n');
     cin >> num;
   }
   cin.ignore(10, '\n');
}



//Name:   calcGradedouble scores[], char grade[], int count)
//Desc:   This function matches the score intevals with the corresponding
//        letter
//        grades
//input:  double scores[] - an array representing scores
//        char grade[] - an array representing grades
//        int count - an integer representing the number of elements
//                    in the arrays
//output: None explicit
//return: None
void calcGrade(double scores[], char grade[], int count) {
   int i = 0;
   for (i = 0; i < count; i++) {
      if (scores[i] > 3.3 && scores[i]<= 4.0) {
         grade[i] = 'A';
      } 
      else if (scores[i] > 2.7 && scores[i] <= 3.3) {
         grade[i] = 'B';
      } 
      else if (scores[i] > 1.9 && scores[i] <= 2.7) {
         grade[i] = 'C';
      } 
      else if (scores[i] > 1.1 && scores[i] <= 1.9) {
         grade[i] = 'D';
      } 
      else if (scores[i] > 0.0 && scores[i] <= 1.1) {
         grade[i] = 'F';
      }
   }
}

//Name:   printList(double scores[], char grades[], int count);
//Desc:   This function prints the results of the grades input 
//input:  double scores[] - an array representing scores
//        char grades[] - an array representing corresponding grades
//        int count - an integer representing number of elements in array
//output: No explicit outputs
//return: None
void printList(double scores[], char grades[], int count) {
   int i = 0;
   for(i = 0; i < count; i++) {
      cout << fixed << setprecision(1) << scores[i] << " "
        << grades[i] << endl;
    }
    cout << endl;
}

//Name:   sort(double scores[], char grade[], int count);
//Desc:   This function sorts the grades first in ascending order
//        by using index references for swapping scores and grades that match
//input:  double scores[] - an array that represents scores
//        char grade[] - an array that represents corresponding grades
//        int count - an integer representing the number of elements in the
//                    arrays
//output: scores, grade could be considered implicit outputs, but none explicit
//return: None
void sort(double scores[], char grade[], int count){
   int minIndex = 0;
   double tempScore = 0.0;
   char tempGrade = ' '; // Style guide suggests this initialization
   int i = 0;
   int j = 0;
  
   cout << "The list sorted by scores in ascending order:\n";
   for (i = 0; i < count - 1; i++) {
      minIndex = i;
      for (j = i + 1; j < count; j++) {
         if (scores[j] < scores[minIndex]) {
            minIndex = j;
          }
      }
     
    if (minIndex != i) {
    // Swap the scores
       tempScore = scores[minIndex];
       scores[minIndex] = scores[i];
       scores[i] = tempScore;

    // Swap grades
       tempGrade = grade[minIndex];
       grade[minIndex] = grade[i];
       grade[i] = tempGrade;
    }
  }
}

//Name:   median(double scores[], int count);
//Desc:   This function calculates the median score in double form
//input:  double scores[] - an array that represents score values
//        int count - an integer variable that represents number of scores
//                    in the input array
//output: None directly
//return: Returns the median score, per tutor Zain
double median(double scores[], int count) {
   int mid = 0;
   double medianScore = 0.0;
  
   if (count % 2 == 1) {
      return scores[count / 2];
    } else {
       mid = count / 2;
      return (scores[mid - 1] + scores[mid]) / 2.0;
    }
   cout << fixed << setprecision(2);
   cout << "\nThe median score is " << medianScore << "\n\n";
}
