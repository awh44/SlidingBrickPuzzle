# SlidingBrickPuzzle
Program for a SlidingBrickPuzzle done for an AI course.

Currently, two different drivers can be use to run the program, and they can be run using the
makefile, using the following targets:
	[MOVES=x [FILE=y]] make random  - this will run the driver drivers/random.c, which does a RandomWalk of a
	SlidingBrickPuzzle, making a random move of a piece for x number of moves (or, if MOVES=x is
	omitted, 20 moves). It will use as the input file y. Note that if the FILE variable is to be
	used, MOVES must be specified as well.
	
	make correct - this will run the driver drivers/correct.c, and will write the results to
	results/results.test. Runs tests on the SlidingBrickPuzzle and its related classes

Please see the headers for comments on the individual functions and their usages. Also included in
the headers are comments on the classes themselves.
