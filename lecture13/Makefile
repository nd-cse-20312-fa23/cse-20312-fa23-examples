CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture07 -I../lecture12
LD=		gcc
LDFLAGS=

all:		set_test

%.o:		%.c set.h
	$(CC) $(CFLAGS) -c -o $@ $<

set_test:	set_test.o set.o ../lecture07/array.o ../lecture12/binary_search.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f set_test *.o
