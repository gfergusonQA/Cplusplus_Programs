/******************************************************************************
# Author:           Gina Ferguson
# Assignment:       A05 (CS161B)
# Date:             February 21, 2024
# Description:      This program reads data from a file containing job titles, employment types, salaries, and remote work ratios. It analyzes the data to identify the position with the highest salary and provides a summary of the total number of positions and the average salary.
# Input:            File items.txt (contains information about various job positions, including job titles, employment types (FT or CT), salaries, and remote work ratios)
# Output:           maxSalaryIndex (integer): stores the index of the job position with the highest salary (in the for loop)
		   totalPositions (integer): stores the total number of positions listed in the data file items.txt
		   averageSalary (double): stores the avg salary calculated from all positions listed in the data file items.txt

# Sources:          Assignment 5 specifications
#                   Zybooks chapter 12, Shawli's class notes, and a05 example.
#******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// Constants for number of items and maximum characters
const int ITEMS = 30;
const int MAXCHAR = 51;

// Function prototypes
void welcome();
bool openFile(ifstream &inFile);
int loadData(ifstream &inFile, char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[]);
void analyzeData(char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[], int count);
void sumAnalysis(char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[], int count);

int main() {
    ifstream inFile;
    int count = 0;
    char items[ITEMS][MAXCHAR];
    char positions[ITEMS][MAXCHAR];
    int salaries[ITEMS] = {0};
    int ratios[ITEMS] = {0};

    welcome();

    if (!openFile(inFile)) {
        cout << "File did not open! Program terminating!!" << endl;
        exit(0);
    }

    count = loadData(inFile, items, positions, salaries, ratios);
    inFile.close();

    analyzeData(items, positions, salaries, ratios, count);
    sumAnalysis(items, positions, salaries, ratios, count);

    return 0;
}

//Name:		welcome
//Description: 	Prints a welcome message.
//Input params:	None
//Output:	None
//Return:	None
void welcome() {
    cout << "Welcome to Gina's Data Analysis Program!" << endl;
    cout << "This program reads data from a file, performs analysis, and displays results." << endl;
    cout << endl;
}

//Name:		openFile
//Description: 	Opens the file "items.txt" and checks if it is opened successfully.
//Input params:	file stream variable
//Output:	None
//Return:	True if file opened successfully, false otherwise.
bool openFile(ifstream &inFile) {
    inFile.open("items.txt");
    return inFile.is_open();
}

//Name:		loadData
//Description: 	Loads data from the file into arrays.
//Input params:	File stream variable, char arrays for item names and positions, int arrays for salaries and ratios.
//Output:	None
//Return:	The number of items loaded.
int loadData(ifstream &inFile, char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[]) {
    int count = 0;
    while (count < ITEMS && inFile.getline(items[count], MAXCHAR, ';')) {
        inFile.getline(positions[count], MAXCHAR, ';');
        inFile >> salaries[count];
        inFile.ignore(1, ';');
        inFile >> ratios[count];
        inFile.ignore(1, '\n');
        count++;
    }
    return count;
}

//Name:		analyzeData
//Description: 	Analyzes the loaded data to find the position with the highest salary.
//Input params:	Arrays of item names, positions, salaries, ratios, and the count of items.
//Output:	Prints the position with the highest salary.
//Return:	None
void analyzeData(char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[], int count) {
int i = 0;
int maxSalaryIndex=0;
    //Find the position with the highest salary
    for (i = 1; i < count; ++i) {
        if (salaries[i] > salaries[maxSalaryIndex]) {
            maxSalaryIndex = i;
        }
    }

    // Output the position with the highest salary
    cout << "Position with the highest salary:" << endl;
    cout << "Job Title: " << items[maxSalaryIndex] << endl;
    cout << "Position: " << positions[maxSalaryIndex] << endl;
    cout << "Salary: $" << salaries[maxSalaryIndex] << endl;
    cout << "Remote Ratio: " << ratios[maxSalaryIndex] << "%" << endl;
    cout << endl;
}

//Name:		sumAnalysis
//Description: 	Performs sums analysis on the loaded data.
//Input params:	Arrays of item names, positions, salaries, ratios, and the count of items.
//Output:	Prints summary analysis including total positions and average salary.
//Return:	None
void sumAnalysis(char items[][MAXCHAR], char positions[][MAXCHAR], int salaries[], int ratios[], int count) {
    // Calculate the total number of positions and the average salary
    int totalPositions = count;
    double totalSalary = 0;
    double averageSalary = 0.0;
    int i = 0;
    for (i = 0; i < count; ++i) {
        totalSalary += salaries[i];
    }
    averageSalary = totalSalary / count;

    // Output the summary analysis
    cout << "Summary Analysis:" << endl;
    cout << "Total Positions: " << totalPositions << endl;
    cout << "Average Salary: $" << fixed << setprecision(2) << averageSalary << endl;
}

