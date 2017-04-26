
#ifndef SORTALGS_H
#define SORTALGS_H

#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<iostream>

using std::cout;
using std::endl;

class SortAlgs {
private:
	clock_t   _start, _end;  // available when ctime is included
    double    _duration;
public:
	void bubbleSort(int, int*);
};

void SortAlgs::bubbleSort(int len, int *arr) {
		_start = clock(); // start timing
		
		int swap, temp;
		for(int i = 0; i < len; i++) {
			swap = 0;
			for(int j = 0; j < len; j++) {
				if(arr[j] < arr[j-1]) {
					swap = 1;
					temp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = temp;
				}	
			}
			if(swap==0) {
				break;
			}
		}
		_end = clock(); // end timing
		_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
		cout << _duration << endl;
	}

#endif
