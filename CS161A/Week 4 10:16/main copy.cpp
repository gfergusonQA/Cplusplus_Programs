/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A04 Ferry Toll Calculator (CS161A)
# Date:             October 26, 2023
# Description:      This program will give the user a total cost to ride the ferry to the San Juan islands.                        It will ask if they have a vehicle, adults, seniors, youths, and bicycles with them and                        calculate the cost. 
# Sources:          Assignment 4 specifications, Zybooks
#******************************************************************************/
// Neither comments nor code should be wider than 79 characters.
// The lines of asterisks above are 79 characters long for easy reference.


#include <iostream>
#include <iomanip>
using namespace std;

// created a function when there is an error & it ends the program also
bool errorEndProgram(bool errorFlag) {
  if (errorFlag) {
    exit(1);
  }
  return false; // continue the program
}

int main() {
  double vehicleFare = 57.90;
  double adultFare = 14.95;
  double seniorFare = 7.40;
  double youthFare = 5.55;
  double bicycleFare = 4.00;
  char vehicleResponse = ' ';
  int adultsOnTrip = 0;
  int seniorsOnTrip= 0;
  int youthsOnTrip = 0;
  int bicyclesOnTrip = 0;
  int totalPeople = 0;
  double totalCost = 0.0;
  //invalid messages as variable to clean up my code
  string invalidAdult = "Invalid number of adults. The program will now "
    "restart. If you need to book 20 people + driver, please give us a call.";
  string invalidSeniors = "Invalid number of seniors. The program will now "
    "restart. If you need to book 20 people + driver, please give us a call.";
  string invalidYouths = "Invalid number of youths. The program will now "
    "restart. If you need to book 20 people + driver, please give us a call.";
  string invalidBicycles = "Invalid number of bicycles. The program will now "
    "restart. If you need to book 20 people + driver, please give us a call.";
  string invalidVehicle = "Invalid response. The program will now restart. "
    "Please answer with only a y/n answer next time.";
  
  cout << "Welcome to Gina’s Ferry Toll Calculator"
       << " to the beautiful San Juan Islands!" << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << setfill(' ') << setw(50) << left << "Fare Description" 
       << setw(20) << right << "Ticket $" << endl;
  cout << setw(50) << left << setfill('-') << "" << "            ";
  cout << setw(8) << right << setfill('-') << "" << endl;

  cout << setfill(' ') << setw(50) << left << "Vehicle Under 14' "
    "(less than 168 in) & Driver";
  cout << setw(15) << right << "$" << vehicleFare << endl;
  // I originally had the prices in strings but replaced with the
  // the vehicleFare, adultFare, etc variables to see what you thought.
  cout << setfill(' ') << setw(50) << left << "Adult (age 19-64)";
  cout << setw(15) << right << "$" << adultFare << endl;
  cout << setfill(' ') << setw(50) << left << "Senior (age 65 & over) /"
    "Disability";
  cout << setw(15) << right << "$" << seniorFare << endl;
  cout << setfill(' ') << setw(50) << left << "Youth (age 6 - 18)";
  cout << setw(15) << right << "$" << youthFare << endl;
  cout << setfill(' ') << setw(50) << left << "Bicycle Surcharge"
    "(included with Vehicle)";
  cout << setw(15) << right << "$" << bicycleFare << endl;

  cout << "Are you riding the ferry with a vehicle? (Y/N): " << endl;
  cin >> vehicleResponse;
  vehicleResponse = tolower(vehicleResponse); // convert to lowercase
  
  if (vehicleResponse != 'n' && vehicleResponse != 'y') 
  {
    cout << invalidVehicle << endl;
    errorEndProgram(true); // reads error and ends program
  }
  
  if (vehicleResponse == 'y') // with Vehicle
    { // ADULTS
      cout << "You chose yes! You are bringing your vehicle onto "
        "the ferry" << endl;
      cout << "How many adults? " << endl;
      cin >> adultsOnTrip;
      if (adultsOnTrip < 0 || adultsOnTrip > 21) {
        cout << invalidAdult << endl;
        errorEndProgram(true); // reads error and ends program
      }
      
      // SENIORS
      cout << "How many seniors? " << endl;
      cin >> seniorsOnTrip;
      if (seniorsOnTrip < 0 || seniorsOnTrip > 21) {
        cout << invalidSeniors<< endl;
        errorEndProgram(true); // reads error and ends program
      }
      
      // YOUTHS
      cout << "How many youths? " << endl;
      cin >> youthsOnTrip;
      if (youthsOnTrip < 0 || youthsOnTrip > 21) {
        cout << invalidYouths << endl;
        errorEndProgram(true); // reads error and ends program
      }
   
    cout << "You are welcome to bring a bicycle on your journey with"
      " your vehicle if your party is under 20 people + 1 driver. :)"
      << endl;
    // NOT BRINGING A VEHICLE
      
    totalCost += vehicleFare; // assigning totalCost to totalCost plus vehicleFare
} else
    { // ADULTS
      cout << "You chose no! You are NOT bringing a vehicle onto the ferry." << endl;
      cout << "How many adults? " << endl;
      cin >> adultsOnTrip;
      if (adultsOnTrip < 0 || adultsOnTrip > 21) {
        cout << invalidAdult << endl;
        errorEndProgram(true); // reads error and ends program
      } 
    
      //SENIORS
      cout << "How many seniors? " << endl;
      cin >> seniorsOnTrip;
      if (seniorsOnTrip < 0 || seniorsOnTrip > 21) {
        cout << invalidSeniors << endl;
        errorEndProgram(true); // reads error and ends program
      }
  
      // YOUTHS
      cout << "How many youths? " << endl;
      cin >> youthsOnTrip;
      if (youthsOnTrip < 0 || youthsOnTrip > 21) {
        cout << invalidYouths << endl;
        errorEndProgram(true); // reads error and ends program
      }
      
      // BICYCLES
      cout << "How many bicycles? " << endl;
      cin >> bicyclesOnTrip;
      if (bicyclesOnTrip < 0 || bicyclesOnTrip > 21) {  
        cout << invalidBicycles << endl; 
        errorEndProgram(true); // reads error and ends program
      }

      totalCost += (bicyclesOnTrip * bicycleFare); // adding totalCost the new         bike total
    }
    // MY CALCULATIONS FOR TOTAL AMOUNT OF PEOPLE TO KEEP THE LIMIT
    // AT 21, WHICH IS 20 PEOPLE PLUS THE DRIVER ACCORDING TO THE DOC
    totalPeople = adultsOnTrip + seniorsOnTrip + youthsOnTrip + 1;
    if (totalPeople > 21) {
      cout << "Error! There are too many people in your group. Please split up"
        " your groups into chunks of 21 people. The program will now restart.";
      errorEndProgram(true); // reads error and ends program
    }
  
    // MY CALCULATIONS FOR TOTAL COST
    totalCost += (adultsOnTrip * adultFare) + (seniorsOnTrip * seniorFare) +
      (youthsOnTrip * youthFare);
      cout << fixed << showpoint << setprecision(2);
      cout << "Your total cost is: $" << totalCost << endl;

    // Check if the total cost is over $100
  if (totalCost > 100) {
      cout << "Congratulations! You've earned a free adult ticket for"
        "your next trip!" << endl;
  } else {
      double difference = 100 - totalCost;
      cout << "You are $" << difference << " away from earning a free adult"           " ticket for your next trip." << endl;
  }

      
  return 0;
}