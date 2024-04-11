#include "doublyLinkedList.cpp"
#include <iostream>

class DEQueue {
  LinkedList list;
  int size;

public:
  DEQueue() : size(0) {}
  bool pushFront(int val);
  bool pushBack(int val);
  bool popFront();
  bool popBack();
  int getFront();
  int getBack();
  void getQueue();
};
bool DEQueue::pushFront(int val) {
  list.insertHead(val);
  size++;
  return true;
}
bool DEQueue::pushBack(int val) {
  list.insertTail(val);
  size++;
  return true;
}
bool DEQueue::popFront() {
  list.remove(0);
  size--;
  return true;
}
bool DEQueue::popBack() {
  list.remove(size - 1);
  size--;
  return true;
}
int DEQueue::getFront() { return list.get(0); }
int DEQueue::getBack() { return list.get(size - 1); }
void DEQueue::getQueue() { list.getValues(); }

int main() {
  DEQueue q;
  q.pushFront(2);
  q.pushFront(1);
  q.pushBack(3);
  q.pushBack(4);
  q.pushBack(5);
  q.getQueue();
  q.popBack();
  q.getQueue();
  q.popFront();
  q.getQueue();
  q.popFront();
  q.getQueue();
  q.popFront();
  q.getQueue();
  return 0;
}
