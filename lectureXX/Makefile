CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		buffer_test

%.o:		%.c buffer.h
	$(CC) $(CFLAGS) -c -o $@ $<

buffer_test:	buffer_test.o buffer.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f buffer_test *.o
