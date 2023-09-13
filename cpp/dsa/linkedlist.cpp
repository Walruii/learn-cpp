#include <iostream>

typedef struct node 
{
    int number;
    struct node *next;
} node;


int main()
{
    node *list = NULL;

    // Adding a number to the list
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return -1;
    }
    n->number = 1;
    n->next = NULL;

    // Update list to point to nodes
    list = n;

    // Add a number 
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;

    list->next = n;
    // Add another number 
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    list->next->next = n;
    
    for (node *tmp = NULL; tmp->next != NULL; tmp = tmp->next)
    {
        printf("%d", tmp->number);
    }
    return 0;

    while(list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    /* for (node *tmp = list->next; list != NULL; list = tmp) */
    /* { */
    /*     free(list); */
    /* } */
}
