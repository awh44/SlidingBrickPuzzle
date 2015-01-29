#include "BreadthFirstWalk.h"
#include "../structures/Queue.h"

BreadthFirstWalk::BreadthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Queue<MoveNode*>();
}

void BreadthFirstWalk::insertion_deletion(MoveNode *node)
{
	if (!open_list_->contains(node, compare_nodes))
	{
		insert_all(node);
	}
}

bool BreadthFirstWalk::compare_nodes(MoveNode *a, MoveNode *b)
{
	return a->get_puzzle() == b->get_puzzle();
}
