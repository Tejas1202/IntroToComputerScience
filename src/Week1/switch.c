//Switch case statements without break, executing each statement after the first condition becomes true

#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int x = get_int("Countdown: ");
    switch(x)
    {
        case 3:
        printf("Three\n");
        sleep(1);
        case 2:
        printf("Two\n");
        sleep(1);
        case 1:
        printf("One\n");
        sleep(1);
        default:
        printf("BlastOff\n");
    }
}