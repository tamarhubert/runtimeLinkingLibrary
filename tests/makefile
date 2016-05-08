CC=gcc
CFLAGS=-I.
DEPS = runtimeLinking.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.so: %.c
	$(CC) -shared -fPIC -o $@ $< $(CFLAGS)

make: runtimeLinkingTests.o testLibrary.so
	cd .. && $(MAKE)
	$(CC) -o runtimeLinkingTests runtimeLinkingTests.o ../runtimeLinking.o -ldl
