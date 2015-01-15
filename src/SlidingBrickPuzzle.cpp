#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <map>

#include "SlidingBrickPuzzle.h"
#include "Move.h"

SlidingBrickPuzzle::SlidingBrickPuzzle(const SlidingBrickPuzzle &orig)
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

std::vector<Move> SlidingBrickPuzzle::all_moves(void)
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
					moves.push_back(Move(board_val, piece_moves[k], i, j));
				}
			}
		}
	}

	return moves;
}

void SlidingBrickPuzzle::apply_move(Move move)
{
	int piece = move.get_piece();
	size_t row = move.get_row(), column = move.get_column();
	Direction direction = move.get_direction();

	if (direction == Direction::UP)
	{
		size_t last_row = row;
		while (board_[last_row + 1][column] == piece)
		{
			last_row++;
		} 

		do
		{
			board_[row - 1][column] = piece;
			board_[last_row][column] = EMPTY;
			column++;
		} while (board_[row][column] == piece);
	}
	else if (direction == Direction::DOWN)
	{
		size_t last_row = row;
		while (board_[last_row + 1][column] == piece)
		{
			last_row++;
		}

		do
		{
			board_[last_row + 1][column] = piece;
			board_[row][column] = EMPTY;
			column++;
		} while (board_[row][column] == piece);
	}
	else if (direction == Direction::LEFT)
	{
		size_t last_column = column;
		while (board_[row][last_column + 1] == piece)
		{
			last_column++;
		}

		do
		{
			board_[row][column - 1] = piece;
			board_[row][last_column] = EMPTY;
			row++;
		} while (board_[row][column] == piece);
	}
	else if (direction == Direction::RIGHT)
	{
		size_t last_column = column;
		while (board_[row][last_column + 1] == piece)
		{
			last_column++;
		}

		do
		{
			board_[row][column] = EMPTY;
			board_[row][last_column + 1] = piece;
			row++;
		} while (board_[row][column] == piece);
	}
}

SlidingBrickPuzzle SlidingBrickPuzzle::apply_move_clone(Move move)
{
	SlidingBrickPuzzle new_puzzle(*this);
	new_puzzle.apply_move(move);
	return new_puzzle;
}

void SlidingBrickPuzzle::normalize(void)
{
	int current_index = 3;
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_[i].size(); j++)
		{
			int board_val = board_[i][j];
			if (board_val == current_index)
			{
				current_index++;
			}
			else if (board_val > current_index)
			{
				swap_indices(current_index, board_val);
				current_index++;
			}
		}
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

bool SlidingBrickPuzzle::equal(const SlidingBrickPuzzle &other)
{
	return board_ == other.board_;
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

bool SlidingBrickPuzzle::is_valid_place(int piece, int board_val)
{
	return (board_val == EMPTY) || ((piece == MASTER) && (board_val == GOAL));
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

std::vector<SlidingBrickPuzzle::Direction> SlidingBrickPuzzle::process_moves(int piece, size_t row, size_t column)
{
	std::vector<Direction> moves;

	if (check_up(piece, row, column))
	{
		moves.push_back(Direction::UP);
	}

	if (check_down(piece, row, column))
	{
		moves.push_back(Direction::DOWN);
	}

	if (check_left(piece, row, column))
	{
		moves.push_back(Direction::LEFT);
	}

	if (check_right(piece, row, column))
	{
		moves.push_back(Direction::RIGHT);
	}

	return moves;
}

bool SlidingBrickPuzzle::check_up(int piece, size_t row, size_t column)
{
	while (board_[row][column] == piece)
	{
		if (!is_valid_place(piece, board_[row - 1][column]))
		{
			return false;
		}

		column++;
	}

	return true;
}

bool SlidingBrickPuzzle::check_down(int piece, size_t row, size_t column)
{
	//move the row down until it hits the bottom row of the piece
	while (board_[row + 1][column] == piece)
	{
		row++;
	}

	while (board_[row][column] == piece)
	{
		if (!is_valid_place(piece, board_[row + 1][column]))
		{
			return false;
		}

		column++;
	}

	return true;
}

bool SlidingBrickPuzzle::check_left(int piece, size_t row, size_t column)
{
	while (board_[row][column] == piece)
	{
		if (!is_valid_place(piece, board_[row][column - 1]))
		{
			return false;
		}

		row++;
	}

	return true;
}

bool SlidingBrickPuzzle::check_right(int piece, size_t row, size_t column)
{
	//move the column to the right until it hits the right edge of the piece
	while (board_[row][column + 1] == piece)
	{
		column++;
	}

	while (board_[row][column] == piece)
	{
		if (!is_valid_place(piece, board_[row][column + 1]))
		{
			return false;
		}

		row++;
	}

	return true;
}

bool SlidingBrickPuzzle::is_piece(int piece)
{
	return piece >= MASTER;
}

void SlidingBrickPuzzle::swap_indices(int index1, int index2)
{
	for (size_t i = 0; i < board_.size(); i++)
	{
		for (size_t j = 0; j < board_[i].size(); j++)
		{
			if (board_[i][j] == index1)
			{
				board_[i][j] = index2;
			}
			else if (board_[i][j] == index2)
			{
				board_[i][j] = index1;
			}
		}
	}	
}
