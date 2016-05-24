/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#ifdef _WIN32
#include <windows.h>

void* rll_open(const char *file){
    return LoadLibrary(file);
}

int rll_close(void* handle){
    return FreeLibrary(handle);
}

void* rll_get(void* handle, const char *symbol){
    return GetProcAddress(handle, symbol);
}

char* rll_error() {
    DWORD errorMessageID = GetLastError();
    if(errorMessageID == 0)
        return NULL;

    LPSTR messageBuffer = NULL;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
    return messageBuffer;
}
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

