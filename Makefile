LEVEL?=38#the default level is 38, to use level 12, add "LEVEL=12" at the end of your command
CFLAGS = -Wall -Wextra -g -o3 -I ./levels/$(LEVEL) -I .
LDFLAGS = -g

SPECIFICS =./levels/$(LEVEL)/

OBJ = generator.o executeProgram.o matrix.o instructionsImplementations.o stack.o $(SPECIFICS)level_specifics.o print.o


build-check: run-test
	make clean
	make main

main: main.o $(OBJ)

run-build: build-check
	./main

test: $(SPECIFICS)test.o $(OBJ)
	cc -g $^ -o test

run-test: clean 
	make test
	./test

new: clean
	make main

anew: new
	./main

new-test: clean
	make test

clean:
	rm -f *.o main test
	rm -f ./levels/*/*.o
