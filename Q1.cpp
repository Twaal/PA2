#include "pa2Functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
// ENTRIES is the number of allowed opperations
const int ENTRIES = 10;
using namespace std;

int main(){
	char code;
	int input1;
	int first,last;
	double num1, num2, delta;
	string fileName;
	string fileRead;
	initialize();
	bool codeNotValid = true;
	bool doWrite = false;
	bool doRead = false;
	ofstream fid;
	ifstream fidr;

	// lops the prompt ENTRIES times
	for (int i = 0;i<ENTRIES;i++){
			cout << "\nPlease enter a command code: \n";
			cin >> code;

			// error checking the code
			if (!checkCode(code)){
				codeNotValid = true;
				cout <<"Invalid command code.";
			} else if (code == 'q'||code == 'Q'){
				codeNotValid = false;
				fid.close();
				return 0;
			} else {
				codeNotValid = false;
			}


			// special prompt for entering the file names
			if (code == 'i' || code == 'I'){
				doRead = true;
				cout << "Enter the name of the file you wish to read from (including the file extension): ";
				cin >> fileRead;
			}
			if (code == 'O' || code == 'o'){
				doWrite = true;
				cout << "Enter the name of the file you wish to write to (including the file extension): ";
				cin >> fileName;
			}

			//initializing the files
		ofstream fid(fileName, fid.app);
		ifstream fidr(fileRead);
		//code = getline(fidr);
		cout << "\nPlease enter command parameter(s): \n";

		// checking to see how many inputs the command requires
		// the rest of the main function is performing the operations using the user defined functions
		// this program could definetly be more modular
		// file input function does not work yet. 
		if (code == 'f'||code=='F'||code=='b'||code=='B'){
			cin >> input1;
			if (doRead && fidr.is_open()){
				//input1 = getline(fidr);
			}
			if (code == 'f'||code=='F'){
				cout << "\n" << factorial(input1)<< "\n";
				if (doWrite == true  && fid.is_open()){
					fid << to_string(factorial(input1))<< endl;
				} 
			} else {
				cout << "\n" << fibonacci(input1)<< "\n";
				if (doWrite == true  && fid.is_open()){
				  fid <</* to_string*/ (fibonacci(input1))<< endl;
					//fid.close();
				} 
			}

		} else if(code == 'q'||code == 'Q'){
			fid.close();
			return 0;
		} else if (code=='d'||code=='D'||code=='e'||code=='E'){
			cin >> first;
			cin >> last;

			if (code=='d'||code=='D'){
				cout << "\n\n";
				for(int i = first;i<(last);i+=2){
					cout << findNextOddValue(i)<<" ";
					if (doWrite == true  && fid.is_open()){
					fid << to_string(findNextOddValue(i))<< "  ";
					} 
				} 
				fid << endl;
			} else {
				cout << "\n\n";
				for(int i = first;i<(last);i+=2){
					cout << findNextEvenValue(i)<<" ";
					if (doWrite == true  && fid.is_open()){
					fid << to_string(findNextEvenValue(i))<< "  ";
					} 
				}
				fid << endl;
			}

		} else if (code == 'R'||code == 'r' || code == 'U' || code == 'u' || code == 'C' || code == 'c' || 
			code == 'K' || code == 'k' || code == 'S' || code == 's' || code == 'N' || code == 'n' || 
			code == 'X' || code == 'x' || code == 'L' || code == 'l' || code == 'Y' || code == 'y'){
			cin >> num1 >> num2 >> delta;
			if (code == 'R'||code == 'r'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double i = num1; i < num2; i = i+delta){
						cout << findSqrtValue(i) << "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(findSqrtValue(i))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							i = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'U' || code == 'u'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<areaSquare(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(areaSquare(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'C' || code == 'c'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<areaCircle(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(areaCircle(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					cout << "\n";
				}
			} else if (code == 'K' || code == 'k'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
					fid << "No computation needed." << endl;
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<lucky(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(lucky(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'S' || code == 's'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<sin(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(sin(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'N' || code == 'n'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<cos(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(cos(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'X' || code == 'x'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<exp(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(exp(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'L' || code == 'l'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<log(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(log(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					fid << endl;
					cout << "\n";
				}
			} else if (code == 'Y' || code == 'y'){
				if (delta <= 0 || num1 > num2){
					cout << "No computation needed.";
				} else {
					cout << "\n";
					int outputCounter = 0;
					for (double j = num1; j < num2+delta; j = j+delta){
						cout <<findNyanCatValue(j)<<  "  ";
						if (doWrite == true  && fid.is_open()){
							fid << to_string(findNyanCatValue(j))<< "  ";
						} 
						outputCounter++;
						if(outputCounter == ENTRIES){
							j = num2;
						}
					}
					cout << "\n";
				}
			} 
		}
	}
	cout << "\n";
	fid.close();
	return 0;
}
