// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//Prototype for adding node to Hash Table at given index
void add(int index, node *n);

// Number of buckets in hash table
const unsigned int N = 26;

// First uppercase letter in ASCII
const unsigned ASCII = 65;

// Hash table
node *table[N];

//Total number of words loaded in dictionary
int number_of_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //selecting the linked list from the pointer array acc. to hash function
    node *cursor = table[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char first_word = word[0];
    int index = toupper(first_word) - ASCII;

    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Opens the file for reading
    FILE *inputr = fopen(dictionary, "r");

    if (inputr == NULL)
    {
        printf("Unable to open dictionary\n");
        return false;
    }

    char dictionary_word[LENGTH + 1];

    //Scans the dictionary word by word until it reaches End Of File
    while (fscanf(inputr, "%s", dictionary_word) != EOF)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            printf("Unable to allocate memory for loading word");
            return false;
        }

        strcpy(tmp -> word, dictionary_word);
        tmp -> next = NULL;

        int index = hash(tmp -> word);

        add(index, tmp);

        number_of_words++;
    }

    //Close the file
    fclose(inputr);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return number_of_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor -> next;
            free(cursor);
            cursor = tmp;
        }
    }
    return true;
}

//adds node to the specified index of our Hash Table
void add(int index, node *n)
{
    node *head = table[index];

    if (head == NULL)
    {
        table[index] = n;
    }
    else
    {
        node *tmp = head;
        table[index] = n;
        table[index] -> next = tmp;
    }
}
