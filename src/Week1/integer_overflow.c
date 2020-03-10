//Showing integer flow after 2 billion as integer has only 32 bits (as it fails to carry the bit)

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    for(int i = 1; ; i *= 2)
    {
        printf("%i\n", i);
        sleep(1);
    }
}