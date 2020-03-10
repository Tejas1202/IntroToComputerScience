#include <cs50.h> //for using string keyword and get_string function as they aren't part of C language (also include -lcs50 at last for compiling)
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name?\n");
    printf("hello, %s\n", answer);
}