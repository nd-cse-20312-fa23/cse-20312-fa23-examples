CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -O2
LD=		gcc
LDFLAGS=
TARGETS=	bubble_sort insertion_sort selection_sort merge_sort

all:		$(TARGETS)

%.o:		%.c utils.h
	$(CC) $(CFLAGS) -c -o $@ $<

bubble_sort:	bubble_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

insertion_sort:	insertion_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

selection_sort:	selection_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

merge_sort:	merge_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

benchmark:	$(TARGETS)
	@time -f "   Bubble Sort: %E" ./bubble_sort
	@time -f "Selection Sort: %E" ./selection_sort
	@time -f "Insertion Sort: %E" ./insertion_sort
	@time -f "    Merge Sort: %E" ./merge_sort

clean:
	rm -f $(TARGETS) *.o
