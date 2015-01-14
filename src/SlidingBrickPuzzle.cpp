#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <map>

#include "SlidingBrickPuzzle.h"
#include "Move.h"

SlidingBrickPuzzle::SlidingBrickPuzzle(SlidingBrickPuzzle &orig)
{
	board_ = orig.board_;
}

bool SlidingBrickPuzzle::load_game(std::string filename)
{
	std::ifstream fin(filename.c_str());

	if (fin.fail())
	{
		return false;
	}
	
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
	
	size_t width, height;
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

	for (size_t row = 0; row < board_.size(); row++)
	{
		std::getline(fin, line);
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
	for (size_t row = 0; row < board_.size(); row++)
	{
		for (size_t column = 0; column < board_[row].size(); column++)
		{
			if (board_[row][column] == piece)
			{
				return process_moves(piece, row, column);
			}
		}
	}

	return std::vector<Direction>();
}

std::vector<SlidingBrickPuzzle::Direction> SlidingBrickPuzzle::process_moves(int piece, size_t row, size_t column)
{
	std::vector<Direction> moves;

	if (check_direction(piece, row, column, -1, 0))
	{
		moves.push_back(Direction::UP);
	}

	if (check_direction(piece, row, column, 1, 0))
	{
		moves.push_back(Direction::DOWN);
	}

	if (check_direction(piece, row, column, 0, -1))
	{
		moves.push_back(Direction::LEFT);
	}

	if (check_direction(piece, row, column, 0, 1))
	{
		moves.push_back(Direction::RIGHT);
	}

	return moves;
}

bool SlidingBrickPuzzle::check_direction(int piece, size_t row, size_t column, int vert_change, int hor_change)
{
	size_t i = row, j = column;
	int i_change = abs(hor_change), j_change = abs(vert_change);

	while (board_[i][j] == piece)
	{
		int board_val = board_[i + vert_change][j + hor_change];
		if (board_val != EMPTY && (piece != MASTER || board_val != GOAL))
		{
			return false;
		}
		i += i_change;
		j += j_change;
	}

	return true;
}

std::vector<Move> SlidingBrickPuzzle::all_moves()
{
	std::vector<Move> moves;
	std::map<int, bool> seen;
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_[i].size(); j++)
		{
			int board_val = board_[i][j];
			if (is_piece(board_val) && !seen[board_val])
			{
				seen[board_val] = true;
				std::vector<Direction> piece_moves = process_moves(board_val, i, j);
				for (size_t k = 0; k < piece_moves.size(); k++)
				{
					moves.push_back(Move(board_val, piece_moves[k]));
				}
			}
		}
	}
	return moves;
}

bool SlidingBrickPuzzle::is_piece(int piece)
{
	return piece >= MASTER;
}
