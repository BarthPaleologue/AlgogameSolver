LEVEL?=38#the default level is 38, to use level 12, add "LEVEL=12" at the end of your command OR replace this line by : LEVEL=12
CFLAGS = -Wall -Wextra -g -o3 -I ./levels/$(LEVEL) -I .
LDFLAGS = -g

SPECIFICS =./levels/$(LEVEL)/

OBJ = colors.h paths.o generator.o executeProgram.o matrix.o dartAgent.o game.o stack.o $(SPECIFICS)level_specifics.o debug.o

anew: new
	./main

new: clean
	make main
	make print-level

run-build: build-check
	./main

build-check: run-test
	make clean
	make main
	make print-level

run-test: clean 
	make test LEVEL=12
	./test
	make clean
	make test LEVEL=38
	./test
	make clean

main: main.o $(OBJ)

test: test.o $(OBJ)

print-level: 
	@echo
	@echo LEVEL set to $(LEVEL)
	@echo

clean:
	rm -f *.o main test
	rm -f ./levels/*/*.o
