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
		void init(SlidingBrickPuzzle puzzle);
		void reset();
		virtual void insert_all(MoveNode *node);

		MoveNode *root_;
		Dictionary<SlidingBrickPuzzle> closed_list_;

		Collection<MoveNode*> *open_list_;

	private:
		void print_solution(MoveNode *solution_node);

};

#endif
