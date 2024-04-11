#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <int> stack;
  stack.push_back(1);
  stack.push_back(2);
  stack.push_back(3);
  cout << *(&stack.back());
  stack.push_back(4);
  cout << *(&stack.back());
  return 0;
}
