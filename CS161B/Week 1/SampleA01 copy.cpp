/******************************************************************************
# Author:           Gayathri Iyer
# Assignment:       A01 Sample (CS161B)
# Date:             April 3, 2022
# Description:      This program will present a menu to the user to calculate the total calories burned based on the type of workout.
This calculation uses the MET value (Metabolic Equivalent of Task) of each activity. We multiply the MET value with the person\'s body weight in kilograms. Then we multiply this with 0.0175 and the duration in minutes to calculate the calories burned in kcals.
This program has been modularized using Pass by Value functions.
# Input:            (What the program asks for, and data type, e.g., string)
# Output:           (Summary of messages displayed by the program)
# Sources:          Assignment 1 specifications
#                   and any other substantial aids, like web pages or students
#                   who helped you.
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//constants for MET values and MET_FACTOR
const double CALS_FACTOR = 0.0175;
const double MET_STEP = 6.6;
const double MET_BOOT = 10.1;
const double MET_PILATES = 3.7;
const double MET_TAI = 3.3;
const double MET_ZUMBA = 8.8;

//function prototypes
void welcome();
void displayMenu();
int readOption();
int readInt(string prompt);
double exeOption(int userChoice, int weight, int minutes);
void getInput(int &weight, int &minutes);
int calcCalories(double metFactor, int weight, int minutes);

//main function
int main()
{
  //declare variables for input
  int userChoice = 0;
  //declare variables for all output and support structure
  int totalCals = 0, weight = 0, minutes = 0, totalMins = 0;
  double metFactor = 0;
  //call welcome function
  welcome();
  // while loop for menu
  displayMenu();
  userChoice = readOption();
  while (userChoice != 6)
  {
    getInput(weight, minutes);
    totalCals += exeOption(userChoice, weight, minutes);
    totalMins += minutes;
    displayMenu();
    userChoice = readOption();
  }

  //display overall Summary for all activities
  cout << "\nYour Workout Summary:" << endl;
  cout << "Total minutes worked out = " << totalMins << endl;
  cout << "Total Calories burned = " << totalCals << " kcals" << endl;
  //print Thank you message
  cout << "Thank you for using my program!" << endl;

  //end program
  return 0;
}

//Name: welcome()
//Desc: This function displays the welcome message
//input: None
//output: None
//return: None
void welcome()
{
  cout << "Welcome to your Workout Summary Program!" << endl;  cout << "MET Values for these activities:" << endl;
  cout << "Step Aerobics = 6.6" << endl;
  cout << "Bootcamp = 10.1" << endl;
  cout << "Pilates = 3.7" << endl;
  cout << "Tai Chi = 3.3" << endl;
  cout << "Zumba = 8.8" << endl;
  cout << endl << endl;
}

//Name: displayMenu()
//Desc: This function displays the menu to the user
//input: None
//output: None
//return: None
void displayMenu()
{
  cout << "Choose a Workout option from below:" << endl;
  cout << "1. Step Aerobics" << endl;
  cout << "2. Bootcamp" << endl;
  cout << "3. Pilates" << endl;
  cout << "4. Tai Chi" << endl;
  cout << "5. Zumba" << endl;
  cout << "6. Quit" << endl;
}

//Name:     readOption()
//Desc:     This function reads the userChoice and returns it
//input:    None
//output:   None
//return:   int userChoice
int readOption()
{
  //get user input from user first
  //call readInt to do data validation
  int userChoice = readInt(">>");
  //data validation loop
  while(userChoice < 1 || userChoice > 6)
  {
    cout << "Invalid Choice! Please enter a number between 1 and 6." << endl;
    userChoice = readInt(">>");    
  }
  return userChoice;
}

//Name:   readInt(string prompt)
//Desc:   This function reads an int, validates and returns it
//input:  None
//output: Maybe error message
//return: int tempVar
int readInt(string prompt)
{
  int tempVar = 0;
  cout << prompt;
  cin >> tempVar;
  while(!cin)
  {
    cout << "Invalid input! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> tempVar;
  }
  cin.ignore(10, '\n');
  return tempVar;
}

//Name: exeOption(int userChoice)
//Desc: This function takes the userChoice and reads the weight and minutes exercised from the user. Then it sets the metFactor based on the the activity. Then it calls the calcCalories function to calculate the calories burned. And returns the totalCals to main()
//input: int userChoice, weight and minutes by reference
//output: Maybe error message
//return: double metFactor
double exeOption(int userChoice, int weight, int minutes)
{
  int totalCals = 0;
  double metFactor = 0;
  //check userChoice.
  switch(userChoice)
  {
    case 1:
      metFactor = MET_STEP;
      break;
    case 2:
      metFactor = MET_BOOT;
      break;
    case 3:
      metFactor = MET_PILATES;
      break;
    case 4:
      metFactor = MET_TAI;
      break;
    case 5:
      metFactor = MET_ZUMBA;
      break;
    case 6:
      minutes = 0;
      return 0;
    default:
      cout << "Invalid choice! Please try again!" << endl;
  }
  //return metFactor
  totalCals = calcCalories(metFactor, weight, minutes);
  return totalCals;
}

//Name: getInput(int &weight, int &minutes)
//Desc: Reads weight and minutes from the user
//input: int weight and minutes by reference
//output: Maybe error message
//return: None
void getInput(int &weight, int &minutes)
{
  weight = readInt("Enter your weight in kilograms: ");
  while(weight < 0)
    {
      cout << "Weight must be a positive number!" << endl;
      weight = readInt("Enter your weight in kilograms: ");
    }
  minutes = readInt("Enter number of minutes for this workout: ");
  while(minutes < 0)
    {
      cout << "Minutes must be a positive number!" << endl;
      minutes = readInt("Enter number of minutes for this workout: ");
    }
}
//Name: calcCalories(metFator, weight, minutes, &totalMins)
//Desc: This function takes the (metFator, weight, minutes, &totalMins) and calculates the calories burned. And returns the totalCals to exeOption
//input: metFator, weight, minutes, &totalMins
//output: Summary for that activity
//return: int totalCals
int calcCalories(double metFactor, int weight, int minutes)
{
  int totalCals = 0;
  //calculate calories burned for this activity
  //use the ceil function to round it up and store in an integer
  //otherwise the calories will be truncated and not rounded.
  int calsBurned = ceil(metFactor * CALS_FACTOR  * weight * minutes);
  totalCals += calsBurned;
  //print current activity Summary
  cout << "\nMET value for this activity = " << metFactor << endl;
  cout << "Minutes worked out for this activity = " << minutes << endl;
  cout << "Calories burned in this activity = " << calsBurned << " kcals\n" << endl;
  return totalCals;
}
