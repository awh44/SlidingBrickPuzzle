/**
	Austin Herring
	January 19, 2015
	Walk.h - header for an abstract Walk class to be used with SlidingBrickPuzzles. Subclasses can
	specify different walks of performing searches on the board, overriding the walk method to do
	so.
*/

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
		virtual bool walk(void) = 0;
};

#endif
