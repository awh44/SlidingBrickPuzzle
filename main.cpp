#include <iostream>
#include <map>

#include "src/SlidingBrickPuzzle.h"
#include "src/Move.h"

void print_direction_string(SlidingBrickPuzzle::Direction direction)
{
	if (direction == SlidingBrickPuzzle::Direction::UP)
		std::cout << "Up,";
	else if (direction == SlidingBrickPuzzle::Direction::DOWN)
		std::cout << "Down,";
	else if (direction == SlidingBrickPuzzle::Direction::LEFT)
		std::cout << "Left,";
	else if (direction == SlidingBrickPuzzle::Direction::RIGHT)
		std::cout << "Right";
}

void print_moves(std::vector<SlidingBrickPuzzle::Direction> moves)
{
	for (size_t i = 0; i < moves.size(); i++)
	{
		print_direction_string(moves[i]);
	}
	std::cout << std::endl;
}

void print_move_array(std::vector<Move> moves)
{
	for (size_t i = 0; i < moves.size(); i++)
	{
		std::cout << "piece " << moves[i].get_piece() << ": ";
		print_direction_string(moves[i].get_direction());
		std::cout << std::endl;
	}	
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
	std::cout << "All moves are:" << std::endl;
	print_move_array(puzzle.all_moves());
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
