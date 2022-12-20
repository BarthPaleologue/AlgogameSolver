CFLAGS = -Wall -Wextra -g -o3
LDFLAGS = -g


build-check: run-test
	make clean
	make main

main: main.o generator.o executeProgram.o matrix.o instructionsImplementations.o stack.o level_specifics.o print.o

run-build: clean
	make
	./main

test: test.o generator.o executeProgram.o matrix.o instructionsImplementations.o stack.o level_specifics.o print.o

run-test: clean 
	make test
	./test

new: clean
	make main

anew: new
	./main

clean:
	rm -f *.o main
