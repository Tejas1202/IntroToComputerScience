#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int last_uppercase_alphabet_in_decimal = 90;
const char first_letter_ascii = 'A';
const char last_letter_ascii = 'z';

int encrypt_character(int character, int key);

int main(int k, string argv[])
{
    if (k != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    string input = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] >= first_letter_ascii && input[i] <= last_letter_ascii)
        {
            printf("%c", encrypt_character(input[i], key));
        }
        else
        {
            printf("%c", input[i]);
        }

    }
    printf("\n");
    return 0;
}

// Ciphers characters based on the key provided
int encrypt_character(int character, int key)
{
    int endpoint = character <= last_uppercase_alphabet_in_decimal ? 'Z' : 'z';
    if (character + key > endpoint)
    {
        int difference = (character + key) - endpoint;
        return (endpoint - 26) + difference;
    }
    return character + key;
}