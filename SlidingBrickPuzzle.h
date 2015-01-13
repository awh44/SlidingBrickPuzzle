#include <iostream>
#include <vector>
#include <string>

class SlidingBrickPuzzle
{
	public:	
		bool load_game(std::string filename);
		void print_board(std::ostream &out = std::cout);

	private:
		static std::vector<std::string> split(std::string s, char delim = ',');

		static const int GOAL = -1;
		static const int EMPTY = 0;
		static const int WALL = 1;
		static const int MASTER = 2;

		std::vector<std::vector<int>> board_;
};
