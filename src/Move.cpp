#include <iostream>

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

void Move::print_move(std::ostream &out)
{
	out << "(" << piece_ << ",";
	if (direction_ == SlidingBrickPuzzle::Direction::UP)
	{
		out << "up";
	}
	else if (direction_ == SlidingBrickPuzzle::Direction::DOWN)
	{
		out << "down";
	}
	else if (direction_ == SlidingBrickPuzzle::Direction::LEFT)
	{
		out << "left";
	}
	else if (direction_ == SlidingBrickPuzzle::Direction::RIGHT)
	{
		out << "right";
	}

	out << ")" << std::endl;
}
