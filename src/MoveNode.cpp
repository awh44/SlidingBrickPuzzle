#include <cstddef>
#include "MoveNode.h"

MoveNode::MoveNode(SlidingBrickPuzzle puzzle)
	: move_(0, SlidingBrickPuzzle::Direction::UP, 0, 0)
{
	puzzle_ = puzzle;
}

MoveNode::MoveNode(MoveNode *parent, Move move)
	: move_(0, SlidingBrickPuzzle::Direction::UP, 0, 0)
{
	parent_ = parent; 

	if (parent_ != NULL)
	{
		puzzle_ = parent->puzzle_.apply_move_clone(move);
		puzzle_.normalize();

		move_ = move;
		cost_ = parent_->cost_ + 1;
	}
	else
	{
		cost_ = 0;
	}
}

MoveNode::~MoveNode()
{
	for (size_t i = 0; i < children_.size(); i++)
	{
		delete children_[i];
	}
}

SlidingBrickPuzzle MoveNode::get_puzzle()
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

void MoveNode::add_child(MoveNode *child)
{
	children_.push_back(child);
}
