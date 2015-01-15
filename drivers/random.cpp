#include <iostream>

#include "../src/SlidingBrickPuzzle.h"
#include "../src/Walk.h"
#include "../src/RandomWalk.h"

int main(void)
{
	SlidingBrickPuzzle puzzle;
	std::cout << "Doing a RandomWalk of level0:" << std::endl;
	puzzle.load_game("input/SBP-level0.txt");
	Walk *walk = new RandomWalk(puzzle, 20);
	walk->walk();

}
