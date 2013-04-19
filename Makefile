CC=gcc
CFLAGS=-Wall -Wextra -Wno-unused-parameter -lpthread

SOURCES=queue.c queue_internal.c

all:
	$(CC) $(CFLAGS) -dynamiclib -o libqueue.dylib $(SOURCES)

examples: libqueue.dylib
	$(CC) $(CFLAGS) -I. -L. -lqueue -o example example.c

clean:
	rm -f example libqueue.dylib