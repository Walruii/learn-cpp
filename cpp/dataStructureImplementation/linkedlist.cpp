#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
  int value;
  struct node *next;
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
    head = tempNode;
    if (tail == nullptr) {
      tail = tempNode;
    }
  }

  void insertTail(int val) {
    node *tempNode = new node;
    tempNode->value = val;
    tempNode->next = nullptr;
    if (tail == nullptr) {
      head = tail = tempNode;
    } else {
      tail->next = tempNode;
      tail = tempNode;
    }
  }

  bool remove(int index) {
    int i = index;
    node *temp = head;
    node *tempHead = head;
    while (i > 0) {
      tempHead = temp;
      temp = temp->next;
      i--;
    }
    if (temp == nullptr)
      return false;

    if (temp == head) {
      temp = head;
      head = head->next;
      delete temp;
      return true;
    }
    if (temp->next == nullptr) {
      tempHead->next = nullptr;
      tail = tempHead;
      delete temp;
      return true;
    }
    tempHead->next = tempHead->next->next;
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

int main() {
  LinkedList a;
  a.insertHead(1);
  a.insertTail(2);
  a.insertTail(3);
  a.insertTail(4);
  a.insertHead(0);
  a.getValues();
  a.remove(0);
  a.getValues();
  a.remove(3);
  a.getValues();
  a.remove(1);
  a.getValues();
}
