#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void initDataset(uint32_t* arr, uint32_t size) {
	for (uint32_t i = 0; i < size; i++) {
		arr[i] = rand() % 400 + 10;
		cout << arr[i] << "\n";
	}
}

void sortArrays(uint32_t* arr, uint32_t size) {
	bool isSorted = false;
	uint32_t sortedElements = 0;
	while (!isSorted) {
		for (uint32_t i = 0; i < (size - 1) - sortedElements; i++) {
			if (arr[i] > arr[i + 1]) {
				uint32_t saveNr = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = saveNr;
			}
		}
		sortedElements++;
		if (sortedElements == size) isSorted = true;
	}
	cout << "done" << "\n";
	for (uint32_t i = 0; i < size; i++) {
		cout << arr[i] << "\n";
	}
}

double findMedian(uint32_t* arr, uint32_t size) {
	if (size & 1) {
		// * 0.f?
		if (size > 1) return arr[size >> 1];
		else return arr[0];
	}
	else {
		return (arr[size >> 1] + arr[(size >> 1) - 1]) / 2.f;
	}
}

void mergeArrays(uint32_t* arr1, uint32_t arr1Size, uint32_t* arr2, uint32_t arr2Size) {
	uint32_t arr3[64] = {0};
	uint32_t j = 0, k = 0;
	for (uint32_t i = 0; i < (arr1Size + arr2Size); i++) {
		if (arr1[j] < arr2[k]) {
			arr3[i] = arr1[j];
			j++;
		}
		else {
			arr3[i] = arr2[k];
			k++;
		}
	}
	for (uint32_t i = 0; i < 64; i++) {
		cout << arr3[i] << "\n";
	}
	cout << "\n";
	cout << "Median: " << findMedian(arr3, (arr1Size + arr2Size)) << "\n";
}

int main(void) {
	cout << fixed;
	srand(time(NULL));
	const unsigned int elementCount = 32;
	uint32_t dataSet[elementCount];
	uint32_t dataSet2[elementCount];
	
	cout << "Array 1 " << "\n";
	initDataset(dataSet, elementCount);
	cout << "Array 2 "<< "\n";
	initDataset(dataSet2, elementCount);

	cout << "Sorting Arrays..." << "\n";
	cout << "Array 1 " << "\n";
	sortArrays(dataSet, elementCount);
	cout << "Array 2 " << "\n";
	sortArrays(dataSet2, elementCount);

	cout << "Merging Arrays..." << "\n";
	mergeArrays(dataSet, elementCount, dataSet2, elementCount);

	while (1);
}


