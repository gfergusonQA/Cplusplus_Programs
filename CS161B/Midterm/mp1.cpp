/*This is the starter file for the practice midterm exam.
This program has a function that will generate a list of integers using the rand function.
Your job is to fill the insertNum and oddCount functions.*/

#include <iostream>
#include <ctime>

using namespace std;

//constants and function prototypes
const int CAP = 100;
int buildList(int[], int size);
void printList(const int[], int size);

//your functions to implement
/*This function finds even numbers in the list, and inserts a number before 
the even number such that the new number is one less than the even number.  
Then return the new size. You should make sure that size does not go past CAP.
Please see my samples in the document and run the test a few times since 
my list is randomly generated.*/

int insertNum(int list[], int size);

/*This function counts the number of odd numbers in the list and returns 
to main.*/

int oddCount(int array[], int size);

//name: 		    main
//description:		main function
//input params:		none
//output:		    List after inserts, and odd count
//return:		    none
int main()
{
	//DO NOT CHANGE MAIN
	int list[CAP], size = 0, count = 0;
	size = buildList(list, size);
	cout << "Original List!" << endl;
	printList(list, size);
	size = insertNum(list, size);
	cout << "List after inserts!" << endl;
	printList(list, size);
	count = oddCount(list, size);
	cout << "Number of odds = " << count << endl;
	return 0;
}

//name: 		    buildList
//description:		function to build list.  DO NOT CHANGE THIS
//input params:		int array and its size
//output:		    none
//return:		    none

int buildList(int list[], int size)
{
	srand(time(NULL));
	size = 10;
	for (int i = 0; i < size; i++)
	{
		list[i] = rand() % 100;
	}
	return size;
}

//name: 		    printList
//description:		function to print the list.  DO NOT CHANGE THIS
//input params:		int array and its size
//output:		    none
//return:		    none

void printList(const int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
}


//implement the missing functions here.
//add appropriate comments as I have done for other functions

int insertNum(int list[], int size)
{
	return 0;
}

//counts the odd numbers in the array and returns the count.
//add appropriate comments as I have done for other functions

int oddCount(int array[], int size)
{
	return 0;
}


