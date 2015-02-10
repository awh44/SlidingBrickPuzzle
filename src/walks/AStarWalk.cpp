#include "AStarWalk.h"
#include "../structures/PriorityQueue.h"
#include "../moves/MoveNode.h"

AStarWalk::AStarWalk(SlidingBrickPuzzle puzzle)
{
	root_ = new MoveNode(puzzle);
	open_list_ = new PriorityQueue<MoveNode *, CompareMoveNode>();
}

AStarWalk::~AStarWalk()
{
	delete root_;
	delete open_list_;
}

bool AStarWalk::walk(void)
{
	open_list_->add(root_);
	while (!open_list_->empty())
	{
		MoveNode *next = open_list_->get();
		open_list_->remove();
		if (next->get_puzzle().is_solved())
		{
			print_solution(next);
			return true;
		}

		closed_list_.insert(next);
		insert_all(next);	
	}

	return false;
}

void AStarWalk::insert_all(MoveNode *curr_node)
{
	std::vector<Move> moves = curr_node->get_puzzle().all_moves();
	for (size_t i = 0; i < moves.size(); i++)
	{
		MoveNode *new_node = new MoveNode(curr_node, moves[i]);
		if (closed_list_.count(new_node) == 0)
		{
			curr_node->add_child(new_node);
			open_list_->add(new_node);
		}
		else
		{
			delete new_node;
		}
	}
}

void AStarWalk::print_solution(MoveNode *solution_node)
{
	print_recursive(solution_node);
	solution_node->get_puzzle().print_board();
	std::cout << "Number of moves: " << solution_node->get_cost() << std::endl;
}

void AStarWalk::print_recursive(MoveNode *solution_node)
{
	if (solution_node->get_parent() == NULL)
	{
		return;
	}
	
	print_recursive(solution_node->get_parent());
	solution_node->get_move().print_move();
}
