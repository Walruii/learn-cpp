#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node;

class LinkedList {
public:
  node *head;
  node *tail;

  LinkedList() : head(nullptr), tail(nullptr) {}

  int get(int index) {
    int i = index;
    node *temp = head;
    while (i > 0) {
      if (temp == nullptr) {
        return -1;
      }
      temp = temp->next;
      i--;
    }
    return temp->value;
  }

  void insertHead(int val) {
    node *tempNode = new node;
    tempNode->value = val;
    tempNode->next = head;
    tempNode->prev = nullptr;
    if (head != nullptr) {
      head->prev = tempNode;
    }
    head = tempNode;
    if (tail == nullptr) {
      tail = tempNode;
    }
  }

  void insertTail(int val) {
    node *tempNode = new node;
    tempNode->value = val;
    tempNode->next = nullptr;
    tempNode->prev = tail;
    if (tail == nullptr) {
      head = tail = tempNode;
    } else {
      tail->next = tempNode;
      tail = tempNode;
    }
  }

  bool remove(int index) {
    if (head == nullptr)
      return false; // No elements to remove

    node *temp = head;
    for (int i = 0; i < index && temp != nullptr; ++i) {
      temp = temp->next;
    }

    if (temp == nullptr)
      return false; // Index out of bounds

    if (temp == head) {
      head = head->next; // Move head forward
      if (head != nullptr) {
        head->prev = nullptr; // If new head exists, reset its prev pointer
      } else {
        tail = nullptr; // If list is now empty, reset tail as well
      }
    } else if (temp == tail) {
      tail = temp->prev;    // Move tail backward
      tail->next = nullptr; // Reset tail's next pointer
    } else {
      temp->prev->next =
          temp->next; // Bridge temp's previous node to temp's next node
      temp->next->prev =
          temp->prev; // Bridge temp's next node back to temp's previous node
    }

    delete temp;
    return true;
  }
  vector<int> getValues() {
    vector<int> vals;
    node *temp = head;
    while (temp != nullptr) {
      vals.push_back(temp->value);
      temp = temp->next;
    }
    for (int i : vals) {
      cout << i << " ";
    }
    endl(cout);
    return vals;
  }
};

/* int main() { */
/*   LinkedList a; */
/*   a.insertHead(1); */
/*   a.insertTail(2); */
/*   a.insertTail(3); */
/*   a.insertTail(4); */
/*   a.insertHead(0); */
/*   a.getValues(); */
/*   a.remove(0); */
/*   a.getValues(); */
/*   a.remove(3); */
/*   a.getValues(); */
/*   a.remove(1); */
/*   a.getValues(); */
/*   return 0; */
/* } */
