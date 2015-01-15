#include <iostream>
#include <map>

#include "../src/SlidingBrickPuzzle.h"
#include "../src/Move.h"
#include "../src/Walk.h"
#include "../src/RandomWalk.h"

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
	std::vector<Move> moves = puzzle.all_moves();
	print_move_array(moves);
	
	std::cout << "Moving 3 left:" << std::endl;
	puzzle.apply_move(Move(3, SlidingBrickPuzzle::Direction::LEFT, 1, 2));
	puzzle.print_board();	

	std::cout << "Moving 2 left:" << std::endl;
	puzzle.apply_move(Move(2, SlidingBrickPuzzle::Direction::LEFT, 2, 2));
	puzzle.print_board();

	std::cout << "Moving 4 down:" << std::endl;
	puzzle.apply_move(Move(4, SlidingBrickPuzzle::Direction::DOWN, 1, 3));
	puzzle.print_board();

	std::cout << "Moving 3 right twice:" << std::endl;
	puzzle.apply_move(Move(3, SlidingBrickPuzzle::Direction::RIGHT, 1, 1));
	puzzle.apply_move(Move(3, SlidingBrickPuzzle::Direction::RIGHT, 1, 2));
	puzzle.print_board();

	std::cout << "Moving 2 up:" << std::endl;
	puzzle.apply_move(Move(2, SlidingBrickPuzzle::Direction::UP, 2, 1));
	puzzle.print_board();
	std::cout << "Valid moves for 2: ";
	print_moves(puzzle.moves_for_piece(2));

	std::cout << "Moving 2 up again:" << std::endl;
	puzzle.apply_move(Move(2, SlidingBrickPuzzle::Direction::UP, 1, 1));
	puzzle.print_board();

	std::cout << "Copying board and applying move of 2 down:" << std::endl;
	SlidingBrickPuzzle new_p = puzzle.apply_move_clone(Move(2, SlidingBrickPuzzle::Direction::DOWN, 0, 1));
	new_p.print_board();

	std::cout << std::endl;

	std::cout << "Loading SBP-level0-solved.txt:" << std::endl;
	SlidingBrickPuzzle puzzle2;
	puzzle2.load_game("input/SBP-level0-solved.txt");
	puzzle2.print_board();
	std::cout << "is_solved == " << puzzle.is_solved() << std::endl;
	std::cout << "Comparing two solved puzzles: " << puzzle2.equal(puzzle) << std::endl;
	std::cout << "Comparing solved and unsolved: " << puzzle2.equal(new_p) << std::endl;

	std::cout << std::endl;

	std::cout << "Loading the non-normalized board:" << std::endl;
	SlidingBrickPuzzle abnormal;
	abnormal.load_game("input/SBP-test-not-normalized.txt");
	abnormal.print_board();
	std::cout << "Normalizing:" << std::endl;
	abnormal.normalize();
	abnormal.print_board();

	std::cout << std::endl;
	
	return 0;
}
