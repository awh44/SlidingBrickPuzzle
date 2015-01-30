#include "DepthFirstWalk.h"
#include "../structures/Stack.h"

DepthFirstWalk::DepthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Stack<MoveNode*>();
}

void DepthFirstWalk::insertion_deletion(MoveNode *node)
{
	if (!been_seen(node))
	{
		insert_all(node);
	}
/*
	This unused code was to be used to improve the memory usage of DFS, but managing the memory
	proved difficult.
	if (node->number_children() == 0)
	{
		//not a solution and doesn't have any children, so delete it
		delete node;
	}
*/
}

bool DepthFirstWalk::been_seen(MoveNode *node)
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
