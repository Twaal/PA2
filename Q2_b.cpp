#include <iostream>
#include <math.h>

using namespace std;

double series(int);

////////////////////////////////////////////////
/////     Print what the program does,     /////
/////     ask the user for an input,       /////
/////     print the results.               /////
////////////////////////////////////////////////

int main(){
	int index;
	cout << "EC327: Introduction to software engineering\nFall 2019\nProgramming Assignment 2\nFinds the n-th index of the series (2n)/(3n + 2).\n";
	cout << "Enter n: ";
	cin >> index;
	cout << "Series("<< index << ") is: " <<series(index) <<"\n";
	return 0;
}

///////////////////////////////////////////////////
//////      This function calculates the      /////
//////      value of f(x) = (2n)/(3n+2)       /////
///////////////////////////////////////////////////


double series(int n){
	if (n == 1){
		return 0.4;
	} else {
		double fn = (double)(2*n)/((3*n)+2);
		return (fn + series(n-1));
	}
}