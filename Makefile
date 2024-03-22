CC = gcc
CXX = g++
CFLAGS = -c -Wall
CXXFLAGS = -c -Wall

all: start

start: main.o testing.o shell_sort.o bubble_sort.o insertion_sort.o selection_sort.o
	$(CXX) main.o testing.o shell_sort.o bubble_sort.o insertion_sort.o selection_sort.o -o result.exe

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

testing.o: tests/testing.cpp
	$(CXX) $(CXXFLAGS) tests/testing.cpp

shell_sort.o: sortings/shell_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/shell_sort.cpp

bubble_sort.o: sortings/bubble_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/bubble_sort.cpp

insertion_sort.o: sortings/insertion_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/insertion_sort.cpp

selection_sort.o: sortings/selection_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/selection_sort.cpp


clean:
	rm -rf *.o result.exe
