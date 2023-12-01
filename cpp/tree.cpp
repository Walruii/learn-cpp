#include <iostream>

class list {
public:
  typedef struct node {
    int value;
    struct node *left;
    struct node *right;
  } node;
};

int main() { 
  list l1;
  list::node nod1;
  return 0; 
}
