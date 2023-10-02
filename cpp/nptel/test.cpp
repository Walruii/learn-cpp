#include <iostream>

#ifndef X
#define X 5
#endif

#ifndef Y
#define Y 5
#endif

using namespace std;

class point {
public:
  int x, y;
  point() {
    x = X;
    y = Y;
  }
  point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  point operator+(point &a) {
    point b;
    b.x = x + a.x;
    b.y = y + a.y;
    return b;
  }
  point operator-(point &a) {
    point b;
    b.x = x - a.x;
    b.y = y - a.y;
    return b;
  }
  point operator*(point &a) {
    point b;
    b.x = x * a.x;
    b.y = y * a.y;
    return b;
  }
};

int main() {
  point a;
  point b(2, 5);
  point c = a + b;
  cout << c.x << " " << c.y << endl;;
  c = c - a;
  cout << c.x << " " << c.y << endl;;
  return 0;
}
