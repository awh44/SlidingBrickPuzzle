#include <unordered_set>

#include "Walk.h"
#include "../SlidingBrickPuzzle.h"
#include "../structures/Collection.h"
#include "../moves/MoveNode.h"

class AStarWalk : public Walk
{
	public:
		AStarWalk(SlidingBrickPuzzle puzzle);
		~AStarWalk();

		bool walk(void);

	private:
		void insert_all(MoveNode *curr_node);
		void print_solution(MoveNode *solution_node);
		void print_recursive(MoveNode *solution_node);

		MoveNode *root_;
		Collection<MoveNode *> *open_list_;
		std::unordered_set<MoveNode*, HashMoveNode, EqualMoveNode> closed_list_;
};
