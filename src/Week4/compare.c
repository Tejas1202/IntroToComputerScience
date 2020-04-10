#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: "); //Similar to string s = get_string("s: ");
    char *t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    //Eventhough the strings are same, their addresses are different in memory
    printf("%p\n", s);
    printf("%p\n", t);
}