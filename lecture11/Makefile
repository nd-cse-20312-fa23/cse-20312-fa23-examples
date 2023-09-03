CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		deque_test

%.o:		%.c deque.h
	$(CC) $(CFLAGS) -c -o $@ $<

deque_test:	deque_test.o deque.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f deque_test *.o
