#!/bin/bash

(time ./walk.out a input/SBP-level0.txt) > AStarResults 2>&1
echo >> AStarResults
echo Done with level0
(time ./walk.out a input/SBP-level1.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with level1
(time ./walk.out a input/SBP-level2.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with level2
(time ./walk.out a input/SBP-level3.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with level3

(time ./walk.out a input/SBP-bricks-level1.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks1
(time ./walk.out a input/SBP-bricks-level2.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks2
(time ./walk.out a input/SBP-bricks-level3.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks3
(time ./walk.out a input/SBP-bricks-level4.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks4
(time ./walk.out a input/SBP-bricks-level5.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks5
(time ./walk.out a input/SBP-bricks-level6.txt) >> AStarResults 2>&1
echo >> AStarResults
echo Done with bricks6
(time ./walk.out a input/SBP-bricks-level7.txt) >> AStarResults 2>&1
