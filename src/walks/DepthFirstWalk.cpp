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
/*		if (node->number_children() == 0)
		{
			delete node;
		}
*/
	}
/*
	else
	{
		//not going to have any children, so can get rid of it
		delete node;
	}
*/
}

bool DepthFirstWalk::been_seen(MoveNode *node)
{
	MoveNode *anscestor = node->get_parent();
	while (anscestor != NULL)
	{
		if (node->get_puzzle() == anscestor->get_puzzle())
		{
			return true;
		}
		anscestor = anscestor->get_parent();
	}
	
	return false;
}
