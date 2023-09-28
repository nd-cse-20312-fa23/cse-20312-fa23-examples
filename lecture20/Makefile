CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=
TARGETS=	fibonacci

all:		$(TARGETS)

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

fibonacci:	pair.o hash.o map.o fibonacci.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o fibonacci
