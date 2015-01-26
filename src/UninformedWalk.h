#ifndef _UNINFORMED_WALK_H_
#define _UNINFORMED_WALK_H_

#include "SlidingBrickPuzzle.h"
#include "Walk.h"
#include "MoveNode.h"
#include "../../../../Personal/Stack/Collection.h"
#include "../../../../Personal/Dictionary/Dictionary.h"

class UninformedWalk : public Walk
{
	public:
		UninformedWalk(SlidingBrickPuzzle puzzle);
		virtual ~UninformedWalk();
		
		virtual bool walk(void);

	protected:
		void init(SlidingBrickPuzzle puzzle);
		void reset();
		void expand(MoveNode *node);

		MoveNode *root_;
		Dictionary<SlidingBrickPuzzle> closed_list_;

		Collection<MoveNode*> *open_list_;

	private:
		bool is_over();
		void print_solution(MoveNode *solution_node);

};

#endif
