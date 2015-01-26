#ifndef _DEPTH_FIRST_WALK_H_
#define _DEPTH_FIRST_WALK_H_

#include "../SlidingBrickPuzzle.h"
#include "UninformedWalk.h"

class DepthFirstWalk : public UninformedWalk
{
	public:
		DepthFirstWalk(SlidingBrickPuzzle puzzle);
};

#endif
