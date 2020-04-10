#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //fopen to open a file, a-for appending
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    //fileprintf => to print something to a file
    fprintf(file, "%s,%s\n", name, number);

    //close file
    fclose(file);
}