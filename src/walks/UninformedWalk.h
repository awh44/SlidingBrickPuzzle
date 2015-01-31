/*
	Austin Herring
	January 30th, 2015
	UninformedWalk - abstract class for algorithms for solving SlidingBrickPuzzles in uninformed
	ways. If found, prints the solution, the cost of the solution, and the number of nodes generated
	upon the computation of the call to walk().

*/

#ifndef _UNINFORMED_WALK_H_
#define _UNINFORMED_WALK_H_

#include "../SlidingBrickPuzzle.h"
#include "Walk.h"
#include "../moves/MoveNode.h"
#include "../structures/Collection.h"

class UninformedWalk : public Walk
{
	public:
		UninformedWalk(SlidingBrickPuzzle puzzle);
		virtual ~UninformedWalk();
		
		virtual bool walk(void);
	protected:
		virtual void insert_all(MoveNode *node);
		virtual void insertion_deletion(MoveNode *node) = 0;
		MoveNode *root_;
		Collection<MoveNode*> *open_list_;

	private:
		void print_solution(MoveNode *solution_node);
		size_t print_solution_recursive(MoveNode *solution_node, size_t num_moves);
		
		size_t nodes_generated_;
};

#endif
