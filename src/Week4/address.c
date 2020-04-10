#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);
    printf("%p\n", &n); //AdrressOf(n)
    printf("%i\n", *&n); //Go to that specific address

    int *p = &n; //where *p to declare a pointer and int to say that it points to an int
    printf("%p\n", p); //pointer's value
    printf("%i\n", *p); //go to that address

    //string s = "EMMA"; //Technically s is just storing the address of the first char
    //printf("%s\n", s);

    printf("For strings\n");
    //Hence we can also write that string in char * as string is cs50 specific
    char *s = "EMMA";
    printf("%s\n", s);
    //Accessing addresses of characters
    printf("%p\n", s); //Hence s is the memory address of the first char
    printf("%p\n", &s[0]); //As s[0] is a char, so &s[0] gives the address
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    //Accessing characters through addresses (doing pointer arithmetics)
    printf("%c\n", *s); //go to memory address of s
    printf("%c\n", *(s+1)); //go to memory address of (s + 1)
    printf("%c\n", *(s+2));
    printf("%c\n", *(s+3));
}