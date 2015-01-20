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

	std::string file = "input/SBP-level0.txt";
	if (argc > 2)
	{
		file = argv[2];
	}

	SlidingBrickPuzzle puzzle;
	std::cout << "Doing a RandomWalk of level0:" << std::endl;
	if (!puzzle.load_game(file))
	{
		std::cout << "Error loading input file. Terminating." << std::endl;
		return 1;
	}

	Walk *walk = new RandomWalk(puzzle, max_moves);
	walk->walk();

	delete walk;
	return 0;
}
