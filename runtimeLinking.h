// The runtime linking library

#ifndef RUNTIME_LINKING_H_
#define RUNTIME_LINKING_H_

// define errors
#define FAILED_ERROR -1;
#define PATH_ERROR -2
#define LOAD_ERROR -3
#define NOT_IMPLEMENTED -99

// define statuses
#define SUCCESS_STATUS 1

typedef struct rll_Library rll_Library;

struct rll_Library {
	char* path
	void* _handler
};

int rll_load(rll_Library);
int rll_destroy(rll_Library);
void* rll_getFunction(rll_Library, char*);

#endif /* RUNTIME_LINKING_H_ */
