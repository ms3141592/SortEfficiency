
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "testlist.h"
#include "sortalgs.h"

using std::cin;



class UserInterface {
private:
	bool menu, game, generate, sort, stats;
	int elementSize;
	
	int arrayList[100000] = {0};
	TestList tlist;
	SortAlgs salgs;
	
	void mainMenu();
	void generateMenu();
	void newData(int);
	void sortdataMenu();
	void sortData(int);
	void runBubbleSort(int);
	void runInsertionSort(int);
public:
	UserInterface();
	void runTests();
};

UserInterface::UserInterface() {
	menu = true;
	game = true; 
	generate = false;
	sort = false;
	stats = false;
}

void UserInterface::mainMenu() {
	int choice;
	cout << "Sort Experiments\n"
		<< "--------------------\n\n";
	cout << "(1) Generate Data\n" // newData function
		<< "(2) Sort Data\n" // sortData function
		<< "(3) Show Statistics\n" // showStatistics function ??, save to txt
		<< "(4) QUIT\n>> ";
	cin >> choice;
	
	switch(choice) {
		case 1:
			menu = false;
			generate = true;
			break;
		case 2:
			menu = false;
			sort = true;
			break;
		case 3:
			menu = false;
			stats = true;
			break;
		case 4:
			menu = false;
			game = false;
			break;
		default:
			cout << "invalid entry\n";
			break;
	}
}

void UserInterface::generateMenu() {
	int choice;
	
	cout << "Test Data\n"
		<< "-------------\n\n";
	cout << "(1) Best Case\n" // 1...n
		<< "(2) Worst Case\n" // n...1
		<< "(3) Average Case\n" // random
		<< "(4) All\n"
		<< "(5) Main Menu\n>> ";
	cin >> choice;
	
		switch(choice) {
		case 1 ... 4:
			newData(choice);
			break;
		case 5:
			menu = true;
			generate = false;
			break;
		default:
			cout << "invalid entry\n";
			break;
	}
	
}

void UserInterface::newData(int choice) {
	cout << "Enter amount of data\n>> ";
	cin >> elementSize;
	
	switch(choice) {
		case 1:
			tlist.bestCase(elementSize);
			cout << "best_case.txt created with " << elementSize << " elements\n";
			break;
		case 2:
			tlist.worstCase(elementSize);
			cout << "worst_case.txt created with " << elementSize << " elements\n";
			break;
		case 3:
			tlist.averageCase(elementSize);
			cout << "average_case.txt created with " << elementSize << " elements\n";
			break;
		case 4:
			tlist.bestCase(elementSize);
			cout << "best_case.txt created with " << elementSize << " elements\n";
			tlist.worstCase(elementSize);
			cout << "worst_case.txt created with " << elementSize << " elements\n";
			tlist.averageCase(elementSize);
			cout << "average_case.txt created with " << elementSize << " elements\n";
			break;
	}
	generateMenu();	
}

void UserInterface::sortdataMenu() {
	int choice;
	cout << "Type of sort?\n"
		<< "-------------\n\n";
	cout << "(1) Bubble\n" // 
		<< "(2) Selection\n" // not active
		<< "(3) Insertion\n" //
		<< "(4) Merge\n" // not active
		<< "(5) Quick\n" // not active
		<< "(6) Main Menu\n>> ";
	cin >> choice;
		
	switch(choice) {
		case 1 ... 5:
			sortData(choice);
			break;
		case 6:
			menu = true;
			sort = false;
			break;
		default:
			cout << "invalid entry\n";
			break;
	}	
}

void UserInterface::sortData(int choice) {
	
	int testChoice;
	
	cout << "Select Test Case\n"
		<< "-------------\n\n";
	cout << "(1) Best Case\n" // 1...n
		<< "(2) Worst Case\n" // n...1
		<< "(3) Average Case\n" // random
		<< "(4) All\n"
		<< "(5) Main Menu\n>> ";
	cin >> testChoice;
	
	switch(choice) {
		
		case 1:
			// bubbleSort
			cout << "\tbefore runBubbleSort() element size 0 = " << elementSize << endl; // test

			runBubbleSort(testChoice);
			cout << "\t after runBubbleSort() element size 3 = " << elementSize << endl; // test

			break;
		case 2:
			// selectionSort

			break;
		case 3:
			// insertrionSort
			cout << "\tbefore runInsertionSort() element size 0 = " << elementSize << endl; // test

			runInsertionSort(testChoice);
			cout << "\t after runInsertionSort() element size 3 = " << elementSize << endl; // test
			break;
		case 4:
			// mergeSort
			break;
		case 5:
			// quickSort
			break;
	}
}

