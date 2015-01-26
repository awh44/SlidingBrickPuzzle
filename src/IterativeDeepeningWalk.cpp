#include "IterativeDeepeningWalk.h"
	
IterativeDeepeningWalk::IterativeDeepeningWalk(SlidingBrickPuzzle puzzle, size_t max)
	: DepthFirstWalk(puzzle)
{
	puzzle_ = puzzle;
	max_ = max;
}

bool IterativeDeepeningWalk::walk(void)
{
	for (size_t i = 0; i < max_; i++)
	{
		curr_depth_ = i + 1;
		if (DepthFirstWalk::walk())
		{
			return true;
		}

		//reset();
		init(puzzle_);
	}

	return false;
}

void IterativeDeepeningWalk::expand(MoveNode *curr_node)
{
	if (curr_node->get_cost() < max_)
	{
		DepthFirstWalk::expand(curr_node);
	}
}
