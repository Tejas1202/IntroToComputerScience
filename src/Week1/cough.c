#include <cs50.h>
#include <stdio.h>

//This is called prototype (as cough function is declared below main function, so C won't be able to recognize it (as C compiler reads from top to bottom) until we give a prototype or else we had to declare it above main function)
void cough(int n); 

int main(void)
{
    cough(3);
}

//making a different function (i.e. abstraction: hiding the implementation details. User don't need to know how you cough, whether you use printf or not etc.)
void cough(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("cough\n");
    }
}