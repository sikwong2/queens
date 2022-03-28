CC = CLANG
CFLAGS = -g -Wall -Wextra -Werror -Wpedantic

chess: chess.o
	$(CC) -o chess chess.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f queens *.o