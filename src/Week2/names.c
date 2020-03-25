#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string names[4];
    names[0] = "EMMA";
    printf("%s\n", names[0]); //when printf prints a string, it essentially loops over the characters and prints them one by one
    //by checking everytime whether it's null terminating character. If yes, it ends the loop
    printf("%c%c%c%c\n", names[0][0], names[0][1], names[0][2], names[0][3]); //2D array
    printf("%c\n", names[0][4]); //accessing null terminating character (gives space)
    printf("%i\n", names[0][4]); //casting to int gives 0
}