#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> bucket;

// Cycle sort 
void cycle_sort(int arr[], int n)
{
	// count number of memory writes 
	int writes = 0;

	// traverse array elements and put it to on 
	// the right place 
	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
		// initialize item as starting point 
		int item = arr[cycle_start];

		// Find position where we put the item. We basically 
		// count all smaller elements on right side of item. 
		int pos = cycle_start;
		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item)
				pos++;

		// If item is already in correct position 
		if (pos == cycle_start)
			continue;

		// ignore all duplicate  elements 
		while (item == arr[pos])
			pos += 1;

		// put the item to it's right position 
		if (pos != cycle_start) {
			swap(item, arr[pos]);
			writes++;
		}

		// Rotate rest of the cycle 
		while (pos != cycle_start) {
			pos = cycle_start;

			// Find position where we put the element 
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos += 1;

			// ignore all duplicate  elements 
			while (item == arr[pos])
				pos += 1;

			// put the item to it's right position 
			if (item != arr[pos]) {
				swap(item, arr[pos]);
				writes++;
			}
		}
	}
}

// Comb sort
void comb_sort(int arr[], int n) {
	int gap = n - 1;
	while (gap > 0) {
		for (int i = 0; i + gap< n; i++) {
			if (arr[i] > arr[i + gap])
				swap(arr[i], arr[i + gap]);
		}
		if (gap == 1 || gap == 1.3)
			return;
		gap = gap / 1.3;
		if (gap < 1 && gap > 0)
			gap = 1;
	}
}

// Radix sort
int count_number(int val) {
	int count = 0;
	while (val) {
		val /= 10;
		count++;
	}
	return count;
}

int get_num_at_n(int val, int n) {
	if (n == 0)
		return -1;
	if (val < pow(10, n - 1))
		return 0;
	val = val % int(pow(10, n));
	while (val >= 10)
		val /= 10;
	return val;
}


void radix_sort(int arr[], int size) {
	// find max element
	int max;
	for (int i = 0; i < size; i++) {
		if (i == 0)
			max = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int max_number = count_number(max);
	int i = max_number;
	vector<bucket> number;
	number.resize(10);

	int count = 1;
	
	while (count <= max_number) {
		int index = 0;
		int id = 0;
		// put element in arr into number arr 2D
		for (int i = 0; i < size; i++) {
			index = get_num_at_n(arr[i], count);
			number[index].push_back(arr[i]);
		}
		// put in to arr
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < number[i].size(); j++) {
				arr[id++] = number[i][j];
			}
		}
		// clear matrix
		for (int i = 0; i < 10; i++) {
			if (number[i].size() != 0)
				number[i].clear();
		}
		//
		count++;
	}
}

int main()
{
	int arr[] = { 121, 432, 564, 23, 1, 45, 788 };
	int size = sizeof(arr) / sizeof(int);
	radix_sort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
