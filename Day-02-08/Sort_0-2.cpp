/* Sorted algorithm  Day 01 */

// selection sort -- Target find min index in i = 0,1,... -> n

void selection_sort(int *Arr[], int n){
	int min_index;
	for(int i = 0; i < n - 1; i++){
		min_index = i;
		for(int j = i + 1; j < n; j++){
			if(Arr[min_index] > Arr[j])
				min_index = j;
		}
		if(min_index != i)
			swap(Arr[min_index], Arr[i]);
	}
}

// burble sort -- Target compare two elements i vs i + 1, max element will in the end index

void burble_sort(int *Arr[], int n){
	bool is_sorted;
	for(int i = 0; i < n - 1; i++){
		is_sorted = true;
		for(j = 0; j < n - i - 1; j++){
			if(Arr[j] > Arr[j + 1]){
				swap(Arr[j], Arr[j + 1]);
				is_sorted = false;
			}	
		}
		if(is_sorted)
			break;
	}
}


// Insertion sort -- Target find true index in i = 1, 2, 3 -> 0 and insert next to the wrong index

void insertion_sort(int *Arr[], int n){
	int value_at_i;
	for(int i = 1; i < n; i++){
		while(Arr[i - 1] <= Arr[i] && i < n)
			i++;
		value_at_i = Arr[i];
		j = i - 1;
		while(Arr[j] > value_at_i && j + 1 < n && j >= 0){
			Arr[j + 1] = Arr[j];
			j--; 
		}
		Arr[j + 1] = value_at_i;
	}
}

// Insertion sort for singly linked list -- Target

void sorted_Insert(node*& newHead, node* pCurent){
	node* headDummy = nullptr;
	if(newHead == nullptr || pCurent->val <= newHead->value){
		pCurent->next = newHead;
		newHead = pCurent;
	}
	else{
		headDummy = newHead;
		while(headDummy->next != nullptr && headDummy->next->val < pCurent->val)
			headDummy = headDummy->next;
		pCurent->next = headDummy->next;
		headDummy->next = pCurent;
	}
}

void insertion_sort_LL(node* &pHead){
	if(pHead == nullptr)
		return;
	node* Next = nullptr;
	node* pCurent = pHead;
	node* newHead = nullptr;
	while(pCurent != nullptr){
		Next = pCurent->next;
		sorted_Insert(newHead, pCurent);
		pCurent = Next; // pCurent->next may be changes in function sorted_Insert
	}
	pHead = newHead; // update new head if have any change
}

