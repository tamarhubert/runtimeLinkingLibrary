CC=gcc
CFLAGS=-I. -g
DEPS = runtimeLinking.h

%.o: %.c $(DEPS)
	$(CC) -c -o ../obj/$@ $< $(CFLAGS)

make: runtimeLinking.o
