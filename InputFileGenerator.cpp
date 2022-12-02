
#include "InputFileGenerator.h"
#include <iostream>

using namespace std;

int main(int argc, char **arg) {

    int input_size;
    cout << "Input size: ";
    cin >> input_size;

    createFiles(input_size);

    return 0;
}