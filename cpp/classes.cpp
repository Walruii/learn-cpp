#include <iostream>
using namespace std;

class sumit {
  int x;
  int y;

public:
  sumit();
  void add();
  void sub();
  void mul();
};

sumit::sumit() {
  cout << "enter the numbers!";
  cin >> x;
  cin >> y;
}
void sumit::add() { cout << x + y << endl; }
void sumit::sub() { cout << x - y << endl; }
void sumit::mul() { cout << x * y << endl; }

int main() {
  sumit a;
  a.add();
  a.sub();
  a.mul();
  return 0;
}
