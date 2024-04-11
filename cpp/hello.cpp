#include <iostream>

using namespace std;

int add(int& x, int & y) {
  return x+y;
}


int main() {
  int x = 5;
  int y = 10;
  int sum = add(x, y); // int sum = 15;
return 0;
}
