
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
	void printToFile(int, int);
public:
	TestList();
	void bestCase(int);
	void worstCase(int);
	void averageCase(int); //
	void listToArray(int, int*);
};

TestList::TestList() {
	srand(time(0));	
}

void TestList::printToFile(int i, int l) {	
	std::ofstream myfile(_caseList[l], std::ios::app);
	if (myfile.is_open()) {
		myfile << i << "\n";
		myfile.close();
	}
}

void TestList::bestCase(int len) {
	// creat empty file
	std::ofstream myfile(_caseList[0]);
	myfile.close();
	
	for(int i = 1; i <= len; i++) {
		printToFile(i, 0);
	}
}

void TestList::worstCase(int len) {
	// creat empty file
	std::ofstream myfile(_caseList[1]);
	myfile.close();
	
	for(int i = len; i > 0; i--) {
		printToFile(i, 1);
	}
}

void TestList::averageCase(int len) {
	// creat empty file
	std::ofstream myfile(_caseList[2]);
	myfile.close();
	
	int ranNum;	
	for(int i = 1; i <= len; i++) {
		ranNum = (rand()%len+1);
		printToFile(ranNum, 2);
	}
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
}
#endif
