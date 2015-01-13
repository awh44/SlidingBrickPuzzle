#include "Move.h"

Move::Move(int piece, SlidingBrickPuzzle::Direction direction)
{
	piece_ = piece;
	direction_ = direction;
}

int Move::get_piece()
{
	return piece_;
}

SlidingBrickPuzzle::Direction Move::get_direction()
{
	return direction_;
}
