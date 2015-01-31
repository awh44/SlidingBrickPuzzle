/*
	Austin Herring
	January 30th, 2015
	DepthFirstWalk - does a depth first search of a SlidingBrickPuzzle. If found, prints the
	solution, the cost of the solution, and the number of nodes generated upon completion of the
	call to walk().
*/
#ifndef _DEPTH_FIRST_WALK_H_
#define _DEPTH_FIRST_WALK_H_

#include "../SlidingBrickPuzzle.h"
#include "UninformedWalk.h"

class DepthFirstWalk : public UninformedWalk
{
	public:
		DepthFirstWalk(SlidingBrickPuzzle puzzle);

	protected:
		void insertion_deletion(MoveNode *node);

	private:
		/**
			given a node, determines if the state associated with it yet has been seen in the
			current search path, starting at the node and travaelling along parents to the root
			@param node the ndoe being examined
			@return true if the node's state already exists upon the list of parents up to the root
		*/
		bool been_seen(MoveNode *node);
};

#endif
