run: brick.out
	./brick.out

brick.out: main.cpp SlidingBrickPuzzle.h SlidingBrickPuzzle.cpp
	g++ -obrick.out -std=gnu++11 main.cpp SlidingBrickPuzzle.cpp
