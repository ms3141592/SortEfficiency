
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
	clock_t _start, _end;  // available when ctime is included
    double _duration;
    void quickSort(int, int, int*);
public:
	double bubbleSort(int, int*);
	void insertionSort(int, int*);
	void quickSortCall(int, int*);
};

double SortAlgs::bubbleSort(int len, int *arr) {
	_start = clock(); // start timing
	
	int swap, temp;
	for(int i = 0; i < len; i++) {
		swap = 0;
		for(int j = 0; j < len; j++) {
			if(arr[j] < arr[j-1]) {
				swap = 1; // the array is not yet sorted
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}	
		}
		if(swap==0) { // the array is sorted 
			break;
		}
	}
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
	//cout << _duration << endl;
	return _duration;
}
	
void SortAlgs::insertionSort(int len, int *arr) {
	_start = clock(); // start timing
	
	int j, index;
	
	for(int i = 1; i < len; i++) {
		index = arr[i];
		j = i;
		
		while( (j > -1) && (arr[j-1] > index)) {
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = index;		
	}
	
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
	cout << _duration << endl;
}

void SortAlgs::quickSort(int min, int max, int *arr) {
	int pivot, _min, _max;
	
	_min = min;
	_max = max;
	pivot = arr[min];
	
	while(min < max) {
		while( (arr[max] >= pivot) && (min < max)) {
			max--;
		}
		if (min != max) {
			arr[min] = arr[max];
			min++;
		}
		while( (arr[min] <= pivot) && (min < max)) {
			min++;
		}
		if(min != max) {
			arr[max] = arr[min];
			max--;
		}		
	}
	
	arr[min] = pivot;
	int m_pivot = min;
	int m_min = _min;
	int m_max = _max;
	
	if(m_min < m_pivot) {
		quickSort(m_min, m_pivot-1, arr);
	}
	if(m_max > m_pivot) {
		quickSort(m_pivot+1, m_max, arr);
	}	
}

void SortAlgs::quickSortCall(int len, int *arr) {
	_start = clock(); // start timing
	
	quickSort(0, len, arr);
	
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
	cout << _duration << endl;
}
#endif
