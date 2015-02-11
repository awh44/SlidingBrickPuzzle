#!/bin/bash

(time ./walk.out a input/SBP-level0.txt) > AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-level1.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-level2.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-level3.txt) >> AStarResults 2>&1
echo >> AStarResults

(time ./walk.out a input/SBP-bricks-level1.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level2.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level3.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level4.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level5.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level6.txt) >> AStarResults 2>&1
echo >> AStarResults
(time ./walk.out a input/SBP-bricks-level7.txt) >> AStarResults 2>&1
