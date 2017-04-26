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
	
	int listLen = 10000;
	int listArray[listLen];
	
	SetTestList setlist;
	SortAlgs sortalgs;
	
	setlist.bestCase(listLen);
	setlist.worstCase(listLen);
	setlist.averageCase(listLen);

	// bubble sort
	std::cout << "bubble sort\n---------------" << endl;	
	setlist.listToArray(0, listArray);	
	std::cout << "start best case" << std::endl;
	sortalgs.bubbleSort(listLen, listArray);
	
	setlist.listToArray(1, listArray);	
	std::cout << "start worst case" << std::endl;	
	sortalgs.bubbleSort(listLen, listArray);
	
	setlist.listToArray(2, listArray);	
	std::cout << "start average case" << std::endl;	
	sortalgs.bubbleSort(listLen, listArray);
	
	// intersection sort
	std::cout << "\ninsertion sort\n---------------" << endl;	
	setlist.listToArray(0, listArray);	
	std::cout << "start best case" << std::endl;
	sortalgs.insertionSort(listLen, listArray);
	
	setlist.listToArray(1, listArray);	
	std::cout << "start worst case" << std::endl;	
	sortalgs.insertionSort(listLen, listArray);
	
	setlist.listToArray(2, listArray);	
	std::cout << "start average case" << std::endl;	
	sortalgs.insertionSort(listLen, listArray);
	
	// quick sort
	std::cout << "\nquick sort\n---------------" << endl;	
	setlist.listToArray(0, listArray);	
	std::cout << "start best case" << std::endl;
	sortalgs.quickSortCall(listLen, listArray);
	
	setlist.listToArray(1, listArray);	
	std::cout << "start worst case" << std::endl;	
	sortalgs.quickSortCall(listLen, listArray);
	
	setlist.listToArray(2, listArray);	
	std::cout << "start average case" << std::endl;	
	sortalgs.quickSortCall(listLen, listArray);	

	return 0;
}

