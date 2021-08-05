/* Daily sorting: Day_03*/

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

					   // If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// Bucket sort 

typedef vector<float> Arr;
typedef vector<int> Arr_i;

void bucket_sort_float(float arr[], int size) {
	vector<Arr> C;
	C.resize(size);
	for (int i = 0; i < size; i++) {
		int bi = size*arr[i]; // bi is index of its bucket
		C[bi].push_back(arr[i]);
	}
	for (int i = 0; i < size; i++) {
		sort(C[i].begin(), C[i].end());
	}
	int index = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < C[i].size(); j++) {
			arr[index++] = C[i][j];
		}
	}

}

void bucket_sort_int(int arr[], int size) {
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	float range = float((max - min)) / size; // range is the number of each bucket
	vector<Arr_i> C;
	C.resize(size + 1);
	for (int i = 0; i < size; i++) {
		int ci = float((arr[i] - min))/ range;
		C[ci].push_back(arr[i]);
	}
	for (int i = 0; i < size + 1; i++) {
		sort(C[i].begin(), C[i].end());
	}
	int index = 0;
	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < C[i].size(); j++) {
			arr[index++] = C[i][j];
		}
	}
}

//  counting sort
void counting_sort(int arr[], int size) {
	int max_val = 0;
	for (int i = 0; i < size; i++) {
		if (i == 0)
			max_val = arr[0];
		if (max_val < arr[i])
			max_val = arr[i];
	}
	int* count_arr = (int*)(malloc((max_val + 1)*sizeof(int)));
	memset(count_arr, 0, sizeof(int)*(max_val + 1));
	for (int i = 0; i < size; i++) 
		count_arr[arr[i]]++;
	for (int i = 1; i <= max_val; i++) 
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	int* result_arr = new int[size];
	for (int i = 0; i < size; i++) {
		result_arr[count_arr[arr[i]] - 1] = arr[i];
		--count_arr[arr[i]];
	}
	for (int i = 0; i < size; i++) {
		arr[i] = result_arr[i];
	}
	delete[] count_arr, result_arr;
}