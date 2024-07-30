/*
# *****************************************************************************
# Author:           Gina Ferguson
# Assignment:       Midterm Exam
# Date:             Thursday, February 8, 2024
# Description:      This program entails a queue of 5 numbers in an array using a FIFO structure.  The front of the queue starts with just 3 numbers, and as we add a number to the rear, one-at-a-time, the values in the array shift toward the front of the queue.
# Input:            option (char): one character that stores user choice (+, -, p, or q), val (int): represents the value to move throughout the queue, queue[]: array that stores the queue data structure w/ a MAX size of 5
# Output:           queue[i] (int): this stores the index of the queue in the printQueue()
# Sources:          Midterm Exam Practice, Zybooks chapters
#*****************************************************************************
*/
#include <iostream>

using namespace std;

int enqueue(int queue[], int &size, int val);
int dequeue(int queue[], int &size, int &val);
void printQueue(int queue[], int size);

const int MAX = 3; // maximum size of queue

//Name:   main()
//Desc:   This function runs the main program
//input:  val (int) - represents the value to move through the queue
//output: queue[] - array that stores the queue data structure
//return: 0
int main() {
  int queue[MAX] = {0};
  int size = 0;
  int val = 0;
  int tempResult = 0;
  char choice = ' ';
  cout << "Welcome to the FIFO Queue Program!\n\n";
   do {
     cout << "\nEnter option: ";
     cin >> choice;
     if (choice == '+') {
       cout << "Integer: ";
       cin >> val;
       if (enqueue(queue, size, val) == 0) {
         printQueue(queue, size);
       }
       else {
         cout << "Error: Queue overflow!\n";
         printQueue(queue, size);
       }
     }
     else if (choice == '-') {
       cout << "Integer: ";
       cin >> val;
       tempResult = dequeue(queue, size, val);
       if (tempResult == 0) {
         printQueue(queue, size);
       }
       else if (tempResult == 1) {
         cout << "Queue Empty.\n\n";
       }
       else {
         cout << val << " is not in the queue.\n";
         printQueue(queue, size);
       }
     }
     else if (choice == 'p') {
       printQueue(queue, size);
     }
     else if (choice == 'q') {
       cout << "\nGoodbye!\n\n";
     }
     else {
       cout << "Invalid option.\n\n";
     }
  } while (choice != 'q');
  return 0;
}

//Name:   enqueue()
//Desc:   This functions inserts a value into the rear of the queue
//input:  None
//output: None - the function is sent to main for calculating
//return: string name
int enqueue(int queue[], int &size, int val){

  if (size < MAX) {
    queue[size] = val;
    size++;
    return 0;
  }
  else {
    return 1;
  }
}

//Name:   dequeue()
//Desc:   This function removes a value from the front of the queue, if the 
//          integer is in the queue, all integers before are also removed and
//          shifted to the front of the queue
//input:  None
//output: queue[] sent to main
//return: 1 or 0
int dequeue(int queue[], int &size, int &val){
  int index = -1;
  int i = 0;

  if (size > 0) {
    for (i = size - 1; i >= 0; i--) { // loop from the rear to the front
      if (queue[i] == val) {
        index = i;
        break; // need to exit the loop here
      }
    }
    if (index != -1) {
      for (i = index; i < size - 1; i++) {
        queue[i] = queue[i+1];
      }
      queue[size-1] = 0;
      size--;
      return 0;
    }
    else {
      return 1;
    }
  }
  else {
    return 1;
  }
}

//Name:   printQueue()
//Desc:   This function prints the queue based on the index and size
//input:  None
//output: printQueue is sent to main 
//return: none
void printQueue(int queue[], int size){
    int i = 0;
    cout << "[";
    for (i = 0; i < size; i++){
        cout << queue[i];

        if (i != size - 1)
            cout << ", " ;
    }
    cout << "]" << endl;
}
