#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc == 2) //Means if the user has typed two words at their prompt
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}