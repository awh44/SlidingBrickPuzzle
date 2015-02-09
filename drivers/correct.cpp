#include <iostream>
#include <map>

#define __DEBUGGING__

#include "../src/SlidingBrickPuzzle.h"
#include "../src/moves/Move.h"
#include "../src/moves/MoveNode.h"
#include "../src/structures/Dictionary.h"

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

void apply_move_cycle(SlidingBrickPuzzle puzzle, Move move)
{
	puzzle.apply_move(move);
	puzzle.print_board();
	std::cout << "Hash = " << puzzle.hash() << std::endl;
	std::cout << "Heuristic = " << puzzle.heuristic() << std::endl << std::endl;
}

void print_heuristic_for_file(std::string file)
{
	SlidingBrickPuzzle level;
	level.load_game(file);
	level.print_board();
	std::cout << "Heuristic = " << level.heuristic() << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		SlidingBrickPuzzle puzzle;

		std::cout << "Loading SBP-level0.txt:" << std::endl;
		puzzle.load_game("input/SBP-level0.txt");
		puzzle.print_board();
		std::cout << "is_solved == " << puzzle.is_solved() << std::endl;
		std::cout << "Hash = " << puzzle.hash() << std::endl;
		std::cout << "Heuristic = " << puzzle.heuristic() << std::endl;

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
		apply_move_cycle(puzzle, Move(3, SlidingBrickPuzzle::Direction::LEFT, 1, 2));

		std::cout << "Moving 2 left:" << std::endl;
		apply_move_cycle(puzzle, Move(2, SlidingBrickPuzzle::Direction::LEFT, 2, 2));

		std::cout << "Moving 4 down:" << std::endl;
		apply_move_cycle(puzzle, Move(4, SlidingBrickPuzzle::Direction::DOWN, 1, 3));

		std::cout << "Moving 3 right twice:" << std::endl;
		apply_move_cycle(puzzle, Move(3, SlidingBrickPuzzle::Direction::RIGHT, 1, 1));
		apply_move_cycle(puzzle, Move(3, SlidingBrickPuzzle::Direction::RIGHT, 1, 2));

		std::cout << "Moving 2 up:" << std::endl;
		apply_move_cycle(puzzle, Move(2, SlidingBrickPuzzle::Direction::UP, 2, 1));
		std::cout << "Valid moves for 2: ";
		print_moves(puzzle.moves_for_piece(2));

		std::cout << "Moving 2 up again:" << std::endl;
		apply_move_cycle(puzzle, Move(2, SlidingBrickPuzzle::Direction::UP, 1, 1));

		std::cout << std::endl << std::endl;

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
		std::cout << "Heuristic = " << abnormal.heuristic() << std::endl;

		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "TESTING THE HEURISTIC FOR ALL LEVELS----------------" << std::endl;
		print_heuristic_for_file("input/SBP-level1.txt");
		print_heuristic_for_file("input/SBP-level2.txt");
		print_heuristic_for_file("input/SBP-level3.txt");
		std::cout << std::endl << std::endl << "Starting bricks levels..." << std::endl;
		print_heuristic_for_file("input/SBP-bricks-level1.txt");
		print_heuristic_for_file("input/SBP-bricks-level2.txt");
		print_heuristic_for_file("input/SBP-bricks-level3.txt");
		print_heuristic_for_file("input/SBP-bricks-level4.txt");
		print_heuristic_for_file("input/SBP-bricks-level5.txt");
		print_heuristic_for_file("input/SBP-bricks-level6.txt");
		print_heuristic_for_file("input/SBP-bricks-level7.txt");

	}
	else if (argc < 3)
	{
		Dictionary<MoveNode*> dict(MoveNode::hash, MoveNode::compare_nodes);
		SlidingBrickPuzzle puzzle;
		puzzle.load_game("input/SBP-level0.txt");
		MoveNode *node = new MoveNode(puzzle);
		dict.insert(node);
		dict.print_dict();
		
		MoveNode *newnode = new MoveNode(puzzle);
		std::cout << "Member? " << dict.member(newnode) << std::endl;
		
		SlidingBrickPuzzle puzzle1;
		puzzle1.load_game("input/SBP-level1.txt");
		MoveNode *third = new MoveNode(puzzle1);
		std::cout << "Member? " << dict.member(third) << std::endl;

		dict.insert(third);
		dict.print_dict();
		std::cout << "Member now? " << dict.member(third) << std::endl;
		delete node;
		delete newnode;
		delete third;
	}

	return 0;
}
