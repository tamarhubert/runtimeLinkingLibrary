/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#ifdef _WIN32
/**
void* rll_open(const char*){

}

int rll_close(void*){

}

void* rll_get(void*, char*){

}
**/
#elif __linux__
#include <dlfcn.h>

void* rll_open(const char *file){
	return dlopen(file, RTLD_NOW | RTLD_GLOBAL);
}

int rll_close(void* handle){
    return dlclose(handle);
}

void* rll_get(void *handle, const char *symbol){
    return dlsym(handle, symbol);
}

char* rll_error(){
    return dlerror();
}

#else
#   error "Unknown compiler"
#endif

