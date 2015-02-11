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
}

MoveNode::MoveNode(MoveNode *parent, Move move)
	: move_(0, SlidingBrickPuzzle::Direction::UP, 0, 0)
{
	parent_ = parent; 
	puzzle_ = parent->puzzle_.apply_move_clone(move);
	puzzle_.normalize();
	move_ = move;
	cost_ = parent_->cost_ + 1;
}

MoveNode::~MoveNode()
{
	//remove_from_parent();
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

void MoveNode::add_child(MoveNode *child)
{
	children_.push_back(child);
}

size_t MoveNode::number_children()
{
	return children_.size();
}

void MoveNode::remove_from_parent()
{
	if (parent_ != NULL)
	{
		parent_->remove_child(this);
	}
}

void MoveNode::remove_child(MoveNode *child)
{
	children_.erase(std::remove(std::begin(children_), std::end(children_), child), std::end(children_));
	if (children_.size() == 0)
	{
		delete this;
	}
}
