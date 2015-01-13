#ifndef _MOVE_H_
#define _MOVE_H_

#include "SlidingBrickPuzzle.h"

class Move
{
	public:
		Move(int piece, SlidingBrickPuzzle::Direction direction);
		int get_piece();
		SlidingBrickPuzzle::Direction get_direction();

	private:
		int piece_;
		SlidingBrickPuzzle::Direction direction_;
};

#endif
