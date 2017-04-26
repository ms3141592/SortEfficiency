/*
	Generate 3 test data files
		let user choose amount of data
		best(++), worst(--), average(random) --> int items
	Write a program that reads data from file into array(user choice),
	-run bubble sort on array and time it
	**Add multiple sort types
	**Test efficiency on diff sort type and case
*/
#include<iostream>


#include "testlist.h"

int main() {
	
	int listLen = 1000;
	int listArray[listLen];
	
	SetTestList setlist;
	
	setlist.bestCase(listLen);
	setlist.worstCase(listLen);
	setlist.averageCase(listLen);
	
	setlist.listToArray(2, listArray);
	
	for(int i = 0; i < listLen; i++) {
		std:cout << listArray[i] << std::endl;
	}

	return 0;
}

