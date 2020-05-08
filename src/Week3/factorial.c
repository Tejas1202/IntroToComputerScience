//Factorial using recursion

#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 1);

    printf("The factorial of %i is %i\n", n, fact(n));
}

int fact(int n)
{
    //base case
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}