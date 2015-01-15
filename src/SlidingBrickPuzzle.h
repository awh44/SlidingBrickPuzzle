#ifndef _SLIDING_BRICK_PUZZLE_H_
#define _SLIDING_BRICK_PUZZLE_H_

#include <iostream>
#include <vector>
#include <string>

class Move;

class SlidingBrickPuzzle
{
	public:
		enum class Direction { UP, DOWN, LEFT, RIGHT };
		
		SlidingBrickPuzzle() {}
		SlidingBrickPuzzle(const SlidingBrickPuzzle &orig);

		/**
			given a filename, this function will load a correctly-formatted board from the file into
			the object and then return true; if the file is not formatted correctly, the function
			will return false
			@param filename the location of the file which contains the desired board
			@return true if the file loaded correctly
		*/
		bool load_game(std::string filename);

		/**
			given a piece, this function will return a vector of all of the possible Directions it
			can move
			@param piece the piece for which the possible directions should be obtained
		*/
		std::vector<Direction> moves_for_piece(int piece);

		/**
			generates all the possible combinations of pieces and directions and returns a vector of
			Move objects representing these combinations
			@return a vector of all possible Moves for the puzzle, indicating pieces and directions
		*/
		std::vector<Move> all_moves(void);
		
		/**
			given a Move object, this function actually moves the piece on the internal board
			@param move the Move which is to be applied, indicating piece and direction
		*/
		void apply_move(Move move);

		/**
			first copies the SlidingBrickPuzzle and then calls the above function to apply the move to the
			new puzzle, returning this new puzzle
			@param move the Move which is to be applied, indicating piece and direction
			@return the cloned SlidingBrickPuzzle, with the given Move applied to it
		*/
		SlidingBrickPuzzle apply_move_clone(Move move);

		/**
			after a move, takes all the pieces in the puzzle and changes the internal representation
			to a common, "normalized" form so that all equivalent puzzles will return true for the
			equals function
		*/
		void normalize(void);

		/**
			returns true if the SlidingBrickPuzzle has been solved
			@return whether the puzzle has been solved (true if it has)
		*/
		bool is_solved(void);

		/**
			returns true if the two SlidingBrickPuzzles are exactly the same
			@return whether the two SlidingBrickPuzzles are the same (true if they are)
		*/
		bool equal(const SlidingBrickPuzzle &other);

		/**
			prints the board to the given output stream (in the same format as for the input files)
			@param out the ostream to which the board should be sent
		*/
		void print_board(std::ostream &out = std::cout);


	private:		
		/**
			given a string s, splits that string into substrings based on the delim character, and
			returns the substrings in vector
			@param s the string to split
			@param delim the character on which to split
			@return the substrings of s delimited by delim
		*/
		static std::vector<std::string> split(std::string s, char delim = ',');

		/**
			given a piece and its position on the board, determines in which Directions that piece
			can move
			@param piece the number of the piece being examined
			@param row the row in which the piece's upper left corner lies
			@param column the column in which the piece's upper left corner lies
			@return a vector of all the Directions that the given piece can move
		*/
		std::vector<Direction> process_moves(int piece, size_t row, size_t column);

		/**
			checks a particular direction, based on vert_change and hor_change, for a piece and sees
			if that direction is a possible move for the piece
			@param piece the number of the piece being examined
			@param row the row in which the piece's upper left corner lies
			@param column the column in which the piece's upper left corner lies
			@param vert_change indicates how far in vertical direction should be checked for empty
							   spaces into which the piece can be moved
			@param hor_change indicates how far in  horizontal direction should be checked for empty
							   spaces into which the piece can be moved
			@return whether the piece can be moved in the direction indicated by the combination of
							   vert_change and hor_change
		*/
		bool check_direction(int piece, size_t row, size_t column, int vert_change, int hor_change);

		/**
			given a value from the board_, determines whether it's a piece (and not an empty square,
			the goal, etc.)
			@param piece the board value to be checked
			@return whether the board value is actually a piece (true if it is)
		*/
		bool is_piece(int piece);

		/**
   			used to swap the indices/piece values of two pieces on the board_ in the normalize
			function
  			@param index1 the first index to be switched
			@param index2 the second index to be switched			
		*/
		void swap_indices(int index1, int index2);

		static const int GOAL = -1;
		static const int EMPTY = 0;
		static const int WALL = 1;
		static const int MASTER = 2;

		std::vector<std::vector<int>> board_;

};

#endif
