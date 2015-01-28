#ifndef _DEPTH_LIMITED_WALK_H_
#define _DEPTH_LIMITED_WALK_H_

#include "Walk.h"
#include "../moves/MoveNode.h"
#include "../structures/Stack.h"


class DepthLimitedWalk : public Walk
{
	public:
		DepthLimitedWalk(SlidingBrickPuzzle puzzle, size_t max_depth);
		virtual bool walk(void);

	protected:
		void insert_all(MoveNode *curr_node);
		void print_solution(MoveNode *solution_node);

	private:
		MoveNode *root_;
		Stack<MoveNode *> *open_list_;
		size_t max_;
};

#endif
