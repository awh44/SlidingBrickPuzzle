# SlidingBrickPuzzle
Program for a SlidingBrickPuzzle done for an AI course.

Currently, two different drivers can be use to run the program, and they can be run using the
makefile, using the following targets:
	
	STRAT=x [FILE=y [MOVES=z]] make walk - this will perform a walk of the given
	input file y (using input/SBP-leve0.txt if FILE is ommitted) using the search
	strategy specified by x (b for breadth first, d for depth first, a for A*, l
	for depth limited, i for iterative deepening, and r for random). For searches
	that require a maximum number of moves (depth limited, iterative deepening,
	random), the MOVES parameter will specify this. Note that if MOVES is
	specified, FILE has to be specified too.
 	
	make correct - this will run the driver drivers/correct.c, and will write the
	results to results/results.test. Runs tests on the SlidingBrickPuzzle and its
	related classes.

The make clean target can be used to remove the output files and the intermediate .o files.

Please see the headers for comments on the individual functions and their usages. Also included in
the headers are comments on the classes themselves.

Note that the results for breadth first and depth first searches on the first several input files
are stored in results/output-breadth-depth.txt. Results for BreadthFirst on SBP-levels 0, 1, 2,
and 3 are stored, but results for DepthFirst on levels 0, 1, and 2 only are stored, because
DepthFirst (given at least half an hour to search) could not find the solution. Simlar results
are stored in results/output-iterative.txt for IterativeDeepening, but the results here are worse,
with only level0 able to be solved. Similar resuls for A*, for levels 0, 1, 2, and 3, as well as
for bricks levels 1 through 7 are stored in results/output-part2.txt.
