#ifndef _WALK_H_
#define _WALK_H_

#include "SlidingBrickPuzzle.h"

class Walk
{
	public:
		virtual ~Walk() {};
		/**
			does a walk of the SlidingBrickPuzzle puzzle_
		*/
		virtual void walk(void) = 0;

	protected:
		SlidingBrickPuzzle puzzle_;
		
};

#endif
