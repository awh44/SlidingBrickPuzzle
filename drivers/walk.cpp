#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "../src/SlidingBrickPuzzle.h"
#include "../src/walks/Walk.h"
#include "../src/walks/RandomWalk.h"
#include "../src/walks/BreadthFirstWalk.h"
#include "../src/walks/DepthFirstWalk.h"
#include "../src/walks/DepthLimitedWalk.h"
#include "../src/walks/IterativeDeepeningWalk.h"
#include "../src/walks/AStarWalk.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc < 2)
	{
		std::cout << "Please include the search type as the first command line argument." << std::endl;
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
	
	std::cout << "Doing a ";
	Walk *walk;
	size_t max_moves = 20;
	switch (argv[1][0])
	{
		case 'B':
		case 'b':	
			std::cout << "BreadthFirst";
			walk = new BreadthFirstWalk(puzzle);
			break;
		case 'D':
		case 'd':
			std::cout << "DepthFirst";
			walk = new DepthFirstWalk(puzzle);
			break;
		case 'I':
		case 'i':
			if (argc > 3)
			{
				max_moves = std::stoi(argv[3]);
			}

			std::cout << "(" << max_moves << ") IterativeDeepening";
			walk = new IterativeDeepeningWalk(puzzle, max_moves);
			break;
		case 'L':
		case 'l':
			if (argc > 3)
			{
				max_moves = std::stoi(argv[3]);
			}

			std::cout << "(" << max_moves << ") DepthLimited";
			walk = new DepthLimitedWalk(puzzle, max_moves);
			break;
		case 'R':
		case 'r':
			if (argc > 3)
			{
				max_moves = std::stoi(argv[3]);
			}

			std::cout << "(" << max_moves << ") Random";
			walk = new RandomWalk(puzzle, max_moves);
			break;
		case 'A':
		case 'a':
			std::cout << "AStar";
			walk = new AStarWalk(puzzle);
			break;
		default:
			std::cout << "Unknown Walk type. Please use Breadth, Depth, Iterative, or Random" << std::endl;
			return 1;
	}

	std::cout << "Walk of " << file << ":" << std::endl;
	walk->walk();

	delete walk;
	return 0;
}
