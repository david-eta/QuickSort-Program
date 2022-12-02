#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include "qsort.h"
#include "InputFileGenerator.h"


using namespace std;

int main() {

    int input_size;
    char cont;
    unordered_map<int, double*> average_map;
    // double* time[2] where time[0] holds total time, time[1] holds number of occurences
    
    while(tolower(cont) != 'n') {
	
        // # of numbers in each file (one unsorted array per file)
	    cout << "Input size: ";
        cin >> input_size;
	    if(input_size <= 0)
	        break;
        
        double exec_time = 0;
        float arr[input_size];
        // srand48(time(NULL)); // buffer

        for(int i = 0; i < 25; i++) { // 25 input files with the same input size (array length)
            for(int j=0; j<input_size; j++) // populate array
                arr[j] = 100*drand48()/drand48(); // generate random value
            
            auto start = std::chrono::high_resolution_clock::now();
            quickSort(0,input_size-1,arr); // run quicksort
            auto time_taken = std::chrono::high_resolution_clock::now() - start;
            double nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(time_taken).count();
            exec_time += nanoseconds;
        }
        record_value(input_size, (exec_time/1000000), "Eta_David_executionTime.txt");
        
        // update averages map
        if (average_map.find(input_size) == average_map.end()) { // check if input size has been used before
            double val[] = {exec_time, 1.0};
            average_map[input_size] = val; // create new input size instance
        } 
        else { // add to 
            double val[] = {(average_map.at(input_size)[0] + exec_time), (average_map.at(input_size)[1] + 1.0)};
            average_map[input_size] = val;
        }


        cout << "again? (y/n) " << endl;
        cin >> cont;
    }
    

    // add averages to txt file
    for (auto x : average_map) {
        double avg = (x.second[0]/x.second[1]) / 1000000;
        record_value(x.first, avg, "Eta_David_averageExecutionTime.txt");
        // cout << "It took an average of " << to_string(avg) << " milliseconds to sort 25 "
    }
    return 0;
}
