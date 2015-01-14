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
		SlidingBrickPuzzle(SlidingBrickPuzzle &orig);

		bool load_game(std::string filename);
		void print_board(std::ostream &out = std::cout);
		bool is_solved(void);
		std::vector<Direction> moves_for_piece(int piece);
		std::vector<Move> all_moves();

	private:
		static const int GOAL = -1;
		static const int EMPTY = 0;
		static const int WALL = 1;
		static const int MASTER = 2;

		std::vector<std::vector<int>> board_;
		
		static std::vector<std::string> split(std::string s, char delim = ',');
		
		std::vector<Direction> process_moves(int piece, size_t row, size_t column);
		bool check_direction(int piece, size_t row, size_t column, int vert_change, int hor_change);
		bool is_piece(int piece);
};

#endif
