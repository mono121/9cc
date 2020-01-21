CFLAGS=-std=c11 -g -static
LDFLAGS = -l 9cc.h

main: main.c

test: main
	./test.sh

clean:
	rm -f main *.o *~ tmp*

.PHONY: test clean
