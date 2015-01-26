#ifndef _ITERATIVE_DEEPENINDG_WALK_H_
#define _ITERATIVE_DEEPENINDG_WALK_H_

#include "SlidingBrickPuzzle.h"
#include "DepthFirstWalk.h"

class IterativeDeepeningWalk : public DepthFirstWalk
{
	public:
		IterativeDeepeningWalk(SlidingBrickPuzzle puzzle, size_t max);

		bool walk(void);
	
	protected:
		void expand(MoveNode *curr_node);

	private:
		SlidingBrickPuzzle puzzle_;
		size_t max_;
		size_t curr_depth_;
};

#endif
