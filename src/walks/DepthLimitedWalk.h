/*
	Austin Herring
	January 30th, 2015
	DepthLimitedWalk - does a depth first search of a SlidingBrickPuzzle, with a maximum depth
	limited provided in the constructor. If found, prints the solution, the cost of the solution,
	and the number of nodes generated upon the completion of the call to walk().
*/

#ifndef _DEPTH_LIMITED_WALK_H_
#define _DEPTH_LIMITED_WALK_H_

#include "Walk.h"
#include "../moves/MoveNode.h"
#include "../structures/Stack.h"


class DepthLimitedWalk : public Walk
{
	public:
		DepthLimitedWalk(SlidingBrickPuzzle puzzle, size_t max_depth);
		~DepthLimitedWalk();
		virtual bool walk(void);

	protected:
		void insert_all(MoveNode *curr_node);
		void print_solution(MoveNode *solution_node);

	private:
		bool been_seen(MoveNode *node);
		MoveNode *root_;
		Stack<MoveNode *> *open_list_;
		size_t max_;
		size_t nodes_generated_;
};

#endif
