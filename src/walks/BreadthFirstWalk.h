/*
	Austin Herring
	January 30th, 2015
	BreadthFirstWalk - does a breadth first search of a SlidingBrickPuzzle. Prints the solution,
	cost of solution, and number of nodes generated upon compleltion of call to walk().
*/

#ifndef _BREADTH_FIRST_WALK_H_
#define _BREADTH_FIRST_WALK_H_

#include "../SlidingBrickPuzzle.h"
#include "UninformedWalk.h"

class BreadthFirstWalk : public UninformedWalk
{
	public:
		BreadthFirstWalk(SlidingBrickPuzzle puzzle);
	protected:
		void insertion_deletion(MoveNode *node);
};

#endif
