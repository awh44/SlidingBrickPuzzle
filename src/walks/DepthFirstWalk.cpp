#include "DepthFirstWalk.h"
#include "../structures/Stack.h"

DepthFirstWalk::DepthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Stack<MoveNode*>();
}
