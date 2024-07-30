//main driver file
//add header comments here.
#include "person.h"
const int CAPACITY = 20;

//function protoypes

//main and then functions.
int main()
{
	PersonType list[CAPACITY];
	int 	   count  = 0;
	char	   fileName[] = "persons.txt";

	populatePersons(list, count, fileName);
	printPersons(list, count);

	//call your functions here to do what is required.
	
	return 0;
}


