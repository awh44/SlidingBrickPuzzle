#include "Walk.h"
#include "SlidingBrickPuzzle.h"

class RandomWalk : public Walk
{
	public:
		/**
			creates a new RandomWalk with the given SlidingBrickPuzzle; when walk is called, it will
			stop after max_moves number of iterations
		*/
		RandomWalk(SlidingBrickPuzzle puzzle, size_t max_moves);

		/**
			does a random walk of the SlidingBrickPuzzle member variable puzzle_
		*/
		void walk(void);

	private:
		size_t max_moves_;
};
