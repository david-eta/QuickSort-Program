// David Eta
// CSCE 350 Project

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <unordered_map>

using namespace std;

void createFiles(int input_size) {

    for (int i = 0; i < 25; i++) {
        
        ofstream file;
        // string filename = "input_files/size_" + std::to_string(input_size) + '/'+std::to_string(input_size)+'_'+std::to_string(i+1)+".txt";
        string filename = std::to_string(input_size)+'_'+std::to_string(i+1)+".txt";
        file.open(filename);

        for(int j=0; j < input_size; j++) {// populate array
            // random float between -500 and 500
            float x = -500 + static_cast <float>(rand() / static_cast <float>(RAND_MAX/(500-(-500))));
            // write into file
            file << x << "    ";
        }
        file.close();
    }
}