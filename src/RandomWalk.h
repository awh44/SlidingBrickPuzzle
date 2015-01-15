#include "Walk.h"
#include "SlidingBrickPuzzle.h"

class RandomWalk : public Walk
{
	public:
		RandomWalk(SlidingBrickPuzzle puzzle, size_t max_moves);
		void walk();

	private:
		size_t max_moves_;
};
