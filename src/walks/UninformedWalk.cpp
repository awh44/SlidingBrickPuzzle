#include "UninformedWalk.h"
#include "../moves/Move.h"

UninformedWalk::UninformedWalk(SlidingBrickPuzzle puzzle)
{
	root_ = new MoveNode(puzzle);
	nodes_generated_ = 0;
}

UninformedWalk::~UninformedWalk()
{
	//Node implementation handles deletion of rest of tree/graph
	delete root_;
	delete open_list_;
}

bool UninformedWalk::walk(void)
{
	if (root_->get_puzzle().is_solved())
	{
		return true;
	}

	insert_all(root_);
	while (!open_list_->empty())
	{
		MoveNode *next = open_list_->get();
		open_list_->remove();
		if (next->get_puzzle().is_solved())
		{
			print_solution(next);
			return true;
		}
		insertion_deletion(next);
	}

	return false;
}

void UninformedWalk::insert_all(MoveNode *curr_node)
{
	std::vector<Move> moves = curr_node->get_puzzle().all_moves();
	for (size_t i = 0; i < moves.size(); i++)
	{
		MoveNode *new_node = new MoveNode(curr_node, moves[i]);
		curr_node->add_child(new_node);
		open_list_->add(new_node);
	}

	nodes_generated_ += moves.size();
}

void UninformedWalk::print_solution(MoveNode *solution_node)
{
	size_t num_moves = print_solution_recursive(solution_node, 0);
	solution_node->get_puzzle().print_board();
	std::cout << "Number of moves: " << num_moves << std::endl;
	std::cout << "Number of nodes generated: " << nodes_generated_ << std::endl;
}

size_t UninformedWalk::print_solution_recursive(MoveNode *solution_node, size_t num_moves)
{
	if (solution_node->get_parent() == NULL)
	{
		return num_moves;
	}

	size_t new_num = print_solution_recursive(solution_node->get_parent(), num_moves + 1);
	solution_node->get_move().print_move();
	return new_num;
}
