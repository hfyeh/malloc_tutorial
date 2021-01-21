#include "my_malloc.h"
#include <stdio.h>

int main() {
    void *p = my_malloc_v1(10);
    printf("p = %p\n", p);
    return 0;
}
