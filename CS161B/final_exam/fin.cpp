/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       Final Exam Version A (CS161B)
# Date:             Tuesday, March 19, 2024
# Description:      This program provides a database .txt file. The user can
#                   add a person to the list (using a struct + array). The 
#                   code entails shifting the list of names and their 
#                   associated data so that the new name will be added to 
#                   that index. There is also data validation included.
# Input:            addPerson (bool function): adds a person to the array/database
# Output:           void functions:
#                        - welcome(): prints welcome message
#                        - printPersons(list, count): prints out the database list
#                        - goodbye(): prints goodbye message
# Sources:          Zybooks & Shawli's notes (& practice exam)
#******************************************************************************/
#include "person.h"

//Name:   main()
//Desc:   THIS IS THE MAIN DRIVER FILE. Main runs the program using functions.
//input:  see header comment
//output: see header comment
//return: 0 to end program
int main()
{
  PersonType list[CAPACITY];
  int count  = 0;
  char fileName[] = "persons.txt";

  welcome();
  populatePersons(list, count, fileName);
  cout << "\nHere is your list so far: \n\n";
  printPersons(list, count);
  if (addPerson(list, count)) 
  {
    cout << "\nAfter adding a person, the list is: \n\n";
    printPersons(list, count);
  } else {
    cout << "\nFailed to add a person.\n";
  }
  goodbye();
  return 0;
}


