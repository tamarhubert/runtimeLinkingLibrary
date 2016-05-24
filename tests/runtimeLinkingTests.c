#include "../src/runtimeLinking.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32

#define LIB "./testLibrary.dll"

#elif __linux__

#define LIB "./testLibrary.so"

#else
#   error "Unknown compiler"
#endif

int main(void){
    void* handle;
    char *error;

    handle = rll_open(LIB);
    if (!handle) {
        printf("could not open shared object\n");
        if ((error = rll_error()) != NULL)  {
            printf("an error accured:\n\t%s\n", error);
        }
        exit(1);
    }

    int (*addXtoY) (int, int) = rll_get(handle, "addXtoY");
    if ((error = rll_error()) != NULL)  {
        printf("an error accured:\n\t%s\n", error);
        exit(1);
    }
    int (*subtractYfromX) (int, int) = rll_get(handle, "subtractYfromX");
    if ((error = rll_error()) != NULL)  {
        printf("an error accured:\n\t%s\n", error);
        exit(1);
    }

    printf("%i\n",addXtoY(10, 5));
    printf("%i\n",subtractYfromX(10, 5));

    rll_close(handle);
	return 0;
}
