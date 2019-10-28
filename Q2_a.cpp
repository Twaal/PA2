#include <iostream>
#include <math.h>
using namespace std;
int gcd(int,int);


////////////////////////////////////////////////
/////     Print what the program does,     /////
/////     ask the user for an input,       /////
/////     print the results.               /////
////////////////////////////////////////////////



int main(){
	cout << "EC327: Introduction to software engineering\nFall 2019\nProgramming Assignment 2\nFinds the greatest common divisor of input 'm' and 'n'.\n";
	int m,n,ans;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	ans = gcd(m,n);
	cout << "GCD is: " << ans << "\n";
	return 0;
}

////////////////////////////////////////////////
/////     This function calculates the     /////
/////     greatest common divisor          /////
/////     of two numbers.                  /////
////////////////////////////////////////////////


int gcd(int m, int n){
	if (m%n == 0){
		return n;
	} else {
		return gcd(n,m%n);
	}
}