CC=gcc
AR=ar
CFLAGS=-Wall -Wextra -Wno-unused-parameter -fPIC -lpthread

OBJ=queue.o queue_internal.o

UNAME=$(shell uname)

all: $(OBJ)
ifeq ($(UNAME),Darwin)
	$(CC) $(CFLAGS) -dynamiclib -o libqueue.dylib $(OBJ)
	$(AR) rcs libqueue.a $(OBJ)
	$(CC) $(CFLAGS) -I. -o example example.c libqueue.a
else
ifeq ($(UNAME),Linux)
	$(CC) $(CFLAGS) -shared -o libqueue.so $(OBJ)
	$(AR) rcs libqueue.a $(OBJ)
	$(CC) $(CFLAGS) -I. -o example example.c libqueue.a
endif
endif

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f  *.o example libqueue.dylib libqueue.so libqueue.a
