#include "IterativeDeepeningWalk.h"

IterativeDeepeningWalk::IterativeDeepeningWalk(SlidingBrickPuzzle puzzle, size_t max_depth)
{
	puzzle_ = puzzle;
	max_ = max_depth;
}

bool IterativeDeepeningWalk::walk(void)
{
	for (size_t i = 1; i <= max_; i++)
	{
		DepthLimitedWalk limited(puzzle_, i);
		if (limited.walk())
		{
			return true;
		}
	}

	return false;
}
