CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		list_test

%.o:		%.c list.h
	$(CC) $(CFLAGS) -c -o $@ $<

list_test:	list_test.o list.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f list_test *.o
