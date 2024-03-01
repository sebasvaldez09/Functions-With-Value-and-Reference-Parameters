/////////////////////////////////////////////////////////////////////
//
// Name: Sebastian Valdez
// Due date: 2-28-2024
// Class: CSCI 1470.04
// Semester: Spring 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
/* Using files, we get 4 inputs from the user to calculate the area of a rectangle and the area of an ellipse.
The outputs are shown in the file output9.txt */
/////////////////////////////////////////////////////////////////////

#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries that your program needs to compile

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;


// Ignore this; it's a little function used for making tests
inline void
_test (const char *expression, const char *file, int line)
{
  cerr << "test(" << expression << ") failed in file " << file;
  cerr << ", line " << line << "." << endl << endl;
}

// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Declare a global constant named PI equal to 3.141592

const double PI = 3.141592;

// Include here your header file 

#include "myfunction.h"


void getData (double &lengtha, double &lengthb);

double area_rectangle (double base, double height);

double area_ellipse (double radiusa, double radiusb);

void printData (ofstream & outFile, double base, double height,
				double area_rec, double radiusa, double radiusb,
				double area_ellipse);


int
main ()
{
// Declare variable named outFile to represent the output file

  ofstream outFile;				// output file variable

// Declare variables named base, height, radiusa, and radiusb that hold doble precision numbers

  double base, height, radiusa, radiusb;

// Declare variables named rec_area, and elli_area that hold double precision real numbers

  double rec_area, elli_area;

// Open output file "output9.txt" and relate it to outFile

  outFile.open ("output9.txt");

//Print on the screen "For the rectangle"

  cout << "For the rectangle" << endl << "Please enter two lengths: ";

//Call void function getData() and receive in base and height the two lengths read from the keyboard

  getData (base, height);

//Print on the screen "For the ellipse"

  cout << endl << "For the ellipse" << endl << "Please enter two lengths: ";

//Call void function getData() and receive in radiusa and radiusb the two lengths read from the keyboard

  getData (radiusa, radiusb);


// Call function area_rectangle() to calculate the area of a rectangle and assign the returned value to rec_area

  rec_area = area_rectangle (base, height);


//Call function area_ellipse() to calculate the area of an ellipse and assign the returned value to elli_area

  elli_area = area_ellipse (radiusa, radiusb);


// Call function printData() to print the output to the output file

  printData (outFile, base, height, rec_area, radiusa, radiusb, elli_area);


// Close the file

  outFile.close ();


  // Do NOT remove or modify the following statements
  cout << endl << "Testing your solution" << endl << endl;
  test (typeid (PI) == typeid (1.));	// Incorrect data type used for PI
  test (PI == 3.141592);		// Incorrect value used for PI
  test (typeid (base) == typeid (1.));	// Incorrect data type used for base
  test (typeid (height) == typeid (1.));	// Incorrect data type used for height
  test (typeid (radiusa) == typeid (1.));	// Incorrect data type used for radiusa
  test (typeid (radiusb) == typeid (1.));	// Incorrect data type used for radiusb
  test (typeid (rec_area) == typeid (1.));	// Incorrect data type used for rec_area
  test (typeid (elli_area) == typeid (1.));	// Incorrect data type used for elli_area
  test (fabs (area_rectangle (2.33, 3.61) - 8.4) < 0.001);	// Incorrect rounding of area of rectangle
  test (fabs (area_rectangle (2.42, 3.7) - 9.0) < 0.001);	// Incorrect rounding of area of rectangle
  test (fabs (area_ellipse (4.55, 5.95) - 85.1) < 0.001);	// Incorrect rounding of area of ellipse
  test (fabs (area_ellipse (4.61, 6.01) - 87.0) < 0.001);	// Incorrect rounding of area of ellipse

  return 0;
}
