/* Sort Algorithm day-02 */

// Quick Sort Partition (Quick Sort phân vùng)
int partition(int* Arr[], int low, int high){
	int pivot_value = Arr[high];
	int i = low - 1;
	for(int j = low; j < high - 1; j++){
		if(Arr[j] <= pivot_value){
			i++;
			swap(Arr[i], Arr[j]);
		}
	}
	swap(Arr[i + 1], Arr[high]); // pivot is locate at correcttion index
	return i + 1;
}

void quick_sort(int* Arr[], int low, high){
	if(low < high){
		int pivot_index = partition(Arr, low, high);
		quick_sort(Arr, low, pivot_index - 1);
		quick_sort(Arr, pivot_index + 1, high);
	}

}
// Merg Sort array

void merg(int* Arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1];
	int *R = new int[n2];
	for (i = 0; i < n1; i++) {
		L[i] = Arr[i + l];
	}
	for (j = 0; j < n2; j++) {
		R[j] = Arr[j + m + 1];
	}
	i = j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			Arr[k] = L[i];
			i++;
		}
		else {
			Arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		Arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		Arr[k] = R[j];
		j++;
		k++;
	}


}

void merg_sort(int* Arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merg_sort(Arr, l, m);
		merg_sort(Arr, m + 1, r);

		merg(Arr, l, m, r);
	}
	return;
}

// Merg Sort with Linked List

node* merg_sort(node*& pHead) {
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	node* temp = pHead;
	node* fast = pHead;
	node* slow = pHead;
	while (fast != nullptr && fast->next != nullptr ) {
		temp = slow; // slow is tail node of first partition
		slow = slow->next; // head node of second partition
		fast = fast->next->next; 
	}
	temp->next = nullptr;
	node* left_side = merg_sort(pHead);
	node* right_side = merg_sort(slow);

	return merg(left_side, right_side);
}

node* merg(node* left, node* right) {
	node* temp = new node;
	temp->data = 0;
	node* pCurent = temp;
	while (left != nullptr && right != nullptr) {
		if (left->data < right->data) {
			pCurent->next = left;
			left = left->next;
		}
		else {
			pCurent->next = right;
			right = right->next;
		}
		pCurent = pCurent->next;
	}

	if (left != nullptr) {
		pCurent->next = left;
		left = left->next;
	}

	if (right != nullptr) {
		pCurent->next = right;
		right = right->next;
	}
	return temp->next;
}