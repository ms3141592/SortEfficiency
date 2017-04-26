
#ifndef TESTLIST_H
#define TESTLIST_H

#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<string>


using std::cout;
using std::string;
using std::endl;

class SetTestList {
private:
	string _caseList[3] = {"best_case.txt", "worst_case.txt", "average_case.txt"};
	void printToFile(int, int);
public:
	SetTestList();
	void bestCase(int);
	void worstCase(int);
	void averageCase(int); //
	void listToArray(int, int*);
};

SetTestList::SetTestList() {
	srand(time(0));
	for(int i = 0; i < 3; i++ ) {
		std::ofstream myfile(_caseList[i]);
		myfile.close();		
	}	
}

void SetTestList::printToFile(int i, int l) {	
	std::ofstream myfile(_caseList[l], std::ios::app);
	if (myfile.is_open()) {
		myfile << i << "\n";
		myfile.close();
	}
}

void SetTestList::bestCase(int len) {
	for(int i = 1; i <= len; i++) {
		printToFile(i, 0);
	}
}

void SetTestList::worstCase(int len) {
	for(int i = len; i > 0; i--) {
		printToFile(i, 1);
	}
}

void SetTestList::averageCase(int len) {
	int ranNum;	
	for(int i = 1; i <= len; i++) {
		ranNum = (rand()%len+1);
		printToFile(ranNum, 2);
	}
}

void SetTestList::listToArray(int l, int *arr) {
	string line;
	int count = 0;
	std::ifstream myfile(_caseList[l]);
	while(getline(myfile, line)) {
		arr[count] = stoi(line); // conver string to int!!!! and make array
		count++;
	} 	 
}
#endif
