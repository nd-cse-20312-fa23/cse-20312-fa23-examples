CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture16 -I../lecture20
LD=		gcc
LDFLAGS=
TARGETS=	counting_sort

all:		$(TARGETS)

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

counting_sort:	../lecture16/utils.o ../lecture20/pair.o ../lecture20/hash.o ../lecture20/map.o counting_sort.o
	$(LD) $(LDFLAGS) -o $@ $^

benchmark:	$(TARGETS)
	@time -f "    Merge Sort: %E" ../lecture16/merge_sort
	@time -f "    Quick Sort: %E" ../lecture17/quick_sort
	@time -f " Counting Sort: %E" ./counting_sort

clean:
	rm -f *.o $(TARGETS)
