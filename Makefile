CC = gcc
CXX = g++
CFLAGS = -c -Wall
CXXFLAGS = -c -Wall

all: start

start: main.o testing.o shell_sort.o bubble_sort.o insertion_sort.o selection_sort.o heap_sort.o recursive_merge_sort.o interactive_merge_sort.o lomuto_sort.o hoar_sort.o thick_sort.o lsd_sort.o msd_sort.o
	$(CXX) main.o testing.o shell_sort.o bubble_sort.o insertion_sort.o selection_sort.o heap_sort.o recursive_merge_sort.o interactive_merge_sort.o lomuto_sort.o hoar_sort.o thick_sort.o lsd_sort.o msd_sort.o -o result.exe

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

heap_sort.o: sortings/heap_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/heap_sort.cpp

recursive_merge_sort.o: sortings/recursive_merge_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/recursive_merge_sort.cpp

interactive_merge_sort.o: sortings/interactive_merge_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/interactive_merge_sort.cpp
	
lomuto_sort.o: sortings/lomuto_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/lomuto_sort.cpp

hoar_sort.o: sortings/hoar_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/hoar_sort.cpp

thick_sort.o: sortings/thick_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/thick_sort.cpp

lsd_sort.o: sortings/lsd_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/lsd_sort.cpp

msd_sort.o: sortings/msd_sort.cpp
	$(CXX) $(CXXFLAGS) sortings/msd_sort.cpp

clean:
	rm -rf *.o result.exe
