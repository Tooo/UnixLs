CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror

all: UnixLs.o LsOutput.o
	gcc $(CFLAGS) -o UnixLs UnixLs.o LsOutput.os

UnixLs.o: UnixLs.c
	gcc $(CFLAGS) -c UnixLs.c

LsOutput.o: LsOutput.c
	gcc $(CFLAGS) -c LsOutput.c

clean:
	rm UnixLs *.o