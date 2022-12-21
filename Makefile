LEVEL=38
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

test: test.o $(OBJ)

run-test: clean 
	make test
	./test

new: clean
	make main

anew: new
	./main

clean:
	rm -f *.o main
