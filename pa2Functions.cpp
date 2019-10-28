#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "pa2Functions.h"
///// ENTRIES is the number of calculations allowed /////
const int ENTRIES = 10;
using namespace std;

//////////////////////////////////////////////////////////////////
/////     initialize() prints the title of the program.      /////
//////////////////////////////////////////////////////////////////
void initialize(){
	int numEntries = ENTRIES;

	cout << "EC327: Introduction to software engineering\nFall 2019\nProgramming Assignment 2\nValue of Entries is: " << numEntries <<"\n";
	cout << "\nCode key: \nF finds the factorial at specifed index.\nB finds fibonacci number at given index.\nR finds the suare roots.\nU finds finds the area of squares given a side length.\nC finds area of a circle given a radius.\nE finds all the even integers in the range.\nK finds random lucky numbers.\nS finds the sin values.\nN finds cosine values.\nX finds the exponentials.\nL finds the natural logs.\nY finds nyanCat values.\nD finds all the odd numbers in the set. \nI sets the program to read from an external file.\nO sets the program to write the results to a file.\nQ quits the program.\n";
}

//////////////////////////////////////////////////////////////////////
/////     checkCode() checks to see if the command is valid.     /////
//////////////////////////////////////////////////////////////////////
bool checkCode(char code){
	if (code == 'f'||code=='F'||code=='b'||code=='B'||code=='c'||code=='C'||code=='r'||code=='R'||code=='u'||code=='U'||code=='e'||code=='E'||code=='k'||code=='K'||code=='s'||code=='S'||code=='n'||code=='N'||code=='X'||code=='l'||code=='L'||code=='Y'||code=='y'||code=='D'||code=='d'||code=='I'||code=='i'||code=='O'||code=='o'||code=='Q'||code=='q'){
		return true;
	} else {
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////
/////     writeDataToFile() writes the program output to a file.     /////
//////////////////////////////////////////////////////////////////////////
void writeDataToFile(const char *file){
	//ifstream file;
}

// reads the program otput from a specified file
void readDataFromFile(const char *file){

}

// returns the factorial value at given index
int factorial(int numIn){
	if (numIn > 1){
		return numIn*factorial(numIn-1);
	} else {
		return 1;
	}
}

// returns the fibonacci value at given index
int fibonacci(int num){
	if(num == 0){
		return 0;
	}
	if (num > 2){
		return fibonacci(num-2) + fibonacci(num-1);
	} else {
		return 1;
	}
}

// returns the sguare root of the input
double findSqrtValue(double numIn){
	double numOut = sqrt(numIn);
	return numOut;
}

// returns the natural log of the input
double naturalLog(double numIn){
	double numOut = log(numIn);
	return numOut;
}

// returns the area of a circle given radius
double areaCircle(double radi){
	return 3.1415*radi*radi;
}

// returns area of a square given a side length
double areaSquare(double leng){
	return leng*leng;
}

// finds the next largest odd integer
int findNextOddValue(int numIn){
	if (numIn % 2 > 0){
		return numIn + 2;
	} else {
		return numIn + 1;
	}
}

// finds the next largest even integer
int findNextEvenValue(int numIn){
	if (numIn % 2 == 0){
		return numIn + 2;
	} else {
		return numIn + 1;
	}
}

// returns the nyanCat value of the input
double findNyanCatValue(double numIn){
	return pow(4*numIn,numIn)+numIn+10;
}

// finds sin, cos, or exponential of the input according to the input code character
double doMath(double numIn, char code){
	if (code == 's'||code=='S'){
		return sin(numIn);
	} else if (code == 'c'||code=='C'){
		return cos(numIn);
	} else if (code == 'e'||code=='E'){
		return exp(numIn);
	}
}

// returns a random number using the input as a seed
double lucky(double seed){
	srand(seed);
	return rand()%100;
}
