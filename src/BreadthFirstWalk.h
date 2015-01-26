#ifndef _BREADTH_FIRST_WALK_H_
#define _BREADTH_FIRST_WALK_H_

#include "SlidingBrickPuzzle.h"
#include "UninformedWalk.h"

class BreadthFirstWalk : public UninformedWalk
{
	public:
		BreadthFirstWalk(SlidingBrickPuzzle puzzle);
};

#endif
