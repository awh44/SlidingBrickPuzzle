#include "UninformedWalk.h"
#include "../moves/Move.h"

UninformedWalk::UninformedWalk(SlidingBrickPuzzle puzzle)
	: closed_list_(1)
{
	init(puzzle);
}

UninformedWalk::~UninformedWalk()
{
	//Node implementation handles deletion of rest of tree/graph
	delete root_;	
}

bool UninformedWalk::walk(void)
{
	if (root_->get_puzzle().is_solved())
	{
		return true;
	}

	insert_all(root_);
	while (!is_over())
	{
		MoveNode *next = open_list_->get();
		open_list_->remove();
		if (!closed_list_.member(next->get_puzzle()))
		{
			if (next->get_puzzle().is_solved())
			{
				print_solution(next);
				next->get_puzzle().print_board();
				return true;
			}
			closed_list_.insert(next->get_puzzle());
			insert_all(next);
		}
	}

	return false;
}

void UninformedWalk::init(SlidingBrickPuzzle puzzle)
{
	root_ = new MoveNode(puzzle);
	closed_list_.insert(puzzle);
}

void UninformedWalk::reset()
{
	delete root_;
	closed_list_.empty_dictionary();
	open_list_->empty_collection();
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
}

bool UninformedWalk::is_over()
{
	return open_list_->empty();
}

void UninformedWalk::print_solution(MoveNode *solution_node)
{
	if (solution_node->get_parent() == NULL)
	{
		return;
	}

	print_solution(solution_node->get_parent());
	solution_node->get_move().print_move();
}
