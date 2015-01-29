#include "UninformedWalk.h"
#include "../moves/Move.h"

UninformedWalk::UninformedWalk(SlidingBrickPuzzle puzzle)
{
	root_ = new MoveNode(puzzle);
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
	while (!open_list_->empty())
	{
		MoveNode *next = open_list_->get();
		open_list_->remove();
		if (next->get_puzzle().is_solved())
		{
			print_solution(next);
			next->get_puzzle().print_board();
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
