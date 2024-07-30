/* guess_game.cpp - Dona Hertel Nov 13, 2023
   CS161A - Week 8 - Example code 3
   Guess the number game.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // for rand() and srand() functions
#include <ctime> // for time() function

using namespace std;

const int BEG = 1;
const int END = 20;

const int MAX_GUESSES = 5;

int main() {
    int number = 0; // the number to guess
    int guess = 0; // the user's guess
    int range = END - BEG + 1; // used to get a range for the rand()
    int totalPlays = 0; // how many plays
    int totalWins = 0; // how may wins
    string ans = "";  // whether to play again or not
    
    // set precision to about 1 digit after the decimal
    cout << setprecision(1) << fixed;
    // just call this once before you call any rand()
    // function.
    srand((int)time(0));
    
    cout << "******* GUESS THE NUMBER GAME *********" << endl << endl;
    
    do {  // loop for each play of the game
		
	    totalPlays++; // keep track of total number of plays
		// this is the start of one play here
	    // generate a random number
	    number = (rand() % range) + BEG;
	    
	    // do up to MAX_GUESSES number of rounds
	    // the count variable is declared outside and
	    // above so we can check it later 
	    int round;
	    for(round = 0; round < MAX_GUESSES; round++) {  
		    // ask the user for a guess
		    cout << "Enter a number between " << BEG
		         << " and " << END << ": " << endl;
		    cin >> guess;
		    	    
		   // check to see if the number has been guessed
		    if(number == guess) {
		       cout << "You've Guessed Correctly! Congradulations!" 
		            << endl << endl;
		       totalWins++;
		       break;
		    }
		    else {
				cout << "Sorry didn't guess right. Try again. " 
				     << endl << endl;
			}
			
         }
   
         // check to see if they went to the max guesses
         if(round == MAX_GUESSES) {
             cout << endl << "Sorry. You're out of guesses. " << endl;
             cout << "The number was: " << number << endl << endl;
         }
 
         cout << "Do you want to play again? (y or n): ";
         cin >> ans;
         
         cout << endl << endl;
	    
    } while(ans == "y" || ans == "Y" || ans == "Yes" || ans == "yes");
    
    float percent = ((float) totalWins) / totalPlays * 100.0;
    
    cout << "You've guessed " << totalWins << " out of " 
         << totalPlays << endl;
    cout << "You've won %" << percent << " of the time." << endl;
    
    cout << endl << endl 
         << "*****THANK YOU FOR PLAYING OUR GAME! ****" << endl;
     
    return 0; 
}
