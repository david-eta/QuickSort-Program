
void quickSort(int l, int r, float arr[]) {
	// base case
	if(l >= r)
		return;
	
	// i and j indexes
	int i_idx = l;
	int j_idx = r;
	float temp;
	
	while(i_idx < j_idx) {
		// Traverse from left to right until arr[i] > arr[l]
        for(int i = i_idx+1; i <= r; i++) {
            if(arr[i] > arr[l]) {
                i_idx = i;
				break;
			}
			if(i==r) 
				i_idx = r;
		}

		// Traverse from right to left until arr[j] < arr[l]
		for(int j = j_idx; j >= l; j--) {
			if(arr[j] < arr[l]) {
				j_idx = j;
				break;
			}
			if(j==l) 
				j_idx = l;
		}	

		// swap arr[i] and arr[j]
		temp = arr[i_idx];
		arr[i_idx] = arr[j_idx];
		arr[j_idx] = temp;
		
	}

	// once i >= j (while loop ends), swap arr[l] with arr[j] 
	temp = arr[l];
	arr[l] = arr[j_idx];
	arr[j_idx] = temp;

	// Recursively call quicksort on the array's left and right partitions 
	quickSort(l, j_idx-1, arr);
	quickSort(j_idx+1, r, arr);
}
