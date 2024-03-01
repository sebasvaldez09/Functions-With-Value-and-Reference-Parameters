/////////////////////////////////////////////////////////////////////
//
// Name: Sebastian Valdez
// Due date: 2-28-2024
// Class: CSCI 1470.04
// Semester: Spring 2024
// CSCI 1470 Instructor: Gustavo Dietrich
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//************************  Function definitions  *************************

// Read the handout carefully for detailed description of the functions that you have to implement

// round_off(): Rounds the value received in the first parameter to the number of digits received in the second parameter

double round_off(double val, int dig)
{
    return round(val * pow(10., dig)) / pow(10., dig);
}


// getData(): Gets two lengths from the keyboard and returns them to the caller
void getData(double & lengtha, double & lengthb)
{
    cin >> lengtha >> lengthb;
}

// printData(): Receives the output file, base of the rectangle, height of the rectangle, area of the rectangle,
// radius a of the ellipse, radius b of the ellipse, and area of the ellipse and prints the output to the file

void printData(ofstream & outFile, double base, double height, double area_rec, double radiusa, double radiusb, double area_ellipse){
    outFile << fixed << setprecision(2);
    outFile << endl << "The area of the rectangle with base " << setw(5) << base << " and height "  << setw(5) << height << " is " << setw(5) << area_rec << endl << endl;
    outFile << endl << "The area of the ellipse with radius " << setw(5) << radiusa << " and radius " << setw(5) << radiusb << " is " << setw(5) << area_ellipse << endl << endl;
}


// area_rectangle(): Calculates the area of the rectangle and returns it rounded to 1 decimal digit to the caller

double area_rectangle(double base, double height){
double area_rectangle = base * height;
return round(area_rectangle * 10.) / 10.;
}

// area_ellipse(): Calculates the area of the area_ellipse and returns it rounded to 1 decimal digit to the caller

double area_ellipse(double radiusa, double radiusb){
return round(PI * radiusa * radiusb * 10.) / 10.;
}
