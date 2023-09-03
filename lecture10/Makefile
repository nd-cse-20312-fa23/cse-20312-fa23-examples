CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		queue_test

%.o:		%.c queue.h
	$(CC) $(CFLAGS) -c -o $@ $<

queue_test:	queue_test.o queue.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f queue_test *.o
