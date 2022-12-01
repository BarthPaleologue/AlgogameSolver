CFLAGS = -Wall -Wextra -g -o3
LDFLAGS = -g

main: main.o generator.o game.o matrix.o stack.o level_specifics.o

build-run: main
	./main

test: test.o generator.o game.o matrix.o stack.o level_specifics.o

run-test: test
	./test

clean:
	rm -f *.o main