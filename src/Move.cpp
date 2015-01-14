#include "Move.h"

Move::Move(int piece, SlidingBrickPuzzle::Direction direction, size_t row, size_t column)
{
	piece_ = piece;
	direction_ = direction;
	row_ = row;
	column_ = column;
}

int Move::get_piece()
{
	return piece_;
}

size_t Move::get_row()
{
	return row_;
}

size_t Move::get_column()
{
	return column_;
}

SlidingBrickPuzzle::Direction Move::get_direction()
{
	return direction_;
}
