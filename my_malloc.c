#include <sys/types.h>
#include <unistd.h>

#include "my_malloc.h"
#include <stdio.h>

void *my_malloc_v1(size_t size) {
    void *p;

    // Get current break
    p = sbrk(0);

    // If failed, return NULL
    if (sbrk(size) == (void *) -1) {
        return NULL;
    } else {
        return p;
    }
}