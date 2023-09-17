CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture16 -O2
LD=		gcc
LDFLAGS=
TARGETS=	quick_sort ../lecture16/merge_sort

all:		$(TARGETS)

%.o:		%.c ../lectur16/utils.h
	$(CC) $(CFLAGS) -c -o $@ $<

quick_sort:	quick_sort.o ../lecture16/utils.o
	$(LD) $(LDFLAGS) -o $@ $^

benchmark:	$(TARGETS)
	@time -f "    Merge Sort: %E" ../lecture16/merge_sort
	@time -f "    Quick Sort: %E" ./quick_sort

clean:
	rm -f quick_sort *.o
