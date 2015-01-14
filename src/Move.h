#ifndef _MOVE_H_
#define _MOVE_H_

#include "SlidingBrickPuzzle.h"

class Move
{
	public:
		Move(int piece, SlidingBrickPuzzle::Direction direction, size_t row, size_t column);
		int get_piece();
		size_t get_row();
		size_t get_column();
		SlidingBrickPuzzle::Direction get_direction();

	private:
		int piece_;
		size_t row_;
		size_t column_;
		SlidingBrickPuzzle::Direction direction_;
};

#endif
