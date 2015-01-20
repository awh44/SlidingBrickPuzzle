PAGER=less
COMP=g++
DEBUG=gdb
STANDARD=gnu++11

.PHONY: random correct clean

random: random.out
	@./random.out $(MOVES) $(FILE)

correct: results/results.test
	@$(PAGER) results/results.test

results/results.test: correct.out
	@./correct.out > results/results.test

random.out: drivers/random.cpp SlidingBrickPuzzle.o Move.o RandomWalk.o 
	@$(COMP) -orandom.out -g -Wall -std=$(STANDARD) drivers/random.cpp SlidingBrickPuzzle.o Move.o RandomWalk.o 

correct.out: drivers/correct.cpp src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp src/Move.h src/Move.cpp 
	@$(COMP) -ocorrect.out -g -Wall -std=$(STANDARD) drivers/correct.cpp src/SlidingBrickPuzzle.cpp src/Move.cpp

SlidingBrickPuzzle.o: src/SlidingBrickPuzzle.h src/SlidingBrickPuzzle.cpp
	@gcc -c -g -Wall -std=$(STANDARD) src/SlidingBrickPuzzle.cpp

Move.o: src/Move.h src/Move.cpp
	@gcc -c -g -Wall -std=$(STANDARD) src/Move.cpp

RandomWalk.o: src/Walk.h src/RandomWalk.h src/RandomWalk.cpp
	@gcc -c -g -Wall -std=$(STANDARD) src/RandomWalk.cpp

debug: correct.out
	@$(DEBUG) ./correct.out

clean:
	@rm -rf *.out *.o
