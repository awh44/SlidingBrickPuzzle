# SlidingBrickPuzzle
Program for a SlidingBrickPuzzle done for an AI course.

Currently, two different drivers can be use to run the program, and they can be run using the
makefile, using the following targets:
	[MOVES=x] make random  - this will run the driver drivers/random.c, which does a RandomWalk of a
	                         SlidingBrickPuzzle, making a random move of a piece for x number of
	                         moves (or, if MOVES=x is ommitted, 20 moves)
	          make correct - this will run the driver drivers/correct.c, and will write the results to
	                         results/results.test. Runs tests on the SlidingBrickPuzzle and related classes
