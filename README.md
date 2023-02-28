# Comparing Sorting Algorithms

## Short Description:
	This program tests the performance of 4 sorting algorithms, Batcher Sort, 
	Heap Sort, Quick Sort, and Shell Sort. It runs these algorithms with 
	seeded, pseudorandom arrays of integers and keep track of statistics
	including the number of moves (anytime a value in the array is repositioned) 
	and how many compares (anytime 2 values in the array are compared to each other) 
	and provides those statistics to the user after running the algorithm 
	in order to track performance.
 
## Build:
	To build the program, run '$ make', '$ make all', or '$ make sort' 
	in the terminal within the sorting directory. This will create
	and executable named 'sorting' which can be run with optional arguments.

## Cleaning:
	In order to clean the directory after creating the executable,
	simply run '$ make clean' and the 'sorting' executable along with
	any .o files will be removed from the directory.

## Running:
	To run the executable, type './sorting' followed by any of the following
	optional arguments.
	-a : run all sorting algorithms
	-b : run batcher sorting algorithm
	-h : run heap sorting algorithm
	-q : run quick sorting algorithm
	-s : run shell sorting algorithm
	-n [size] : set the size of the array to be sorted
	-r [seed] : set the seed of the random array
	-p [elements] : set the number of elements of the
					sorted array to display after sorting
	-H : show SYNOPSIS and USAGE of program
