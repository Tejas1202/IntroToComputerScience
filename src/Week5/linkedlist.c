// Implements a list of numbers with linked list

#include <stdio.h>
#include <stdlib.h>

//as we can't use node inside the struct before declaring node on the last line, so we've to do
//this workaround by doing typedef struct "node" and then "struct" node *next
//struct node is kind of a formal name while node at the last line is kind of a nickname so we don't
//have to use struct node everywhere
typedef struct node //Represents a node
{
    int number;
    struct node *next; //pointer to the next node
}
node;

int main(void)
{
    //list of size 0
    node *list = NULL;

    //Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 1;
    n -> next = NULL;
    list = n;

    //Add 2 to the list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 2;
    n -> next = NULL;
    list -> next = n;

    //Add 3 to the list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 3;
    n -> next = NULL;
    list -> next -> next = n;

    //Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> number);
    }

    //Free list
    while (list != NULL)
    {
        node *tmp = list -> next;
        free(list);
        list = tmp;
    }
}