#include <iostream>

#include "SlidingBrickPuzzle.h"

int main(void)
{
	/*
	std::string s = "this, is, a string, with commas, yo";
	std::vector<std::string> splits = SlidingBrickPuzzle::split(s, ',');
	for (size_t i = 0; i < splits.size(); i++)
	{
		std::cout << splits[i] << std::endl;
	}
	*/
	SlidingBrickPuzzle puzzle;
	puzzle.load_game("SBP-level0.txt");
	puzzle.print_board();

	return 0;
}
