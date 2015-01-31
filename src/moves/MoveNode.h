/*
	Austin Herring
	January 30, 2015
	MoveNode.h - contians a class for a Node in a search tree; contains a state, the move applied
	to get there, the cost, and the parents and children.
*/

#ifndef _H_MOVENODE_
#define _H_MOVENODE_

#include <functional>
#include <vector>

#include "../SlidingBrickPuzzle.h"
#include "Move.h"

template <class T>
class MoveNodeHash;

class MoveNode
{
	public:
		static bool compare_nodes(MoveNode *a, MoveNode *b);

		MoveNode(SlidingBrickPuzzle puzzle);
		MoveNode(MoveNode *parent = NULL, Move move = Move(0, SlidingBrickPuzzle::Direction::UP, 0, 0));
		~MoveNode();

		SlidingBrickPuzzle get_puzzle();
		MoveNode *get_parent();
		Move get_move();
		unsigned int get_cost();
		void add_child(MoveNode *child);
		size_t number_children();
		void remove_from_parent();

	private:
		void remove_child(MoveNode *child);
		
		SlidingBrickPuzzle puzzle_;
		MoveNode *parent_;
		Move move_;
		unsigned int cost_;
		std::vector<MoveNode*> children_;
};

/*
template <>
struct MoveNodeHash<MoveNode*>
{
	size_t operator()(MoveNode* const& node) const 
	{
		return node->get_puzzle().hash();
	}
};
*/
#endif
