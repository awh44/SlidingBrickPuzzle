#ifndef _WALK_H_
#define _WALK_H_

#include "SlidingBrickPuzzle.h"

class Walk
{
	public:
		virtual void walk() = 0;

	protected:
		SlidingBrickPuzzle puzzle_;
		
};

#endif
