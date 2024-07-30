#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double LABOR_COST = 35.00;
const int SQUARE_FEET = 110;

void getWallDimensions(double& length, double& width, double& height);
double getPaintPrice();
double calcWallSquareFeet(double length, double width, double height);
void numberOfGallons(double sqFeet, int& gallons);
void laborHours(int gallons, int& hours);
void displayCost(int gallons, double paintPrice, int hours);

int main(){
  double length, width, height, paintPrice, wallSquareFeet;
  int gallons, hours = 0;


  getWallDimensions(length, width, height);
  paintPrice = getPaintPrice();
  wallSquareFeet = calcWallSquareFeet(length, width, height);
  numberOfGallons(wallSquareFeet, gallons);
  laborHours(gallons, hours);
  displayCost(gallons, paintPrice, hours);

  return 0;
}

double getPaintPrice(){
  double paintPrice;
  cout << "Enter the price of the paint per gallon: ";
  cin >> paintPrice;
  while (paintPrice < 10.00) {
    cout << "ERROR: Paint price must be 10.00 or greater.\n";
    cout << "Enter the price of the paint per gallon: ";
    cin >> paintPrice;
  }
  cin.ignore();
  return paintPrice;
}

void getWallDimensions(double &length, double &width, double &height) {
  cout << "Enter the length, width, and height of the room (in feet):\n";
  cout << "Length: ";
  cin >> length;
  while (length < 5 || length < 0) {
    cout << "ERROR. Cannot be less than 5 feet.\n";
    cout << "Length: ";
    cin >> length;
  }
  cin.ignore();

  cout << "Width: ";
  cin >> width;
  while (width < 5 || width < 0) {
    cout << "ERROR. Cannot be less than 5 feet.\n";
    cout << "Width: ";
    cin >> width;
  }
  cin.ignore();

  cout << "Height: ";
  cin >> height;
  while (height < 5 || height < 0) {
    cout << "ERROR. Cannot be less than 5 feet.\n";
    cout << "Height: ";
    cin >> height;
  }
  cin.ignore();
}

double calcWallSquareFeet(double length, double width, double height) {
  double wallSquareFeet;
  wallSquareFeet = 2 * height * (length + width);
  return wallSquareFeet;
}

void numberOfGallons(double wallSquareFeet, int &gallons) {
  gallons = ceil(wallSquareFeet / SQUARE_FEET);
}

void laborHours(double gallons, int &hours) {
  hours = gallons * 8;
}

void displayCost(int gallons, double paintPrice, int hours) {
  double paintCost, laborCost, totalCost;
  paintCost = gallons * paintPrice;
  laborCost = hours * LABOR_COST;
  totalCost = paintCost + laborCost;

  cout << fixed << setprecision(2);
  cout << "\n" << left << setw(20) << "Gallons of paint:" << right << setw(10) << gallons << endl; // set the width and alignment of the output fields
  cout << left << setw(20) << "Paint cost:" << right << setw(10) << "$" << paintCost << endl; // add a dollar sign before the cost values
  cout << left << setw(20) << "Hours of labor:" << right << setw(11) << hours << endl;
  cout << left << setw(20) << "Labor cost:" << right << setw(10) << "$" << laborCost << endl;
  cout << left << setw(20) << "Total charges:" << right << setw(10) << "$" << totalCost << endl;
  cout << endl;
}