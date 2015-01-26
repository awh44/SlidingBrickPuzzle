#include "DepthFirstWalk.h"
#include "../../../../Personal/Stack/Stack.h"

DepthFirstWalk::DepthFirstWalk(SlidingBrickPuzzle puzzle)
	: UninformedWalk(puzzle)
{
	open_list_ = new Stack<MoveNode*>();
}
