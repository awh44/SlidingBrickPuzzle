#ifndef _ITERATIVE_DEEPENING_WALK_H_
#define _ITERATIVE_DEEPENING_WALK_H_

#include "DepthLimitedWalk.h"

class IterativeDeepeningWalk : public Walk
{
	public:
		IterativeDeepeningWalk(SlidingBrickPuzzle puzzle, size_t max_depth);
		bool walk(void);
	
	private:
		SlidingBrickPuzzle puzzle_;
		size_t max_;
};

#endif
