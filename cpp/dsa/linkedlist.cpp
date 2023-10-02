#include <iostream>
using namespace std;

class LinkedList
{
  typedef struct node
  {
    int value;
    struct node *link;
  } node;
  node *start;
  node *back;

public:
  LinkedList() : start(NULL), back(NULL) {}
  /* ~LinkedList() */
  /* { */
  /*   delete back; */
  /*   while (start != NULL) */
  /*   { */
  /*     node *tmp = start->link; */
  /*     delete start; */
  /*     start = tmp; */
  /*   } */
  /* } */

  void push_back(int a)
  {
    node *newNode = new node;
    newNode->link = NULL;
    newNode->value = a;
    if (start == NULL)
    {
      start = newNode;
    }
    else
    {
      back->link = newNode;
    }
    back = newNode;
  }

  void display()
  {
    node *tmp = start;
    while (tmp != NULL)
    {
      cout << tmp->value;
      tmp = tmp->link;
    }
    cout << endl;
    delete tmp;
  }
};

int main()
{
  LinkedList l1;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  l1.push_back(6);
  l1.push_back(7);
  l1.display();

  return 0;
}
