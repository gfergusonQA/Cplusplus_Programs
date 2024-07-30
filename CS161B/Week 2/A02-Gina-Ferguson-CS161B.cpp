/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Assignment 2
# Date:             1/18/2024
# Description:      This program asks a user for their first name, last name,
#                   student ID, and if the assignment is late so that a file
#                   name can be encoded, created, and printed out for the
#                   user to see.
# Input:            option [char] - used in readOption function to store user’s                           choice from menu options
                    lateInput [char] - used in readInput function to store user’s                          choice if assignment was late
                    hour [integer] - used in readTime function to store what hour                          of time the user is inputting
                    min [integer] - used in readtime function to store the                                 minutes of the time user is inputting

# Output:           fileName [char array] - outputs fileName into the encode()    #                       function where it gets encoded later
#                   fName [char array] - used to encode file name with 
#                       first name
#                   lName [char array] - used to encode file name with first name
#                   lateStamp [bool] - used to encode the file with status of 
#                       assignment late or not
# Sources:          Zybooks Chapter 10 Char Arrays
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.
// You don't need to include these three lines in your program!


#include <iostream>
#include <cctype> // tolower function
#include <cstring> // strncpy / strcat functions
using namespace std;

// Function Definitions:
void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag); 
void readInput(char parsedID[], char fileName[]); //*** OVERLOADED
void readTime(char strTime[]); // NEW for this level ***

int main() {
  // declare local variables
  char option;
  char fileName[50];
  // in a loop, call the functions and output the encoded file name
  // repeat the menu in the loop until the user chooses to quit
  // main() should only do the steps above!!!!!!! 

// Get user's last name, 
  // first name, 
  // if the assignment was late or not, 
  // their student ID
  // the file name
  // the time of submission
  welcome();

  do {
    displayMenu();
    readOption(option);

    switch (option) {
     case 'e':
     case 'E':
        cout << "This program will ask you a few questions and generate an encoded fileName based on your answers.\n" << endl;
        encode(fileName);
        cout << "\nYour encoded file name is: " << fileName << endl;
        break;
     case 'q':
     case 'Q':
        cout << "Thank you for using my filename generator!" << endl;
        break;
     default:
        cout << "Invalid option! Please try again!" << endl;
    }

  } while (option != 'q' && option != 'Q');

  return 0;
}

// function definitions:

void welcome(){
  cout << "Welcome to Gina's fileName encoding program!!\n\n";
}

void displayMenu() 
{
  cout << "\nPlease pick an option below:" << endl;
  cout << "(e)Encode a file name" << endl << "(q)quit" << endl
    << ">> ";
}


// Reads option through ref parameter, must do validation to make sure character is E/e or Q/q and nothing other than that. Use a while loop!!!!!!!
void readOption(char &option) {
  while(true) {
    cin >> option;
    cin.ignore();

    // convert to lower case
    option = tolower(option);

    if (option == 'e' || option == 'q') {
      break;
    } else {
      cout << "\nInvalid option! Please try again!!" << endl;
      displayMenu();
    }
  }
}


 // Declare appropriate local variables
      // Call the readInput() function to read student's names and lateFlag
      // Call the readInput() function to read Student ID and filename
      // Call the readTime() function to read the submitted time
          // ** NEW for this level **
      // File the encodeFileName array based on 6 pieces of info adding              // _underscores_ between
      // Start with the student's names, if assignment is late, put LATE in the filename and nothing otherwise, add the parsed studentID, add the time, without the colon, and then finally add the filename
// EXAMPLE: if late --- smith_sue_LATE_5587_1827_prog2.c
// EXAMPLE: not late -- smith_sue_5587_1824_prog2.c
  // Use strncpy() and strcat() functions
  // takes 1 char array
void encode(char encodeFileName[]) {
  char fName[50], lName[50], fileName[50], parsedID[5], strTime[5];
  bool lateStamp;

  readInput(fName, lName, lateStamp);
  readInput(parsedID, fileName);
  readTime(strTime);

  // convert first and last to lowercase letters
  for (int i = 0; fName[i] != '\0'; i++) {
    fName[i] = tolower(fName[i]);
  }

  for (int i = 0; lName[i] != '\0'; i++) {
    lName[i] = tolower(lName[i]);
  }

  // make the file name by directions
  strcpy(encodeFileName, lName); // 
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fName);

  // late stamp here
  if (lateStamp) {
    strcat(encodeFileName, "_LATE_");
  }

 // piecing together the names
  strcat(encodeFileName, "-");
  strcat(encodeFileName, parsedID);
  
  strcat(encodeFileName, "_");
  strcat(encodeFileName, strTime);
  strcat(encodeFileName, "_");
  strcat(encodeFileName, fileName);
}

//***OVERLOADED FUNCTION***
// Need to make sure all character data for the student's name is lowercase -write a function tolower
// if assignment was late, do validation for this (example y/Y or n/N)
void readInput(char fName[], char lName[], bool &lateFlag){
  cout << "\nEnter your last name: ";
  cin.getline(lName, 50);

  cout << "\nEnter your first name: ";
  cin.getline(fName, 50);

  char lateInput;
  cout << "\nWas your assignment Late (y/n)? ";
  cin >> lateInput;

  lateFlag = (tolower(lateInput) == 'y');
}

 // parsedID = 4 digit studentID that will be returned
 // fileName = for the file name of the assignment
 // the student ID is a local variable (char array). Use the strncpy() function to copy from \
      // position 7 til the end of the string.
void readInput(char parsedID[], char fileName[]) {
//*** OVERLOADED FUNCTION***
  cout << "\nEnter your Student-ID (format: 222-22-2222): ";
  cin.ignore(); // Ignore the new line character
  cin.getline(parsedID, 5, '-');
  cin.getline(parsedID + 5, 3, '-');
  cin.getline(parsedID + 8, 5);

  cout << "\nEnter the file name: ";
  cin.getline(fileName, 50);
}

// reads the time from the user as 2 integers and return one char array by reference (that is the strTime                     array)
// the time read from the use will be in military time (e.g. 18:24 for 6:24pm)
    // 2 integers: 1 for hour, and 1 for min
    // YOU MUST DO DATA VALIDATION for the numbers and the HH:MM format. Make sure the colon is used to separate the mins and hours
void readTime(char strTime[]){ // NEW for this level ***
  int hour;
  int min;

  while(true) {
    cout << "\nEnter the time submitted (military time - ex: 18:24 for 6:24pm): ";
    cin >> hour;

    if (cin.fail() || hour<0 || hour>23) {
      cin.clear(); //clear the flag asap
      cin.ignore(); //clear input buffer
      cout << "Invalid hour. Please enter a valid hour (0-23)." << endl;
    } else {
      break;
    }
  }

  while (true) {
    cin.ignore();
    cin >> min;

    if (cin.fail() || min < 0 || min > 59) {
      cin.clear();
      cin.ignore();
      cout << "Invalid minute. Please enter a valid minute (0-59)." << endl;
    } else {
      break;
    }
  }

  //format the time as HH:MM
  sprintf(strTime,"%02d%02d", hour, min);
}
