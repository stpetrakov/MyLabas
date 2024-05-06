CC = gcc
CXX = g++
CFLAGS = -c -Wall
CXXFLAGS = -c -Wall

all: start

start: main.o tests.o binary_heap.o
	$(CXX) main.o tests.o binary_heap.o -o result.exe

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

tests.o: Tests/tests.cpp
	$(CXX) $(CXXFLAGS) Tests/tests.cpp

binary_heap.o: Heaps/binary_heap.cpp
	$(CXX) $(CXXFLAGS) Heaps/binary_heap.cpp

clean:
	rm -rf *.o result.exe