void UserInterface::runBubbleSort(int testChoice) {
	double runTime;
	switch(testChoice) {
		case 1:
			tlist.listToArray(0, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test
			
			std::cout << "start best case" << std::endl;				
			runTime = salgs.bubbleSort(elementSize, arrayList);
			cout << "\tafter bubbleSort() element size 2 = " << elementSize << endl; // test
			
			cout << runTime << " seconds\n";
			break;
		case 2:
			tlist.listToArray(1, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test

			
			cout << "start worst case" << std::endl;				
			runTime = salgs.bubbleSort(elementSize, arrayList);
				cout << "\tafter bubbleSort() element size 2 = " << elementSize << endl; // test
				
			cout << runTime << " seconds\n";			
			break;
		case 3:
			tlist.listToArray(2, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test
			
			std::cout << "start average case" << std::endl;
			runTime = salgs.bubbleSort(elementSize, arrayList);
			cout << "\tafter bubbleSort() element size 2 = " << elementSize << endl; // test
			
			cout << runTime << " seconds\n";
			break;
		case 4:
			tlist.listToArray(0, arrayList);
			std::cout << "start best case" << std::endl;				
			runTime = salgs.bubbleSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
			
			tlist.listToArray(1, arrayList);
			std::cout << "start worst case" << std::endl;		
			runTime = salgs.bubbleSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
	
			tlist.listToArray(2, arrayList);
			std::cout << "start average case" << std::endl;		
			runTime = salgs.bubbleSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
	
			break;
		case 5:
			menu = true;
			sort = false;
			break;
		default:
			cout << "invalid entry\n";
			break;
	}
}

void UserInterface::runInsertionSort(int testChoice) {
	double runTime;
	switch(testChoice) {
		case 1:
			tlist.listToArray(0, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test
			
			std::cout << "start best case" << std::endl;				
			runTime = salgs.insertionSort(elementSize, arrayList);
			cout << "\tafter insertionSort() element size 2 = " << elementSize << endl; // test
			
			cout << runTime << " seconds\n";
			break;
		case 2:
			tlist.listToArray(1, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test

			
			cout << "start worst case" << std::endl;				
			runTime = salgs.insertionSort(elementSize, arrayList);
				cout << "\tafter insertionSort() element size 2 = " << elementSize << endl; // test
				
			cout << runTime << " seconds\n";			
			break;
		case 3:
			tlist.listToArray(2, arrayList);
			cout << "\tafter listToArray() element size 1 = " << elementSize << endl; // test
			
			std::cout << "start average case" << std::endl;
			runTime = salgs.insertionSort(elementSize, arrayList);
			cout << "\tafter insertionSort() element size 2 = " << elementSize << endl; // test
			
			cout << runTime << " seconds\n";
			break;
		case 4:
			tlist.listToArray(0, arrayList);
			std::cout << "start best case" << std::endl;				
			runTime = salgs.insertionSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
			
			tlist.listToArray(1, arrayList);
			std::cout << "start worst case" << std::endl;		
			runTime = salgs.insertionSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
	
			tlist.listToArray(2, arrayList);
			std::cout << "start average case" << std::endl;		
			runTime = salgs.insertionSort(elementSize, arrayList);
			cout << runTime << " seconds\n";
	
			break;
		case 5:
			menu = true;
			sort = false;
			break;
		default:
			cout << "invalid entry\n";
			break;
	}
}


void UserInterface::runTests() {
	while(game) {
		while(menu) {
			mainMenu();
		}
		while(generate) {
			generateMenu();
		}
		while(sort) {
			sortdataMenu();
		}	
	}
}
#endif
