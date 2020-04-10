#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    //passing address so that scanf receives a pointer and not a copy
    //also scanf must be having int *a as it's parameter
    scanf("%i", &x); //&x suggests address of the chunk of memory that we want to put the user's input in
    printf("x is %i\n", x);

    char *s = NULL; //as NULL means there is no memory allocated yet
    printf("s: ");
    //if we don't add \n in scanf, then the scanf function after that doesn't work properly
    scanf("%s\n",s); //as s is itself a pointer/address
    printf("s is %s\n", s); //as there was no memory allocated for the string (e.g. EMMA) to store in, it printed out null

    //so instead, we use array here and pass EMMA to that
    //note: a longer string gets cut because due to insufficient memory allocation
    char t[5]; //array treated as a pointer as it's also a chunk of contiguous memory like char star (or string)
    printf("t: ");
    scanf("%s\n", t); //Hence scanf treating the array t as a pointer taking the address of first byte of memory of t
    printf("t is %s\n", t);
}