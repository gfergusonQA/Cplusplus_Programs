#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX = 51;

// Function prototypes
bool openFile(ifstream& inFile, string fileName);
void ratioCalc(ifstream& inFile, ofstream& fileName);
void calculateOtherStatistic(ifstream& inFile, ofstream& outFile);

int main() {
    ifstream inFile;
    ofstream outFile;
    char highestSalary[MAX];
    int maxSalary = 0;

    // Open file and check if successful
    if (!openFile(inFile, "stem.txt")) {
        cout << "Error opening file." << endl;
        return 0;
    }

    // open output file
    outFile.open("stemout.txt");

    // Calculate and write ratio of men and women
    ratioCalc(inFile, outFile);
    calculateOtherStatistic(inFile, outFile);

    // Close files
    inFile.close();
    outFile.close();
  
    return 0;
}

//Name:   openFile()
//Desc:   This function opens a file
//input:  None
//output: open file
//return: true or false if the file is opened
bool openFile(ifstream& inFile, string fileName) {
    inFile.open(fileName);
    if (!inFile) {
      return false;
    }
    return true;
}

//Name:   ratioCalc()
//Desc:   This function calculates percentage of men/women in majors
//input:  read from stem.txt file
//output: strings and data for men/women percentages
//return: men/women percentages
void ratioCalc(ifstream& inFile, ofstream& outFile) {
    char major[MAX];
    char discardLine[MAX];
    int men = 0;
    int women = 0;
    int total = 0;
    int intDiscard = 0;
    double menPerc = 0.00;
    double womenPerc = 0.00;

    outFile << left << setw(50) << "Major" << left << setw(15) << "Men %"
      << left << setw(15) << "Women %" << endl;
    outFile << left << setw(50) << "-----" << left << setw(15)
      << "-----" << left << setw(15) << "-------" << endl;
    cout << left << setw(50) << "Major" << left << setw(15) << "Men %" 
    << left << setw(15) << "Women %" << endl;
    cout << left << setw(50) << "-----" << left << setw(15)
    << "-----" << left << setw(15) << "-------" << endl;

    //ignore header line
    inFile.ignore(200, '\n');

    // read from files
    inFile >> intDiscard >> major >> discardLine
        >> total >> men >> women >> intDiscard;

    while(!inFile.eof()) {
      menPerc = (static_cast<double>(men) / total) * 100;
      womenPerc = (static_cast<double>(women) / total) * 100;
      outFile << fixed << setprecision(2);
      outFile << left << setw(50) << major << left 
        << setw(15) << menPerc << left << setw(15) 
        << womenPerc << endl;
      // read from the file
      inFile >> intDiscard >> major >> discardLine 
        >> total >> men >> women >> intDiscard;
    }
    inFile.clear();
    inFile.seekg(0);
}

//Name:   calculateOtherStatistic()
//Desc:   This function calculates highest salary
//input:  stem.txt file dataset
//output: highest salary
//return: n/a
void calculateOtherStatistic(ifstream& inFile, ofstream& outFile) {
    char major[MAX];
    char discardLine[MAX];
    char topMajor[MAX];
    int salary = 0;
    int intDiscard = 0;
    int maxSalary = 0;
    
    inFile.ignore(200, '\n');

    while (!inFile.eof()) {
      //read from file
    inFile >> intDiscard >> major >> discardLine >> intDiscard >> intDiscard >> intDiscard >> salary;

      if(salary > maxSalary) {
        maxSalary = salary;
        strcpy(topMajor, major);
      }
    }
  outFile << "\n The major that has the highest salary is " << topMajor << " with a salary of $" << maxSalary << endl;
}
