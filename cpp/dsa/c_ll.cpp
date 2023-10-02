#include <iostream>
using namespace std;

typedef struct node
{
  int number;
  struct node *next;
} node;


int main()
{
  node *list = NULL;

  // Adding a number to the list
  node *n = new node;

  if (n == NULL)
  {
    return -1;
  }

  n->number = 1;
  n->next = NULL;

  // Update list to point to nodes
  list = n;

  // Add a number
  n = new node;
  if (n == NULL)
  {
    delete list;
    return 1;
  }

  n->number = 2;
  n->next = NULL;

  list->next = n;
  // Add another number
  n = new node;

  if (n == NULL)
  {
    delete list->next;
    delete list;
    return 1;
  }

  n->number = 3;
  n->next = NULL;

  list->next->next = n;

  for (node *tmp = list; tmp->next != NULL; tmp = tmp->next)
  {
    cout << tmp->number;
  }
  cout << endl;

  while (list != NULL)
  {
    node *tmp = list->next;
    delete list;
    list = tmp;
  }
  return 0;
}
