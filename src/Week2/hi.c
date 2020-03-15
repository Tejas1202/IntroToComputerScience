#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("%i %i %i\n", c1, c2, c3); //clang implicitly casting these charaters to their respective decimals (acc.to ASCII), which are
    //then eventually stored as binary inside RAM
}