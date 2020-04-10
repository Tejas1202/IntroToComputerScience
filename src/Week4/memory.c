// http://valgrind.org/docs/manual/quick-start.html#quick-start.prepare
//Usage => valgrind ./memory

#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int)); //allocating memory of 40 bytes and giving the address of first byte to x
    //chunk of memory (40 bytes) is nothing but a buffer or array
    x[10] = 0; //accessing the un-allocated memory, hence buffer overflow
    free(x);
}

int main(void)
{
    f();
    return 0;
}