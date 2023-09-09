CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture07
LD=		gcc
LDFLAGS=

all:		search

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

search:		search.o linear_search.o binary_search.o ../lecture07/array.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f search *.o
