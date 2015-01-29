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
	private:
		static bool compare_nodes(MoveNode *a, MoveNode *b);
};

#endif
