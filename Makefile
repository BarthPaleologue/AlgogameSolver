CFLAGS = -Wall -Wextra -g -o3
LDFLAGS = -g

main: main.o generator.o game.o matrix.o stack.o level_specifics.o

run-build: clean
	make
	./main

test: test.o generator.o game.o matrix.o stack.o level_specifics.o

run-test: clean 
	make test
	./test

clean:
	rm -f *.o main