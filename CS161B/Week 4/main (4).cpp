// NOTE: This template is to be used for partner practice ONLY! You must
// use the required Algorithmic Design Document for all Assignments.
/******************************************************************************
# Author:           Thien, Idris, Gina, & Josh (Group 2)
# Lab:              Discussion #4
# Date:             February 2, 2024
# Description:      The program prompts the user to input a count and a list 
#                   of integers, then performs a right shift on the array 
#                   elements based on a specified position. Finally, it outputs
#                   the modified array after the shifting process.
# Input:            count (int): used to store user input for array for # of int
#                   list (int array: used to store list of integers by user
#                   pos (int): represents the position from which the array 
#                              elements will be shifted
#                   Validation(int &num): takes integer and reads for the count
#                                        and makes sure of any non-integers
#                   readList(int list[], int &count): takes array and reads list
# Output:           ShiftingArrayToFront(int list[], int count, int pos): takes
#                                an integer array and shifts the array right
#                   PrintArray(int list[], int count): takes the array and prints
# Sources:          Zybooks chapter 11, Ms. Sengupta's notes
#******************************************************************************/

#include <iostream>

using namespace std;

const int MAX = 100;

void Validation(int &num);
void readList(int list[], int &count);
void ShiftingArrayToFront(int list[], int count, int pos);
void PrintArray(int list[], int count);


int main() {
  int list[MAX] = {0};
  int count = 0;
  int pos = 0;

  cout << "How many numbers do you want to enter? ";
  // Validates data to check for non-negative integers
  Validation(count);
  
  
  cout << "Enter numbers of integers: ";
  readList(list, count);

  cout << "Enter position to shift from: ";
  cin >> pos;
  ShiftingArrayToFront(list, count, pos);

  cout << "Your list after shifting: ";
  cout<< endl;
  PrintArray(list, count);
  
  return 0;
} 

//Name:   Validation(int &num)
//Desc:   This function reads a number from the user that will be the 
//        number of items in the list, and validates the data
//input:  num (integer) - number that the user inputs to validate
//output: error message as a string
//return: None
void Validation(int &num)
{
  cin >> num;
  while (!cin || num < 0) 
    {
      cout << "Invalid input! Please try again!!" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> num;
    }
  cin.ignore(100, '\n');
}

//Name:   readList(int list[], int &count)
//Desc:   This function reads each individual number from the list and iterates 
//        through them to store the list.
//input:  i (integer) - index for the for loop of the array
//        (integer) list[] - array that is stored from input
//output: none
//return: None
void readList(int list[], int &count) {
  int i = 0;

  
  for (i = 0; i < count; ++i)
    {
      cin >> list[i];
    }
  cin.ignore(100, '\n');
}

//Name:   void ShiftingArrayToFront(int list[], int count, int pos)
//Desc:   This function shifts the array element to the right
//input:  temp (integer) - stores the temporary value for the shift
//        i (integer) - represents the index of the loop/array
//output: list[]: list from user input
//return: None
void ShiftingArrayToFront(int list[], int count, int pos) {
  int temp = 0;
  int i = 0;
  int j = 0;

  for (i = 0; i < count - pos; ++i) {//crontols how many times to shift count - pos 
    temp = list[count - 1]; //stores the last element in temp

    for (j = count - 1; j > 0; --j) { //shifts the array to the right
      list[j] = list[j - 1];//copies the element to the right
    }

    list[0] = temp;//puts the last element back to the first element
  }
}

//Name:   void PrintArray(int num)
//Desc:   This function prints the array with a for loop
//input:  i (integer) - index for the for loop / array
//output: error message as a string
//return: None
void PrintArray(int list[], int count) {
  int i = 0;

  for (i = 0; i < count; ++i) {
    cout << list[i] << " ";
  }
  cout << endl;
}

