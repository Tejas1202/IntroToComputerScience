#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));
    *x = 43;
    *y = 15; //as we've not assigned any memory to this address, it can contain any garbage value from the other programs as well
    //so when we try to deference this pointer, it can give segmentation fault/anything bad can happen
    //Henceforth any varable should be assigned should be intialized to avoid putting any garbage value in it.
}