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

#include "userinterface.h"

int main() {	
	

	UserInterface ui;
	
	ui.runTests();
	
	return 0;
}
