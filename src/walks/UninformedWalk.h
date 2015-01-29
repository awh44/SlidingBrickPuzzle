#ifndef _UNINFORMED_WALK_H_
#define _UNINFORMED_WALK_H_

#include "../SlidingBrickPuzzle.h"
#include "Walk.h"
#include "../moves/MoveNode.h"
#include "../structures/Collection.h"
#include "../structures//Dictionary.h"

class UninformedWalk : public Walk
{
	public:
		UninformedWalk(SlidingBrickPuzzle puzzle);
		virtual ~UninformedWalk();
		
		virtual bool walk(void);
	protected:
		virtual void insert_all(MoveNode *node);
		virtual void insertion_deletion(MoveNode *node) = 0;
		Collection<MoveNode*> *open_list_;

	private:
		MoveNode *root_;
		void print_solution(MoveNode *solution_node);
};

#endif
