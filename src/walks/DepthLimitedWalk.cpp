#include <vector>

#include "DepthLimitedWalk.h"
#include "../moves/Move.h"

DepthLimitedWalk::DepthLimitedWalk(SlidingBrickPuzzle puzzle, size_t max_depth)
{
	root_ = new MoveNode(puzzle);
	open_list_ = new Stack<MoveNode *>();
	max_ = max_depth;
	nodes_generated_ = 0;
}

DepthLimitedWalk::~DepthLimitedWalk()
{
	delete root_;
	delete open_list_;
}

//this algorithm is extremely close to the one used for depth first search (simply with a depth
//limit added as an extra condition to the if statement with !been_seen), but getting the
//inheritance to work proved too difficult, so this is just a manual copy of the code.
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
			std::cout << "Number of moves: " << next->get_cost() << std::endl;
			std::cout << "Number of nodes generated: " << nodes_generated_ << std::endl;
			return true;
		}

		if (!been_seen(next))
		{
			insert_all(next);
		}
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
			nodes_generated_++;
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

bool DepthLimitedWalk::been_seen(MoveNode *node)
{
	//check only the current path
	MoveNode *ancestor = node->get_parent();
	while (ancestor != NULL)
	{
		if (node->get_puzzle() == ancestor->get_puzzle())
		{
			return true;
		}
		ancestor = ancestor->get_parent();
	}
	
	return false;
}
