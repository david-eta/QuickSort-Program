
# QuickSort Program

This is a program that runs the quicksort algorithm to sort randomly created sets of numbers.

## Description

The main.cpp file requires no user input while the other_option.cpp file does. Details explained below.


## Getting Started

### Dependencies

* IDE of Choice
* C++ installed
* Works on Windows 10, Windows 11, Mac OS and Ubuntu.


## Executing program

### qsort.h
This sorts an array using the quicksort algorithm.


### InputFileGenerator.h
This generates a files with x number of random values between -500 and 500. Where x is the input size.


### main.cpp
Run:
```
> g++ -Wall -std=c++11 main.cpp
> ./a.out
```
in the terminal.

This will call the InputFileGenerator program to create 25 files for each input file then
calcluate how long it takes to sort each file and the average per input size. For the purpose of this exercise, the only input sizes used are 10, 100 and 1000.

These values are recorded in "Eta_David_executionTime.txt" and"Eta_David_averageExecutionTime.txt" respectively.


# other_option.cpp
Run:
```
> g++ -Wall -std=c++11 other_option.cpp
> ./a.out
```
in the terminal.

This works the exact same way as main.cpp except it generates its own arrays and does not read from randomly generated files.
It also allows the user to specify any input size as many times as they want.


### Eta_David_averageExecutionTime.txt
If the program does not run, be sure to create this file and make sure it is empty before running it.
This holds the average time each set of 25 files of a number of numbers takes to be sorted in milliseconds.


### Eta_David_executionTime.txt
If the program does not run, be sure to create this file and make sure it is empty before running it.
This holds how long it takes to run quicksort on each file in milliseconds. 


### Makefile
This can run the main.cpp file exactly as it should be run as well as clean out the other files before starting a new session.

## Author

[David Eta](https://github.com/david-eta/)
