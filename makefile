PAGER=less
COMP=g++
DEBUG=gdb

.PHONY: random correct clean

random: random.out
	@./random.out $(MOVES)

correct: results/results.test
	@$(PAGER) results/results.test

results/results.test: correct.out
	@./correct.out > results/results.test

random.out: drivers/random.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp src/Move.h src/Move.cpp src/Walk.h src/RandomWalk.h src/RandomWalk.cpp
	$(COMP) -orandom.out -g -Wall -std=gnu++11 drivers/random.cpp src/SlidingBrickPuzzle.cpp src/Move.cpp src/RandomWalk.cpp

correct.out: drivers/correct.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp src/Move.h src/Move.cpp 
	@$(COMP) -ocorrect.out -g -Wall -std=gnu++11 drivers/correct.cpp src/SlidingBrickPuzzle.cpp src/Move.cpp

debug: correct.out
	@$(DEBUG) ./correct.out

clean:
	@rm *.out
