#include "BreadthFirstWalk.h"
#include "../../../../Personal/Queue/Queue.h"

BreadthFirstWalk::BreadthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Queue<MoveNode*>();
	std::cout << open_list_ << std::endl;
}
