run: brick.out
	./brick.out

debug: brick.out
	gdb ./brick.out

brick.out: main.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp src/Move.h src/Move.cpp
	g++ -obrick.out -g -Wall -std=gnu++11 main.cpp src/SlidingBrickPuzzle.cpp src/Move.cpp
