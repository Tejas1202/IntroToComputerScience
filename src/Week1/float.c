#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float price = get_float("What's the price?\n");
    printf("Your total bill is %.2f (Inclusive of sales tax)\n", price * (1.18));
    float f = 0.1 + 0.2;
    printf("%f\n", f);
}