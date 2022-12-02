// David Eta
// CSCE 350 Project

#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include "qsort.h"
#include "InputFileGenerator.h"


using namespace std;

void record_value(int inpt_size, double val, string file_name);
void compile(int input_size);

int main(int argc, char **arg) { 
    
    compile(10);
    compile(100);
    compile(1000);
    return 0;
}


void compile(int input_size) {

    // create file of random numbers
    createFiles(input_size);

    double exec_time, total_exec_time = 0;

    for (int i = 0; i < 25; i++) {
        
        // initialise file
        ifstream in_file;
        string filename = "input_files/size_" + std::to_string(input_size) + '/'+std::to_string(input_size)+'_'+std::to_string(i+1)+".txt";
	    in_file.open(filename);

        // populate table
        int n = 0;
        float num;
        float arr[input_size];
        while(in_file >> num)
            arr[n] = num;
        
        // -- run quicksort and time it --
        auto start = std::chrono::high_resolution_clock::now();
        // run quicksort
        quickSort(0, input_size-1, arr);
        // calculate time
        auto time_taken = std::chrono::high_resolution_clock::now() - start;
        double nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(time_taken).count();
        exec_time += nanoseconds;

        // record value in text file
        record_value(input_size, (exec_time/1000000), "Eta_David_executionTime.txt");
        // increment
        total_exec_time += nanoseconds;
    }
    // record value of average time for this input size in text file
    record_value(input_size, (total_exec_time/1000000)/25, "Eta_David_averageExecutionTime.txt");
}


void record_value(int input_size, double value, string filename) {
    ofstream file;
    file.open(filename, ios_base::app); // file.open(filename);
    file << input_size << "    " << value << "\n";
    file.close();
}