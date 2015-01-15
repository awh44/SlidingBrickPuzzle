#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "../src/SlidingBrickPuzzle.h"
#include "../src/Walk.h"
#include "../src/RandomWalk.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	size_t max_moves = 20;
	if (argc > 1)
	{
		max_moves = std::stoi(argv[1]);
	}

	SlidingBrickPuzzle puzzle;
	std::cout << "Doing a RandomWalk of level0:" << std::endl;
	puzzle.load_game("input/SBP-level0.txt");
	Walk *walk = new RandomWalk(puzzle, max_moves);
	walk->walk();

	return 0;
}
