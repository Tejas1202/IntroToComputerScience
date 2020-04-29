#include <cs50.h>
#include <math.h>
#include <stdio.h>

const int QUARTERS = 25;
const int DIMES = 10;
const int NICKELS = 5;
const int PENNIES = 1;

int number_of_coins(int cents);

int main(void)
{
    float n = 0;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    int cents = round(n * 100);
    printf("%i\n", number_of_coins(cents));
}

//Returns the number of coins needed to give the change
int number_of_coins(int cents)
{
    int coins = 0;
    while (cents != 0)
    {
        if (cents - QUARTERS >= 0)
        {
            cents -= QUARTERS;
            coins++;
        }
        else if (cents - DIMES >= 0)
        {
            cents -= DIMES;
            coins++;
        }
        else if (cents - NICKELS >= 0)
        {
            cents -= NICKELS;
            coins++;
        }
        else
        {
            cents -= PENNIES;
            coins++;
        }
    }
    return coins;
}