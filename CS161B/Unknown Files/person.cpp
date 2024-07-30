// person.cpp file including function definitions
#include "person.h"
/*#***************************************************************************/

//Name:   populatePersons(PersonType list[], int& count, const char fileName[])
//Desc:   Loads the file and loads name, citizen, age, in a loop, increment+1
//input:  citizenship (char array): to store country chars, age (char array): 
//        to store age chars, name (char array): to store name chars
//output: error messaging (cout + strings)
//return: string name
//function to read from file and populate list
void populatePersons(PersonType list[], int& count, const char fileName[])
{
    ifstream inFile;
    char name[MAX_CHAR];
    char citizen[MAX_CHAR];
    int age = 0;

    inFile.open(fileName);
    if(!inFile)
    {
        cout << "\nFail to open " << fileName << " to populate inventory!" 
        << endl;
        exit(1);
    }
    inFile >> name;
    while(!inFile.eof())
    {
        inFile >> citizen;
        inFile >> age;
        strcpy(list[count].name, name);
        strcpy(list[count].citizenship, citizen);
        list[count].age = age;
        count++;

        inFile >> name;
    }
    inFile.close();
}

//Name:   printPersons()
//Desc:   Prints all persons on list[] that are datatype PersonType (struct)
//input:  PersonType list[] so it can be altered
//output: printing name, citizenship, and age in a for loop
//return: None (void)
void printPersons(const PersonType list[], int count)
{
    int index = 0;
    for(index = 0; index < count; index++)
    {
        cout << list[index].name << ";" << list[index].citizenship;
        cout << ";" << list[index].age << endl;
    }
}

/* --------------------- My additions below ----------------------------- */

//Name:   welcome()
//Desc:   Prints the welcome message
//input:  None
//output: welcome string
//return: NOne (void)
void welcome() {
  cout << "\nWelcome to my Citizen's Database!\n\n";
}

//Name:   addPerson(PersonType list[], int &count)
//Desc:   Reads list[] and inserts new info in array PersonType struct with a boolean
//input:  PersonType list[] (char array): where name, citizenship, and age are inserted
//        &count (integer): tracks the number of people inthe list (not a direct input)
//output: string prompts, bool: the function outputs true or false based on conditions
//return: true or false
bool addPerson(PersonType list[], int &count) {
  int position = 0;
  int i = 0;
  int tempAge = 0;
  PersonType aPerson;
  
  if (count >= CAPACITY) 
  {
    cout << "\nError! The list is full.\n";
    return false;
  }
  cout << "\nEnter your name: ";
  cin.getline(aPerson.name, MAX_CHAR);  
  if (containsDigit(aPerson.name)) { // digit data validation
    cout << "\nError! Name cannot contain numbers.\n";
    return false;
  }
  cout << "Enter your citizenship: ";
  cin.getline(aPerson.citizenship, MAX_CHAR);
  if (containsDigit(aPerson.citizenship)) { // digit data validation
    cout << "\nError! Citizenship cannot contain numbers.\n";
    return false;
  }
  readInt("Enter your age (whole #s only): ", tempAge);
  aPerson.age = tempAge; // assigning to check validity
  if (aPerson.age < 1 || aPerson.age > 100)
    {
      cout << "\nError! Invalid age.\n";
      return false;
    }
  cout << "Enter position number: ";
  cin >> position;
  cin.ignore(); // to consume new line
  if (position < 0 || position > count)
  {
    cout << "\nError! Invalid position.\n";
    return false;
  }
  // shift elements to the right to make space for the new element
  for (i = count; i > position; i--)
    {
      list [i] = list[i-1];
    }
  // insert new element
  list[position] = aPerson;
  count++;
  return true;
}

//Name:   goodbye()
//Desc:   Prints good bye message
//input:  None
//output: string
//return: None (void)
void goodbye() {
  cout << "\n\n*~*~*~ Thank you for using my Citizen Database!! ~*~*~*\n\n";
}

/* --------- my data validation function definitions ---------------------- */

//Name:   readInt(const char prompt[], int &age)
//Desc:   reads integer input for data validation status for age
//input:  age (integer reference): input age or integer to validate
//output: error message w/ string if cin fails
//return: none (void)
void readInt(const char prompt[], int &age) {
  cout << prompt;
  while (!(cin >> age)) {
    cout << "\nInvalid input. Please enter a valid number: ";
    cin.clear();
    cin.ignore(100, '\n');
  }
  cin.ignore(100, '\n');
}

//Name:   containsDigit(const char str[])
//Desc:   Returns true or false if char in array is a digit
//input:  char for str[], and processed w for loop
//output: bool (containsDigit) true or false
//return: true or false
bool containsDigit(const char str[]) {
  int i = 0;
  for (i = 0; str[i] != '\0'; i++) { // account for not null terminator
    if (isdigit(str[i])) {
      return true;
    }
  }
  return false;
}