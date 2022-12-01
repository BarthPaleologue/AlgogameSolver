CFLAGS = -Wall -Wextra -g -o3
LDFLAGS = -g

main: main.o generator.o game.o matrix.o stack.o level_specifics.o

build-run: main
	./main

clean:
	rm -f *.o main