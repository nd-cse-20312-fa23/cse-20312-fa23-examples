CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture03 -I../lecture07 -I../lecture12
LD=		gcc
LDFLAGS=

all:		set_test duplicates4

%.o:		%.c set.h
	$(CC) $(CFLAGS) -c -o $@ $<

set_test:	set_test.o set.o ../lecture07/array.o ../lecture12/binary_search.o
	$(LD) $(LDFLAGS) -o $@ $^

duplicates4:	duplicates4.o set.o ../lecture03/library.o ../lecture07/array.o ../lecture12/binary_search.o
	$(LD) $(LDFLAGS) -o $@ $^

test-duplicates%:	duplicates%
	for i in $$(seq 1000); do ./$<; done | time -f "\nElapsed: %E" uniq -c

clean:
	rm -f set_test duplicates4 *.o
