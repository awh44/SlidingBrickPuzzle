/**
	Austin Herring
	January 19, 2015
	Move.h - header for "Move" class. The Move class encodes the data for a particular Move in the
	SlidingBrickPuzzle game; that is, it includes information on which piece is to be moved, which
	direction it will be moved in, and the row and column of the peice's upper leftmost corner.
*/


#ifndef _MOVE_H_
#define _MOVE_H_

#include <iostream>

#include "SlidingBrickPuzzle.h"


class Move
{
	public:
		Move(int piece, SlidingBrickPuzzle::Direction direction, size_t row, size_t column);
		Move(const Move &other);

		/**
			gets the value of the piece associated with the Move
			@return the value of the piece associated with the Move
		*/
		int get_piece(void);

		/**
			gets the row in which the associated piece's upper-left corner lies
			@return the row as specified above
		*/
		size_t get_row(void);

		/**
			gets the column in which the associated piece's upper-left corner lies
			@return the column as specified above
		*/
		size_t get_column(void);

		/**
			gets the direction associated with the Move, either up, down, left, or right (indicated
			by SlidingBrickPuzzle::Direction::UP/DOWN/LEFT/RIGHT)
			@return the direction associated with the Move
		*/
		SlidingBrickPuzzle::Direction get_direction(void);

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
