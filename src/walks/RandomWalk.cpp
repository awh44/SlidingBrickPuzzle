#include <iostream>
#include <vector>
#include <cstdlib>

#include "RandomWalk.h"
#include "../moves/Move.h"

RandomWalk::RandomWalk(SlidingBrickPuzzle puzzle, size_t max_moves)
{
	puzzle_ = puzzle;
	max_moves_ = max_moves;
}

bool RandomWalk::walk(void)
{
	puzzle_.print_board();
	std::cout << std::endl;

	size_t executed_moves = 0;
	while (!puzzle_.is_solved() && executed_moves < max_moves_)
	{
		std::vector<Move> moves = puzzle_.all_moves();
		Move selected = moves[rand() % moves.size()];
		selected.print_move();
		std::cout << std::endl;
		
		puzzle_.apply_move(selected);
		puzzle_.normalize();
		puzzle_.print_board();
		std::cout << std::endl;
		
		executed_moves++;
	}

	return puzzle_.is_solved();
}
