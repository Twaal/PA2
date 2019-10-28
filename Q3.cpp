#include <math.h>
#include <iostream>
using namespace std;
int* reverseMultiply(int* list,int size);
int * reverseAdd (int *list, int size);
int main(){
	cout << "Enter the number of entries: ";
	int entries;
	cin >> entries;

	int testList[entries];


	for (int j = 0; j < entries; j++){
		cout << "Entry " << j << " is: ";
		int input;
		cin >> input;
		testList[j] = input;
	}
	  ////////////////////////
	 //initialize the array//
	////////////////////////
	int arrayMult[(2*entries)+1];
	
	for (int k = 0; k < (2*entries)+1;k++){
		arrayMult[k] = (reverseMultiply(testList,entries)[k]);
	}

	
	  //////////////////////////////
	 //display the original array//
	//////////////////////////////
	cout << "The original array is: [";

	for (int i = 0; i < entries; i++){
		cout << " "<< testList[i];
	}

	cout << "] and the address of the zero element is: "<< &testList[0];

	  //////////////////////////////////////
	 //display the reverseMultiply array //
	//////////////////////////////////////
	cout << "\nOne array is: [";
	for (int i=0;i<(sizeof(arrayMult))/4;i++){
		cout << " "<<arrayMult[i];
	}
	cout << "] and the address of the zero element is: "<< &arrayMult[0];

	
	  //////////////////////////////////
	 // display the reverseAdd array //
	//////////////////////////////////
	
	

	int arrayAdd[(2*entries)-1];


	for (int i = 0; i < (2*entries)-1;i++){
		arrayAdd[i] = (reverseAdd(arrayMult,(sizeof(arrayMult)/4))[i]);
	}

	cout << "\nTwo array is: [";
	for (int i=0;i<(sizeof(arrayAdd))/4;i++){
		cout << " "<<arrayAdd[i];
	}
	cout << "] and the address of the zero element is: "<< &arrayAdd[0];





	cout << "\n";
	cout << "\n";
	return 0;
}

	    ////////////////////////////////////////////////////////////////////////
	   //  reverseMultiply() takes the users inputs and appends the entries  //
	  //   in reverse, then the last element of the array is the procust    //
	 //    of all the prior elements in the array.                         //
	////////////////////////////////////////////////////////////////////////

int* reverseMultiply(int* list, int size){
	int product = 1;
	int newSize = (2*size)+1;
	int* newList = new int[newSize];
	for (int i = 0; i < size; i++){
		newList[i]=list[i];
	}
	int count = size-1;
	for (int j = size; j < (newSize-1);j++){
		newList[j]=list[count];
		count --;
	}
	for (int k=0;k<(newSize-1);k++){
		product = product * newList[k];
		
	}
	newList[newSize-1]=product;
	return newList;
	delete newList;

}

	    ///////////////////////////////////////////////////////////////////
	   //  reverseAdd() takes the array from part one and adds the      //
	  //   consecutive numbers together. The first numbers are         //
	 //    same as the entries.                                       //
	///////////////////////////////////////////////////////////////////
int* reverseAdd (int *newList, int newSize){
	int* addArr = new int[newSize-2];
	for (int i = 0;i<(newSize-1)/2;i++){
		addArr[i]=newList[i];
	}
	int count = 1;
	for (int i = ((newSize-1)/2);i<((newSize-1));i++){
		addArr[i]= newList[count] + newList[count-1];
		count++;
	}
	return addArr;
	delete addArr;
}