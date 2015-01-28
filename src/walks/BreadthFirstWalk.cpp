#include "BreadthFirstWalk.h"
#include "../structures/Queue.h"

BreadthFirstWalk::BreadthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Queue<MoveNode*>();
}
