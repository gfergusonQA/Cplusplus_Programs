/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Midterm Exam Version A (CS161A)
# Date:             October 30, 2023
# Description:      This program is to output the winners of a Rock Collecting Competition. The program will prompt the user for 3 contestant names (strings), and the number of the rocks they collected (integers). There will be warnings for things such as rock amounts that are less than 0. Then, the program will determine the first, second, and third place winners. It will account for three way and two way ties. There will also be a section that calculates the average number of rocks collected (double with two decimal places).
# Sources:          Midterm A specifications, Zybooks, my notes from the quarter
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string playerOne;
  string playerTwo;
  string playerThree;
  int playerOneRocks = 0;
  int playerTwoRocks = 0;
  int playerThreeRocks = 0;
  string firstPlace;
  string secondPlace;
  string thirdPlace;
  double avgRocks = 0.00;
  const int NUM_PLAYERS = 3;

  cout << "Welcome to Gina's Rock Collector Championship!" << endl;

  // player1 contestant entry
  cout << "Enter player 1 name: " << endl;
  getline(cin, playerOne);
  cout << "How many rocks did " + playerOne + " collect? " << endl;
  cin >> playerOneRocks;
  if (playerOneRocks < 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
      playerOneRocks = 0;
  }
  cin.ignore();

  // player2 contestant entry
  cout << "Enter player 2 name: " << endl;
  getline(cin, playerTwo);
  cout << "How many rocks did " + playerTwo + " collect? " << endl;
  cin >>  playerTwoRocks;
  if (playerTwoRocks < 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
      playerTwoRocks = 0;
  }
  cin.ignore();

  // player3 contestant entry
  cout << "Enter player 3 name: " << endl;
  getline(cin, playerThree);
  cout << "How many rocks did " + playerThree + " collect? " << endl;
  cin >> playerThreeRocks;
  if (playerThreeRocks < 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
      playerThreeRocks = 0;
  }
  cin.ignore();

// determining the winner conditionals
  // if player 1 is > players 2 and 3, we set player 1 to firstPlace variable
  if ((playerOneRocks > playerTwoRocks) && (playerOneRocks > playerThreeRocks)) 
  {
    firstPlace = playerOne;
    // after player 1 takes 1st place, player 2 (if greater than 3) becomes 
    //2nd place
    if (playerTwoRocks > playerThreeRocks) {
      secondPlace = playerTwo;
      thirdPlace = playerThree;
    // or if player 3 is greater than player 2, player 3 becomes 2nd place
    } else if (playerThreeRocks > playerTwoRocks) {
      secondPlace = playerThree;
      thirdPlace = playerTwo;
    // Else, players 2 and 3 are tied
    } else {
      secondPlace = "It's a tie between " + playerTwo + " and " + playerThree + 
      "!";
      thirdPlace = "N/A (due to tie)";
    }
    
  // if player 2 is > players 1 and 3, we set player 2 to firstPlace variable
  } else if ((playerTwoRocks > playerOneRocks) && 
    (playerTwoRocks > playerThreeRocks)) {
    firstPlace = playerTwo;
    // if player 1 > player 3, we set player 1 to 2nd place
    if (playerOneRocks > playerThreeRocks) {
      secondPlace = playerOne;
      thirdPlace = playerThree;
    // if player 3 > player 1, we set player 3 to 2nd place
    } else if (playerThreeRocks > playerOneRocks) {
      secondPlace = playerThree;
      thirdPlace = playerOne;
    } else {
      secondPlace = "It's a tie between " + playerOne + " and " + playerThree 
      + "!";
      thirdPlace = "N/A (due to tie)";
    }

  // if player 3 is > players 1 and 2 we set player 3 to firstPlace variable
  } else if ((playerThreeRocks > playerOneRocks) && 
    (playerThreeRocks > playerTwoRocks)) {
    firstPlace = playerThree;
    if (playerOneRocks > playerTwoRocks) {
      secondPlace = playerOne;
      thirdPlace = playerTwo;
    } else if (playerTwoRocks > playerOneRocks) {
      secondPlace = playerTwo;
      thirdPlace = playerOne;
    } else {
      secondPlace = "It's a tie between " + playerOne + " and " + playerTwo 
      + "!";
      thirdPlace = "N/A (due to tie)";
    }
    
  // if player 1 = player 2, but greater than player 3, then players 1 & 2 
  //have a tie,and no 3rd place
  } else if (playerOneRocks == playerTwoRocks && 
  playerOneRocks > playerThreeRocks) {
    firstPlace = "It's a tie between " + playerOne + " and " + playerTwo + "!";
    secondPlace = playerThree;
    thirdPlace = "N/A (due to tie)";
    
  // if player 1 = player 3, but is greater than player 2, then players 1 & 3 
  //have a tie, and no 3rd place
  } else if (playerOneRocks == playerThreeRocks && 
  playerOneRocks > playerTwoRocks) {
    firstPlace = "It's a tie between: " + playerOne + " and " + playerThree 
    + "!";
    secondPlace = playerTwo;
    thirdPlace = "N/A (due to tie)";

  // if player 2 = player 3, but is greater than player 1, then players 2 & 3 
  //have a tie, and no 3rd place
  } else if (playerTwoRocks == playerThreeRocks && 
  playerTwoRocks > playerOneRocks) {
    firstPlace = "It's a tie between " + playerTwo + " and " + playerThree 
    + "!";
    secondPlace = playerOne;
    thirdPlace = "N/A (due to tie)";

  // else 3-way tie
  } else {
    firstPlace = "It's a three-way tie between " + playerOne + ", " + 
    playerTwo + ", and " + playerThree + "!";
    secondPlace = "N/A (due to tie)";
    thirdPlace = "N/A (due to tie)";
  }

  // Announcing the winners! :)
  cout << "First place: " << firstPlace << endl;
  cout << "Second place: " << secondPlace << endl;
  cout << "Third place: " << thirdPlace << endl;
  
  cout << setprecision(2) << fixed << showpoint;
  avgRocks = ((playerOneRocks + playerTwoRocks + playerThreeRocks)/NUM_PLAYERS);
  cout << "The average number of rocks collected by the top three players is " 
  << avgRocks <<" rocks!" << endl;

  cout << "Congratulations Rock Collectors!" << endl;
  
  return 0;
}