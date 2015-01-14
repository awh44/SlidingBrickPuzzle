PAGER=less
COMP=g++
DEBUG=gdb

.PHONY: view-results

view-results: results/results.test
	@$(PAGER) results/results.test

results/results.test: brick.out
	@./brick.out > results/results.test

debug: brick.out
	@$(DEBUG) ./brick.out

brick.out: main.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp src/Move.h src/Move.cpp
	@$(COMP) -obrick.out -g -Wall -std=gnu++11 main.cpp src/SlidingBrickPuzzle.cpp src/Move.cpp
