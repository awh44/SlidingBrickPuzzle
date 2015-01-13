#include <fstream>
#include <stdexcept>
#include <iostream>

#include "SlidingBrickPuzzle.h"

SlidingBrickPuzzle::SlidingBrickPuzzle(SlidingBrickPuzzle &orig)
{
	board_ = orig.board_;
}

bool SlidingBrickPuzzle::load_game(std::string filename)
{
	std::ifstream fin(filename.c_str());
	
	std::string line;
	std::getline(fin, line);
	if (fin.eof())
	{
		return false;
	}

	std::vector<std::string> wh = split(line);
	if (wh.size() != 2)
	{
		return false;
	}
	
	int width, height;
	try
	{
		width = stoi(wh[0]);
		height = stoi(wh[1]);
	}
	catch (const std::invalid_argument &e)
	{
		return false;
	}

	board_ = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));

	size_t row = 0;
	std::getline(fin, line);
	while (!fin.eof())
	{
		std::vector<std::string> split_line = split(line);
		if (split_line.size() != width)
		{
			return false;
		}

		for (size_t column = 0; column < width; column++)
		{
			try
			{
				board_[row][column] = std::stoi(split_line[column]);
			}
			catch (const std::invalid_argument &e)
			{
				return false;
			}
		}
		row++;
		std::getline(fin, line);
	}

	if (row != height)
	{
		return false;
	}

	return true;
}

std::vector<std::string> SlidingBrickPuzzle::split(std::string s, char delim)
{
	std::vector<std::string> values;
	size_t start = 0, end = s.find_first_of(delim, 1);
	while (end != std::string::npos)
	{
		values.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find_first_of(delim, start + 1);
	}

	return values;
}

void SlidingBrickPuzzle::print_board(std::ostream &out)
{
	if (board_.size() < 1)
	{
		return;
	}

	out << board_[0].size() << "," << board_.size() << std::endl;
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_[i].size(); j++)
		{
			out << board_[i][j] << ",";
		}

		out << std::endl;
	}
}

bool SlidingBrickPuzzle::is_solved(void)
{
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_[i].size(); j++)
		{
			if (board_[i][j] == GOAL)
			{
				return false;
			}
		}
	}

	return true;
}

std::vector<SlidingBrickPuzzle::Direction> SlidingBrickPuzzle::moves_for_piece(int piece)
{
	
}
