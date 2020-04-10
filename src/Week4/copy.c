#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void inefficient_copy();
void efficient_copy();

int main(void)
{
    inefficient_copy();
    efficient_copy();
}

void inefficient_copy()
{
    printf("inefficient_copy\n");
    char *s = get_string("s: ");
    char *t = s; //copies string's address

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}

void efficient_copy()
{
    printf("efficient_copy\n");
    char *s = get_string("s: ");
    //malloc always returns the address of the first byte only out of thw whole chunk of allocated memory
    char *t = malloc(strlen(s) + 1); //memory allocate, + 1 because we need to have null character

    //strcpy(t, s); //to copy the string directly using library
    for (int i = 0, n = strlen(s); i < n + 1; i++) //n + 1 because we also wanna copy the null char in s
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); //freeing the memory that we allocated by doing malloc
}