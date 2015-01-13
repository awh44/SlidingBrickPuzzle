run: brick.out
	./brick.out

brick.out: main.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp
	g++ -obrick.out -std=gnu++11 main.cpp src/SlidingBrickPuzzle.cpp
