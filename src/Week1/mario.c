#include<stdio.h>
#include<cs50.h>

void print_width(void);
void print_block(void);

int main(void)
{
    print_width();
    print_block();
}

//prints "?" in width
void print_width(void)
{
    int n;
    do
    {
        n = get_int("Width: ");
    } while(n < 1);
    for(int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}

//Prints n by n grid of blocks
void print_block(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    } while(n < 1);
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}