
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "testlist.h"
#include "sortalgs.h"

using std::cin;

class UserInterface {
	
public:
	void mainMenu();
	void newData();
	void sortData();
	void showStatistics();	
};



void UserInterface::mainMenu() {
	int choice;
	cout << "Sort Experiments\n"
		<< "--------------------\n\n";
	cout << "(1) Generate New Data\n" // newData function
		<< "(2) Sort Data\n" // sortData function
		<< "(3) Show Statistics\n" // showStatistics function ??, save to txt
		<< "(4) QUIT\n>> ";
	
	cin >> choice;
	
	switch (choice) {
		case 1:
			newData();
			break;
		case 2:
			sortData();
			break;
		case 3:
			//showStatistics();
			break;
		case 4:
			break;
		
		default:
			cout << "not a valid entry\n";
			mainMenu();
	}		
}

void UserInterface::newData() {
	int choice[2];
	
	cout << "Test Data\n"
		<< "-------------\n\n";
	cout << "(1) Best Case\n" // 1...n
		<< "(2) Worst Case\n" // n...1
		<< "(3) Average Case\n" // random
		<< "(4) All\n"
		<< "(5) Main Menu\n>> ";
	cin >> choice[0];
	if(choice[0] == 5) {
		mainMenu();
	}
	if( (choice[0] != 1) && (choice[0] != 2) && (choice[0] != 3) && (choice[0] != 4) ) {
			cout << "not a valid entry\n";
			newData();
	}
	cout << "How many data elements to generate?\n>> ";
	cin >> choice[1];
	cout << choice[1];
	
	switch (choice[0]) {
		case 1:
			// generate best list 
			break;
		case 2:
			// generate worst list
			break;
		case 3:
			// generate average list
			break;
		case 4:
			// generate all 3
			break;
		default:
			cout << "not a valid entry\n";
			newData();
	}	
}

void UserInterface::sortData() {
	int choice[2];
	
	cout << "Type of data to use?\n"
		<< "-------------\n\n";
	cout << "(1) Best Case\n" //
		<< "(2) Worst Case\n" //
		<< "(3) Average Case\n" //
		<< "(4) All\n"
		<< "(5) Main Menu\n>> ";
	cin >> choice[0];
	if(choice[0] == 5) {
		mainMenu();
	}
	
	cout << "Type of sort?\n"
		<< "-------------\n\n";
	cout << "(1) Bubble\n" // 
		<< "(2) Selection\n" //
		<< "(3) Insertion\n" //
		<< "(4) Merge\n" //
		<< "(5) Quick\n" //
		<< "(6) All (Warning! may take a long time)\n"
		<< "(7) Main Menu\n>> ";
	cin >> choice[1];
	cout << choice[1];
	if(choice[1] == 7) {
		mainMenu();
	}
	
	if( (choice[0] > 0 && choice[0] < 5) && (choice[1] > 0 && choice[1] < 7) ){
		cout << "ok\n";
		// run sort funtion
	} else {
		cout << "not a valid entry\n";
		sortData();
	}
}

#endif
