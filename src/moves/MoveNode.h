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

class MoveNode
{
	public:
		static bool compare_nodes(MoveNode *a, MoveNode *b);
		static size_t hash(MoveNode *node);

		MoveNode(SlidingBrickPuzzle puzzle);
		MoveNode(MoveNode *parent = NULL, Move move = Move(0, SlidingBrickPuzzle::Direction::UP, 0, 0));
		~MoveNode();

		SlidingBrickPuzzle &get_puzzle();
		MoveNode *get_parent();
		Move get_move();
		unsigned int get_cost();
		size_t get_hash();
		size_t get_heuristic();
		void add_child(MoveNode *child);

	private:
		void remove_child(MoveNode *child);
		
		SlidingBrickPuzzle puzzle_;
		MoveNode *parent_;
		Move move_;
		unsigned int cost_;
		std::vector<MoveNode*> children_;
		size_t hash_;
		size_t heuristic_;
};

class CompareMoveNode
{
	public:
		bool operator()(MoveNode *a, MoveNode *b)
		{
			return a->get_heuristic() + a->get_cost() > b->get_heuristic() + b->get_cost();
		}
};

class HashMoveNode
{
	public:
		bool operator()(MoveNode *a) const noexcept
		{
			return a->get_hash();
		}
};

class EqualMoveNode
{
	public:
		bool operator()(MoveNode *a, MoveNode *b) const
		{
			return MoveNode::compare_nodes(a, b);
		}
};
#endif
