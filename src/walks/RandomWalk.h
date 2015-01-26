/**
	Austin Herring
	January 19, 2015
	RandomWalk.h - header for a RandomWalk class for the SlidingBrickPuzzle game. Given a puzzle and
	a maximum number of moves to make, this class, when told to walk, will choose random Moves to
	make out of all of the ones available, quitting either when the puzzle is solved or when the
	maximum number of moves has been reached. 
*/

#include "Walk.h"
#include "../SlidingBrickPuzzle.h"

class RandomWalk : public Walk
{
	public:
		/**
			creates a new RandomWalk with the given SlidingBrickPuzzle; when walk is called, it will
			stop after max_moves number of iterations
			@param puzzle the puzzle on which the walk is to be performed
			@param max_moves the maximum number of moves to make before quitting the walk
		*/
		RandomWalk(SlidingBrickPuzzle puzzle, size_t max_moves);

		/**
			does a random walk of the SlidingBrickPuzzle member variable puzzle_
		*/
		bool walk(void);

	private:
		SlidingBrickPuzzle puzzle_;
		size_t max_moves_;
};
