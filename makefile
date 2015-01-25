PAGER=less
COMP=g++
DEBUG=gdb
STANDARD=gnu++11
COMPOPS=-g -Wall -std=$(STANDARD)
OBJECTOPS=-c -obuild/

.PHONY: random correct clean

random: random.out
	@./random.out $(MOVES) $(FILE)

correct: results/results.test
	@$(PAGER) results/results.test

results/results.test: correct.out
	@./correct.out > results/results.test

random.out: drivers/random.cpp build/SlidingBrickPuzzle.o build/Move.o build/RandomWalk.o 
	@$(COMP) -orandom.out $(COMPOPS) drivers/random.cpp SlidingBrickPuzzle.o Move.o RandomWalk.o 

correct.out: drivers/correct.cpp build/SlidingBrickPuzzle.o build/Move.o
	@$(COMP) -ocorrect.out $(COMPOPS) drivers/correct.cpp SlidingBrickPuzzle.o Move.o

build/SlidingBrickPuzzle.o: src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp
	@gcc $(OBJECTOPS)SlidingBrickPuzzle.o $(COMPOPS) src/SlidingBrickPuzzle.cpp

build/Move.o: src/Move.h src/Move.cpp
	@gcc $(OBJECTOPS)Move.o $(COMPOPS) src/Move.cpp

build/RandomWalk.o: src/Walk.h src/RandomWalk.h src/RandomWalk.cpp
	@gcc $(OBJECTOPS)RandomWalk.o $(COMPOPS) src/RandomWalk.cpp

debug: correct.out
	@$(DEBUG) ./correct.out

clean:
	@rm -rf *.out build/*.o
