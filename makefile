CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror

all: UnixLs.o
	gcc $(CFLAGS) -o UnixLs UnixLs.o

UnixLs.o: UnixLs.c
	gcc $(CFLAGS) -c UnixLs.c

clean:
	rm UnixLs *.o