#include <iostream>
using namespace std;

class Print {
  int x;

public:
  Print(int _x) : x(_x) {}

  void display() { cout <<  ++this.x << " "; }
};
int main() {
  Print i(1);
  i.display();
  return 0;
}
