#include <iostream>
#include <vector>
#include <string>

class SlidingBrickPuzzle;

class SlidingBrickPuzzle
{
	public:
		SlidingBrickPuzzle() {}
		SlidingBrickPuzzle(SlidingBrickPuzzle &orig);

		enum class Direction { UP, DOWN, LEFT, RIGHT };

		bool load_game(std::string filename);
		void print_board(std::ostream &out = std::cout);
		bool is_solved(void);
		std::vector<Direction> moves_for_piece(int piece);

	private:
		static std::vector<std::string> split(std::string s, char delim = ',');

		static const int GOAL = -1;
		static const int EMPTY = 0;
		static const int WALL = 1;
		static const int MASTER = 2;

		std::vector<std::vector<int>> board_;
};
