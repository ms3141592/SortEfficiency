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
#include "sortalgs.h"

int main() {
	
	int listLen = 100000;
	int listArray[listLen];
	
	SetTestList setlist;
	SortAlgs sortalgs;
	
	setlist.bestCase(listLen);
	setlist.worstCase(listLen);
	setlist.averageCase(listLen);
	
	setlist.listToArray(0, listArray);	
	std::cout << "start best case" << std::endl;
	sortalgs.bubbleSort(listLen, listArray);
	
	setlist.listToArray(1, listArray);	
	std::cout << "start worst case" << std::endl;	
	sortalgs.bubbleSort(listLen, listArray);
	
	setlist.listToArray(2, listArray);	
	std::cout << "start average case" << std::endl;	
	sortalgs.bubbleSort(listLen, listArray);
	
	
	/*
	for(int i = 0; i < listLen; i++) {
		std::cout << listArray[i] << endl;
	}
*/
	return 0;
}

