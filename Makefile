CFLAGS = -Wall -Wextra -g -o3
LDFLAGS = -g

main: main.o algos.o matrix.o stack.o

build-run: main
	./main

clean:
	rm -f *.o main