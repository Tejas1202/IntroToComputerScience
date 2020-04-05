//Easier way to substitution problem (reference from internet)
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool validate_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    if (!validate_key(argv[1]))
    {
        printf("Please confirm that:\n");
        printf("1. Your key is 26 characters long\n");
        printf("2. All the letters are unique characters only irrespective of their casing\n");
        return 1;
    }

    string text = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(argv[1][text[i] - 65]));
        }
        else if(islower(text[i]))
        {
            printf("%c", tolower(argv[1][text[i] - 97]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

//validates if key is 26 characters long and has all unique characters (case insensitive)
bool validate_key(string key)
{
    if (strlen(key) == 26)
    {
        int unique_alphabet_count = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    unique_alphabet_count++;
                    break;
                }
            }
        }
        if (unique_alphabet_count == 26)
        {
            return true;
        }
    }
    return false;
}