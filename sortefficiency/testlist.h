
#ifndef TESTLIST_H
#define TESTLIST_H

#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

using std::cout;
using std::string;
using std::endl;

class TestList {
private:
	string _caseList[3] = {"best_case.txt", "worst_case.txt", "average_case.txt"};
public:
	TestList();
	void bestCase(int);
	void worstCase(int);
	void averageCase(int); //
	void listToArray(int, int*);
};

TestList::TestList() {
	srand(time(0));
	std::ofstream myfile(_caseList[0]);
	myfile.close();
	
	myfile.open(_caseList[1]);
	myfile.close();	
	
	myfile.open(_caseList[2]);
	myfile.close();	
}

void TestList::bestCase(int len) {

	std::ofstream myfile(_caseList[0], std::ios::app);
	
	for(int i = 1; i <= len; i++) {
		if (myfile.is_open()) {
			myfile << i << "\n";		
		}
	}
	myfile.close();
}

void TestList::worstCase(int len) {
	std::ofstream myfile(_caseList[1], std::ios::app);
	for(int i = len; i > 0; i--) {
		if (myfile.is_open()) {
			myfile << i << "\n";		
		}
	}
	myfile.close();
}

void TestList::averageCase(int len) {
	std::ofstream myfile(_caseList[2], std::ios::app);
	int ranNum;	
	for(int i = 1; i <= len; i++) {
		ranNum = (rand()%len+1);
		if (myfile.is_open()) {
			myfile << ranNum << "\n";		
		}
	}
	myfile.close();
}

void TestList::listToArray(int l, int *arr) {
	string line;
	int count = 0;
	int i_line;
	std::ifstream myfile(_caseList[l]);
	while(getline(myfile, line)) {
		std::istringstream (line) >> i_line; // conver string to int!!!!
		arr[count] = i_line;// make int array
		//arr[count] = stoi(line); // conver string to int!!!! and make array
		count++;
	} 	 
	myfile.close();
}
#endif
