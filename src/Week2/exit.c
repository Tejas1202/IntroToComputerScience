#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]); //as argv[0] will be the program name
    return 0;
}