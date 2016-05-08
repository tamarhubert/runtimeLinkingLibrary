/*
* The linked list library
*
* Created by: Tamar Hubert
*/
#ifndef RUNTIME_LINKING_H_
#define RUNTIME_LINKING_H_

void* rll_open(const char*);
int rll_close(void*);
void* rll_get(void*, const char*);
char* rll_error();

#endif /* RUNTIME_LINKING_H_ */
