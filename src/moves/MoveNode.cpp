#include <algorithm>
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
	//remove_from_parent();
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

size_t MoveNode::number_children()
{
	return children_.size();
}

size_t MoveNode::remove_from_parent()
{
	if (parent_ == NULL)
	{
		return 0;
	}

	parent_->children_.erase(std::remove(std::begin(parent_->children_), std::end(parent_->children_), this), std::end(parent_->children_));
	if (parent_->children_.size() == 0)
	{
		delete parent_;
	}
	return parent_->children_.size();
}
