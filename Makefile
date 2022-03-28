CC = CLANG
CFLAGS = -g -Wall -Wextra -Werror -Wpedantic

queens: queens.o chess.o
	$(CC) -o queens queens.o chess.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f chess *.o
