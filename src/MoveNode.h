#ifndef _H_MOVENODE_
#define _H_MOVENODE_

#include <vector>

#include "SlidingBrickPuzzle.h"
#include "Move.h"

class MoveNode
{
	public:
		MoveNode(SlidingBrickPuzzle puzzle);
		MoveNode(MoveNode *parent = NULL, Move move = Move(0, SlidingBrickPuzzle::Direction::UP, 0, 0));
		~MoveNode();

		SlidingBrickPuzzle get_puzzle();
		MoveNode *get_parent();
		Move get_move();
		unsigned int get_cost();
		void add_child(MoveNode *child);

	private:
		SlidingBrickPuzzle puzzle_;
		MoveNode *parent_;
		Move move_;
		unsigned int cost_;
		std::vector<MoveNode*> children_;
};

#endif
