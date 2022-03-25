CC = CLANG
CFLAGS = -g -Wall -Wextra -Werror -Wpedantic

queens: queens.o
	$(CC) -o queens queens.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f queens *.o