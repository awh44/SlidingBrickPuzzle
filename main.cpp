#include <iostream>

#include "src/SlidingBrickPuzzle.h"

void print_moves(std::vector<SlidingBrickPuzzle::Direction> moves)
{

	for (size_t i = 0; i < moves.size(); i++)
	{
		if (moves[i] == SlidingBrickPuzzle::Direction::UP)
			std::cout << "Up,";
		else if (moves[i] == SlidingBrickPuzzle::Direction::DOWN)
			std::cout << "Down,";
		else if (moves[i] == SlidingBrickPuzzle::Direction::LEFT)
			std::cout << "Left,";
		else if (moves[i] == SlidingBrickPuzzle::Direction::RIGHT)
			std::cout << "Right";
	}
	std::cout << std::endl;
}

int main(void)
{
	SlidingBrickPuzzle puzzle;

	std::cout << "Loading SBP-level0.txt:" << std::endl;
	puzzle.load_game("input/SBP-level0.txt");
	puzzle.print_board();
	std::cout << "is_solved == " << puzzle.is_solved() << std::endl;

	std::cout << "Moves for the master piece: ";
	print_moves(puzzle.moves_for_piece(2));
	std::cout << "Moves for piece 3: ";
	print_moves(puzzle.moves_for_piece(3));
	std::cout << "Moves for piece 4: ";
	print_moves(puzzle.moves_for_piece(4));
	std::cout << std::endl;

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
