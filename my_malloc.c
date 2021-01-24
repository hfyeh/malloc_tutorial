#include <sys/types.h>
#include <unistd.h>

#include "my_malloc.h"
#include <stdio.h>

typedef struct block *block_ptr;

struct block {
    size_t size;
    block_ptr next;
    int free;
};


#define align4(x) ((((x - 1) >> 2) << 2) + 4)


// Point to the beginning of the heap
void *base = NULL;

// Find block that has greater or equal size as requested size
// Return NULL if no qualified block are present
static block_ptr find_block(block_ptr *last, size_t size) {
    block_ptr b = base;
    while (b && !(b->free && b->size >= size)) {
        *last = b;
        b = b->next;
    }
    return b;
}

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