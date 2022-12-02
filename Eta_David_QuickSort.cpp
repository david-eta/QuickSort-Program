// David Eta
// CSCE 350 Project

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

void quickSort(int l, int r, float *arr);

int main(int argc, char **arg) {

	// Read file into array

	ifstream in_file;
	in_file.open("input.txt");
	int n = 0;
	float num;
	while(in_file >> num)
		n++; // what is n? Number of lines/values?
	float arr[n];
	
	n = 0;
	while(in_file >> num){
		arr[n] = num;
		n++;
	}

	//Run quickSort and time the process
	
	auto start = std::chrono::high_resolution_clock::now();
	quickSort(0,n-1,arr);
	auto time_taken = std::chrono::high_resolution_clock::now() - start;
	double nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(time_taken).count();
	// convert to string and to milliseconds
	string milliseconds = ("Running Quicksort on the list took: " +  to_string(nanoseconds/1000000) + " milliseconds");
	cout << milliseconds << endl;;

	//Print output to output.txt
	ofstream out_file;
	out_file.open("output.txt");
	for(int i=0; i < n; i++) {
		out_file << arr[i] << " ";
	}
	out_file << endl;
	out_file << milliseconds << "\n" << endl;
	out_file.close();	
}

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
