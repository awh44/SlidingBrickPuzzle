#include "Walk.h"
#include "../SlidingBrickPuzzle.h"
#include "../structures/Dictionary.h"

class AStarWalk : public Walk
{
	public:
		AStarWalk(SlidingBrickPuzzle puzzle);
		~AStarWalk();

		bool walk(void);

	private:
		MoveNode *root_;
		Collection<MoveNode *> *open_list_;
		Dictionary<MoveNode *> *closed_list_;
};
