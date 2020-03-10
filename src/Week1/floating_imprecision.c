// Floating-point arithmetic with float

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");

    // Perform division
    printf("x / y = %f\n", x / y);
    printf("x / y = %.50f\n", x / y); //floating point imprecision (as the computer is storing the closest possible match, because with limited
    //memory and space, it cannot store all the bits after the decimal)
}