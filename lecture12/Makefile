CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture07
LD=		gcc
LDFLAGS=

all:		linear_search binary_search

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

linear_search:	linear_search.o ../lecture07/array.o
	$(LD) $(LDFLAGS) -o $@ $^

binary_search:	binary_search.o ../lecture07/array.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f linear_search binary_search *.o
