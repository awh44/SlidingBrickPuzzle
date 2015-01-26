#include <iostream>

#include "Move.h"

Move::Move(int piece, SlidingBrickPuzzle::Direction direction, size_t row, size_t column)
{
	piece_ = piece;
	direction_ = direction;
	row_ = row;
	column_ = column;
}

Move::Move(const Move &other)
{
	piece_ = other.piece_;
	direction_ = other.direction_;
	row_ = other.row_;
	column_ = other.column_;
}

int Move::get_piece(void)
{
	return piece_;
}

size_t Move::get_row(void)
{
	return row_;
}

size_t Move::get_column(void)
{
	return column_;
}

SlidingBrickPuzzle::Direction Move::get_direction(void)
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
