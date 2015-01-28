#include <vector>

#include "DepthLimitedWalk.h"
#include "../moves/Move.h"

DepthLimitedWalk::DepthLimitedWalk(SlidingBrickPuzzle puzzle, size_t max_depth)
{
	root_ = new MoveNode(puzzle);
	open_list_ = new Stack<MoveNode *>();
	max_ = max_depth;
}

//this algorithm is extremely close to the one in UninformedWalk.h (with the Stack as the
//open_list_; then, basically just override small portions of methods to ignore the closed_list_
//and then change insert_all to only call the parent method if the cost condition is satisfied),
//but I couldn't make the inheritance work right, so I just made a new class and manually copied the
//code
bool DepthLimitedWalk::walk(void)
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
		insert_all(next);
	}

	return false;
}

void DepthLimitedWalk::insert_all(MoveNode *curr_node)
{
	if (curr_node->get_cost() < max_)
	{
		std::vector<Move> moves = curr_node->get_puzzle().all_moves();
		for (size_t i = 0; i < moves.size(); i++)
		{
			MoveNode *new_node = new MoveNode(curr_node, moves[i]);
			curr_node->add_child(new_node);
			open_list_->add(new_node);
		}
	}
}

void DepthLimitedWalk::print_solution(MoveNode *solution_node)
{
	if (solution_node->get_parent() == NULL)
	{
		return;
	}

	print_solution(solution_node->get_parent());
	solution_node->get_move().print_move();
}
