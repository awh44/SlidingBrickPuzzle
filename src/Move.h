#ifndef _MOVE_H_
#define _MOVE_H_

#include <iostream>

#include "SlidingBrickPuzzle.h"

class Move
{
	public:
		Move(int piece, SlidingBrickPuzzle::Direction direction, size_t row, size_t column);

		/**
			gets the value of the piece associated with the Move
			@return the value of the piece associated with the Move
		*/
		int get_piece();

		/**
			gets the row in which the associated piece's upper-left corner lies
			@return the row as specified above
		*/
		size_t get_row();

		/**
			gets the column in which the associated piece's upper-left corner lies
			@return the column as specified above
		*/
		size_t get_column();

		/**
			gets the direction associated with the Move, either up, down, left, or right (indicated
			by SlidingBrickPuzzle::Direction::UP/DOWN/LEFT/RIGHT)
			@return the direction associated with the Move
		*/
		SlidingBrickPuzzle::Direction get_direction();

		/**
			prints the piece number and the direction of the Move to the specified ostream, in the
			form of (piece,direction)
			@param out the ostream to which the Move should be printed
		*/
		void print_move(std::ostream &out = std::cout);
	private:
		int piece_;
		size_t row_;
		size_t column_;
		SlidingBrickPuzzle::Direction direction_;
};

#endif
