PAGER=less
COMP=g++
DEBUG=gdb
STANDARD=gnu++11
COMPOPS=-g -Wall -std=$(STANDARD)
OBJECTOPS=-c -obuild/

.PHONY: walk correct clean

walk: walk.out
	@./walk.out $(STRAT) $(FILE) $(MOVES)

correct: results/results.test
	@$(PAGER) results/results.test

results/results.test: correct.out
	@./correct.out > results/results.test

walk.out: drivers/walk.cpp build/SlidingBrickPuzzle.o build/Move.o build/RandomWalk.o build/UninformedWalk.o build/BreadthFirstWalk.o build/MoveNode.o build/DepthFirstWalk.o build/DepthLimitedWalk.o build/IterativeDeepeningWalk.o
	$(COMP) -owalk.out $(COMPOPS) drivers/walk.cpp build/SlidingBrickPuzzle.o build/Move.o build/RandomWalk.o build/UninformedWalk.o build/BreadthFirstWalk.o build/DepthFirstWalk.o build/IterativeDeepeningWalk.o build/MoveNode.o build/DepthLimitedWalk.o

correct.out: drivers/correct.cpp build/SlidingBrickPuzzle.o build/Move.o
	@$(COMP) -ocorrect.out $(COMPOPS) drivers/correct.cpp build/SlidingBrickPuzzle.o build/Move.o

build/SlidingBrickPuzzle.o: src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp
	@gcc $(OBJECTOPS)SlidingBrickPuzzle.o $(COMPOPS) src/SlidingBrickPuzzle.cpp

build/Move.o: src/moves/Move.h src/moves/Move.cpp
	@gcc $(OBJECTOPS)Move.o $(COMPOPS) src/moves/Move.cpp

build/RandomWalk.o: src/walks/Walk.h src/walks/RandomWalk.h src/walks/RandomWalk.cpp
	@gcc $(OBJECTOPS)RandomWalk.o $(COMPOPS) src/walks/RandomWalk.cpp

build/UninformedWalk.o: src/walks/Walk.h src/walks/UninformedWalk.h src/walks/UninformedWalk.cpp 
	@gcc $(OBJECTOPS)UninformedWalk.o $(COMPOPS) src/walks/UninformedWalk.cpp

build/BreadthFirstWalk.o: src/walks/UninformedWalk.h src/walks/BreadthFirstWalk.h src/walks/BreadthFirstWalk.cpp
	@gcc $(OBJECTOPS)BreadthFirstWalk.o $(COMPOPS) src/walks/BreadthFirstWalk.cpp

build/DepthFirstWalk.o: src/walks/UninformedWalk.h src/walks/DepthFirstWalk.h src/walks/DepthFirstWalk.cpp
	@gcc $(OBJECTOPS)DepthFirstWalk.o $(COMPOPS) src/walks/DepthFirstWalk.cpp

build/IterativeDeepeningWalk.o: src/walks/IterativeDeepeningWalk.h src/walks/IterativeDeepeningWalk.cpp
	gcc $(OBJECTOPS)IterativeDeepeningWalk.o $(COMPOPS) src/walks/IterativeDeepeningWalk.cpp

build/DepthLimitedWalk.o: src/walks/DepthLimitedWalk.h src/walks/DepthLimitedWalk.cpp
	gcc $(OBJECTOPS)DepthLimitedWalk.o $(COMPOPS) src/walks/DepthLimitedWalk.cpp

build/MoveNode.o: src/moves/MoveNode.h src/moves/MoveNode.cpp
	@gcc $(OBJECTOPS)MoveNode.o $(COMPOPS) src/moves/MoveNode.cpp

debug: correct.out
	@$(DEBUG) ./correct.out

clean:
	@rm -rf *.out build/*.o
