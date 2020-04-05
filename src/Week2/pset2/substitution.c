#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool validate_key(string key);
int find_index_in_alphabets(char c);

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
    int text_length = strlen(text);
    char ciphertext[text_length + 1]; //as we have to also add null character at end for printf to identify end of string
    for (int i = 0; i < text_length; i++)
    {
        int index = 0;
        if (isupper(text[i]))
        {
            index = find_index_in_alphabets(text[i]);
            ciphertext[i] = toupper(argv[1][index]);
        }
        else if (islower(text[i]))
        {
            index = find_index_in_alphabets(toupper(text[i]));
            ciphertext[i] = tolower(argv[1][index]);
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    ciphertext[text_length] = '\0';
    printf("ciphertext: %s\n", ciphertext);
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

//Finds the occurence of character in alphabet
int find_index_in_alphabets(char c)
{
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] == c)
        {
            index = i;
            break;
        }
    }
    return index;
}