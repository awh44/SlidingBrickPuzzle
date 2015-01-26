sAGER=less
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

walk.out: drivers/walk.cpp build/SlidingBrickPuzzle.o build/Move.o build/RandomWalk.o build/UninformedWalk.o build/BreadthFirstWalk.o build/MoveNode.o build/DepthFirstWalk.o build/IterativeDeepeningWalk.o
	@$(COMP) -owalk.out $(COMPOPS) drivers/walk.cpp build/SlidingBrickPuzzle.o build/Move.o build/RandomWalk.o build/UninformedWalk.o build/BreadthFirstWalk.o build/DepthFirstWalk.o build/IterativeDeepeningWalk.o build/MoveNode.o

correct.out: drivers/correct.cpp build/SlidingBrickPuzzle.o build/Move.o
	@$(COMP) -ocorrect.out $(COMPOPS) drivers/correct.cpp build/SlidingBrickPuzzle.o build/Move.o

build/SlidingBrickPuzzle.o: src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp
	@gcc $(OBJECTOPS)SlidingBrickPuzzle.o $(COMPOPS) src/SlidingBrickPuzzle.cpp

build/Move.o: src/Move.h src/Move.cpp
	@gcc $(OBJECTOPS)Move.o $(COMPOPS) src/Move.cpp

build/RandomWalk.o: src/Walk.h src/RandomWalk.h src/RandomWalk.cpp
	@gcc $(OBJECTOPS)RandomWalk.o $(COMPOPS) src/RandomWalk.cpp

build/UninformedWalk.o: src/Walk.h src/UninformedWalk.h src/UninformedWalk.cpp 
	@gcc $(OBJECTOPS)UninformedWalk.o $(COMPOPS) src/UninformedWalk.cpp

build/BreadthFirstWalk.o: src/BreadthFirstWalk.h src/BreadthFirstWalk.cpp
	@gcc $(OBJECTOPS)BreadthFirstWalk.o $(COMPOPS) src/BreadthFirstWalk.cpp

build/DepthFirstWalk.o: src/DepthFirstWalk.h src/DepthFirstWalk.cpp
	@gcc $(OBJECTOPS)DepthFirstWalk.o $(COMPOPS) src/DepthFirstWalk.cpp

build/IterativeDeepeningWalk.o: src/IterativeDeepeningWalk.h src/IterativeDeepeningWalk.cpp
	@gcc $(OBJECTOPS)IterativeDeepeningWalk.o $(COMPOPS) src/IterativeDeepeningWalk.cpp

build/MoveNode.o: src/MoveNode.h src/MoveNode.cpp
	@gcc $(OBJECTOPS)MoveNode.o $(COMPOPS) src/MoveNode.cpp

debug: correct.out
	@$(DEBUG) ./correct.out

clean:
	@rm -rf *.out build/*.o
