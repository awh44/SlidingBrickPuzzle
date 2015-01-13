#include <iostream>

#include "src/SlidingBrickPuzzle.h"

int main(void)
{
	SlidingBrickPuzzle puzzle;

	std::cout << "Loading SBP-level0.txt:" << std::endl;
	puzzle.load_game("input/SBP-level0.txt");
	puzzle.print_board();
	std::cout << "is_solved == " << puzzle.is_solved() << std::endl << std::endl;

	std::cout << "Loading SBP-level0-solved.txt:" << std::endl;
	puzzle.load_game("input/SBP-level0-solved.txt");
	puzzle.print_board();
	std::cout << "is_solved == " << puzzle.is_solved() << std::endl << std::endl;

	std::cout << "Copying the puzzle into another puzzle:" << std::endl;
	SlidingBrickPuzzle puzzle2(puzzle);
	puzzle2.print_board();
	std::cout << "is_solved == " << puzzle.is_solved() << std::endl << std::endl;


	return 0;
}
