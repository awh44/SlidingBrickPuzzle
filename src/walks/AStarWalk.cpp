#include "AStarWalk.h"
#include "MoveNode.h"

AStarWalk::AStarWalk(SlidingBrickPuzzle puzzle)
{
	root_ = new MoveNode(puzzle);
	open_list_ = new Queue();
	closed_list_ = new Dictionary(MoveNode::hash, MoveNode::compare);
}

AStarWalk::~AStarWalk()
{
	delete root_;
	delete open_list_;
	delete closed_list_;
}

bool AStarWalk::walk(void)
{
	open_list_->add(root_);
	while (!open_list_->empty())
	{
		MoveNode *next = open_list_.get();
		open_list_.remove();
		if (next->get_puzzle().is_solved())
		{
			std::cout << "Found it!" << std::endl;
			return true;
		}

		closed_list_->add(next);
		insert_all(next);	
	}

	return false;
}

void AStarWalk::insert_all(MoveNode *node)
{
	std::vector<Move> = curr_node->get_puzzle().all_moves();
	for (size_t i = 0; i < moves.size(); i++)
	{
		MoveNode *new_node = new MoveNode(node, moves[i]);
		if (!closed_list_->member(new_node))
		{
			node->add_child(new_node);
			open_list_->add(new_node);
		}
		else
		{
			delete new_node;
		}
	}
}
