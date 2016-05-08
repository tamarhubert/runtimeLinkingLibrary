CC=gcc
CFLAGS=-I.
DEPS = runtimeLinking.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: runtimeLinking.o
