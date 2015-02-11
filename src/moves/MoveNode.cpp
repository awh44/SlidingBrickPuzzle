#include <algorithm>
#include <cstddef>
#include "MoveNode.h"

bool MoveNode::compare_nodes(MoveNode *a, MoveNode *b)
{
	return a->get_puzzle() == b->get_puzzle();
}

size_t MoveNode::hash(MoveNode *node)
{
	return node->get_puzzle().hash();
}

MoveNode::MoveNode(SlidingBrickPuzzle puzzle)
	: move_(0, SlidingBrickPuzzle::Direction::UP, 0, 0)
{
	parent_ = NULL;
	puzzle_ = puzzle;
	cost_ = 0;
	hash_ = puzzle_.hash();
	heuristic_ = puzzle_.heuristic();
}

MoveNode::MoveNode(MoveNode *parent, Move move)
	: move_(0, SlidingBrickPuzzle::Direction::UP, 0, 0)
{
	parent_ = parent; 
	puzzle_ = parent->puzzle_.apply_move_clone(move);
	puzzle_.normalize();
	move_ = move;
	cost_ = parent_->cost_ + 1;
	hash_ = puzzle_.hash();
	heuristic_ = puzzle_.heuristic();
}

MoveNode::~MoveNode()
{
	for (size_t i = 0; i < children_.size(); i++)
	{
		delete children_[i];
	}
}

SlidingBrickPuzzle &MoveNode::get_puzzle()
{
	return puzzle_;
}

MoveNode *MoveNode::get_parent()
{
	return parent_;
}

Move MoveNode::get_move()
{
	return move_;
}

unsigned int MoveNode::get_cost()
{
	return cost_;
}

size_t MoveNode::get_hash()
{
	return hash_;
}

size_t MoveNode::get_heuristic()
{
	return heuristic_;
}

void MoveNode::add_child(MoveNode *child)
{
	children_.push_back(child);
}
