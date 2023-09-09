CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture03
LD=		gcc
LDFLAGS=

all:		bitset_test duplicates5

%.o:		%.c bitset.h
	$(CC) $(CFLAGS) -c -o $@ $<

bitset_test:	bitset_test.o bitset.o
	$(LD) $(LDFLAGS) -o $@ $^

duplicates5:	duplicates5.o bitset.o ../lecture03/library.o
	$(LD) $(LDFLAGS) -o $@ $^

test-duplicates%:	duplicates%
	for i in $$(seq 1000); do ./$<; done | time -f "\nElapsed: %E" uniq -c

clean:
	rm -f bitset_test duplicates5 *.o
