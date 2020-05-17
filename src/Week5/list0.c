// Implements a list of numbers with an array of dynamic size
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int list[3];
    int *list = malloc(3 * sizeof(int)); // can replace the above line with this, which will
    // give pointer to the first byte in the chunk of memory

    // always check as if your system for some reason runs out of memory, it'll give null
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1; // if this is at 0th byte
    list[1] = 2; // indexing 1 will access the 4th byte
    list[2] = 3; // indexing 2 will access the 8th byte
    // Hence this square bracket notation is doing all the pointer arithmetic underneath the hood

    // If we decide now that we want to store another integer, we can't just resize our array just like that (as the bytes adjacent to our last byte in
    // this array may already be occupied by another variables like EMMA etc.)
    //Now we're assigning it to a tmp instead of list directly because if we do list = realloc, then
    //we'll orphange the old memory, and we'll have no pointers pointing to it. It'll be just be floating
    //somewhere in the memory
    int *tmp = malloc(4 * sizeof(int));

    // Copy elements from old array to new array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Allocating the last element
    tmp[3] = 4;

    // Free list of size 3 (as we already copied from the old array, hence don't need that chunk of memory, so
    //it frees the memory of wherever the pointer is pointing at)
    free(list);

    // Remember list of size 4
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list of size 4
    free(list);
}