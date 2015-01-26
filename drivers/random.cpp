#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "../src/SlidingBrickPuzzle.h"
#include "../src/Walk.h"
#include "../src/RandomWalk.h"
#include "../src/BreadthFirstWalk.h"
#include "../src/DepthFirstWalk.h"
#include "../src/IterativeDeepeningWalk.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc < 1)
	{
		std::cout << "Please include the search type as the first commandl ine argument." << std::endl;
		return 1;
	}

	std::string file = "input/SBP-level0.txt";
	if (argc > 2)
	{
		file = argv[2];
	}

	SlidingBrickPuzzle puzzle;
	if (!puzzle.load_game(file))
	{
		std::cout << "Error loading input file. Terminating." << std::endl;
		return 1;
	}
	
	Walk *walk;
	size_t max_moves = 20;
	switch (argv[1][0])
	{
		case 'B':
		case 'b':	
			walk = new BreadthFirstWalk(puzzle);
			break;
		case 'D':
		case 'd':
			walk = new DepthFirstWalk(puzzle);
			break;
		case 'I':
		case 'i':
			if (argc > 3)
			{
				max_moves = std::stoi(argv[3]);
			}

			walk = new IterativeDeepeningWalk(puzzle, max_moves);
			break;
		case 'R':
		case 'r':
			if (argc > 3)
			{
				max_moves = std::stoi(argv[3]);
			}

			walk = new RandomWalk(puzzle, max_moves);
			break;
		default:
			std::cout << "Unknown Walk type. Please use Breadth, Depth, or Random" << std::endl;
	}

	std::cout << "Doing a Walk of " << file << ":" << std::endl;
	walk->walk();

	delete walk;
	return 0;
}
