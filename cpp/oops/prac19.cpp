#include <iostream>
using namespace std;

class point {
  public:
    int x, y;

    point() : x(6), y(5) {
    }
    point(int a, int b) : x(a), y(b) {  }
    point add(point &a) {
      point c;
      c.x = x + a.x;
      c.y = y + a.y;
      return c;
    }
    point operator+(point &a) {
      point c;
      c.x = x + a.x;
      c.y = y + a.y;
      return c;
    } 
}; 

int main() {
  point a(2, 3);
  point b(3, 4);
  b = b.add(a);
  b = b + a;
  cout << b.x << b.y;
  return 0;
}

