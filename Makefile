all:
	g++ -Wall -std=c++11 main.cpp

clean: 
	rm *.o output
	rm 1*.txt
	rm ./a.out
	
