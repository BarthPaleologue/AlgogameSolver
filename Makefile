CFLAGS = -Wall -Wextra

main: main.o algos.o matrix.o

clean:
	rm -f *.o main