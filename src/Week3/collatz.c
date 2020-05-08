//Collatz conjecture: A program that speculates it is always possible to get back to 1 for positive integers
//Here algorithm implemented using recursion with multiple recursive cases

#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = 1;
    do
    {
        n = get_int("n: ");
    }
    while (n <= 0);

    printf("Total steps taken is %i\n", collatz(n));
}


int collatz(int n)
{
    //base case
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0) //recursive case for even numbers
    {
        return 1 + collatz(n/2);
    }
    else //recursive case for odd numbers
    {
        return 1 + collatz(3*n + 1);
    }
}