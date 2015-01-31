/*
	Austin Herring
	January 30th, 2015
	IterativeDeepeningWalk - does an iterative deepening search of a SlidingBrickPuzzle, using the
	maximum depth provided as a parameter to the constructor. Simply uses repeated calls to
	DepthLimitedWalk. If found, prints the solution, the cost of the solution, and the number of
	nodes generated upon the computation of the call to walk(), for the given depth-limited walk.
*/

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
