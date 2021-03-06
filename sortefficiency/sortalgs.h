
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
	double insertionSort(int, int*);
	double quickSortCall(int, int*);
	double selectionSort(int, int*);
};

double SortAlgs::bubbleSort(int len, int *arr) {
	_start = clock(); // start timing
	
	int swap, temp;
	for(int i = len-1; i > 0; i--) {
		swap = 0;
		for(int j = 1; j <= i; j++) {
			if(arr[j-1] > arr[j]) {
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
	cout << _duration << endl;
	//cout << "\t" << len << endl;
	return _duration;
}
	
double SortAlgs::insertionSort(int len, int *arr) {
	_start = clock(); // start timing
	
	int j, index;
	
	for(int i = 1; i < len; i++) {
		index = arr[i];
		j = i;
		
		while( (j > 0) && (arr[j-1] > index)) {
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = index;		
	}
	
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds	
	cout << _duration << endl;	
	return _duration;
}

void SortAlgs::quickSort(int min, int max, int *arr) {
	int pivot, _min, _max;
	
	_min = min;
	_max = max;
	pivot = arr[min];
	
	while(min < max) {
		while( (arr[max] >= pivot) && (min < max) ) {
			max--;
		}
		if (min != max) {
			arr[min] = arr[max];
			min++;
		}
		while( (arr[min] <= pivot) && (min < max) ) {
			min++;
		}
		if(min != max) {
			arr[max] = arr[min];
			max--;
		}
	}
	arr[min] = pivot;
	pivot = min;
	min = _min;
	max = _max;
	if(min < pivot) {
		quickSort(min, pivot-1, arr);
	}
	if(max > pivot) {
		quickSort(pivot+1, max, arr);
	}

}

double SortAlgs::quickSortCall(int len, int *arr) {
	_start = clock(); // start timing
	
	quickSort(0, len-1, arr);
	
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
//	cout << _duration << endl;
	return _duration;
}

double SortAlgs::selectionSort(int len, int *arr) {
	_start = clock(); // start timing
	int min, temp;
	
	for(int i = 0; i < len-1; i++) {
		min = i;
		for(int j = i+1; j < len; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	_end = clock(); // end timing
	_duration = ((double)(_end - _start))/CLOCKS_PER_SEC; // compute to seconds		
//	cout << _duration << endl;
	return _duration;
}
#endif
