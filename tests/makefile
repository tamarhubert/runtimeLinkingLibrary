CC=gcc
CFLAGS=-I. -g

%.o: %.c
	$(CC) -c -fPIC -o ../obj/$@ $< $(CFLAGS)

%.so: %.c
	$(CC) -shared -fPIC -o ../obj/$@ $< $(CFLAGS)

make: runtimeLinkingTests.o testLibrary.so
	cd ../src && $(MAKE)
	$(CC) -o ../obj/runtimeLinkingTests ../obj/runtimeLinkingTests.o ../obj/runtimeLinking.o -ldl
