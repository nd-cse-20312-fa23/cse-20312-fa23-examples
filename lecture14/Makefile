CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		bitset_test

%.o:		%.c bitset.h
	$(CC) $(CFLAGS) -c -o $@ $<

bitset_test:	bitset_test.o bitset.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f bitset_test *.o
