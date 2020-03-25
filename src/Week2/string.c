#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    printf("Output: ");
    for(int i = 0, n = strlen(s); i < n; i++) //Not asking strlen in condition as it will be called again and again
    {
        printf("%c", s[i]);
    }
    printf("\n");
}