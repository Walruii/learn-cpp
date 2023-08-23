#include <cinttypes>
#include <iostream>
using namespace std;

class Stack {
private:
  int arr[100];
  int size;
  int top;

public:
  Stack();
  void menu();
  void push();
  int pop();
  void print_arr();
};

Stack::Stack() {
  size = 4;
  top = 0;
  menu();
}
void Stack::menu() {
  int flag = -1;
  while (flag != 0) {
    cout << "********************" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "0. Exit" << endl;
    cout << "********************" << endl;
    cout << "Input: ";
    cin >> flag;
    switch (flag) {
    case 1:
      push();
      print_arr();
      break;
    case 2:
      pop();
      print_arr();
      break;
    case 0:
      exit(0);
      break;
    default:
      break;
    }
  }
}
void Stack::push() {
  if (top >= size) {
    cout << "The Stack is full" << endl;
  } else {
    int ele;
    cout << "Enter the element you want to add" << endl;
    cin >> ele;
    arr[top] = ele;
    top++;
  }
}
int Stack::pop() {
  if (top <= 0) {
    cout << "The Stack is empty" << endl;
    return 0;
  } else {
    top--;
    return arr[top];
  }
}
void Stack::print_arr() {
  cout << endl;
  for (int i = 0; i < top; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << top << " " << size;
  cout << endl;
}
int main() {
  Stack s1;
  return 0;
}
