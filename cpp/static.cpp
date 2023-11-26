#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
  static Point *point_;
  Point() {
    x = 4;
    y = 5;
  }

  Point(int a, int b = 5) : x(a), y(b) {}

public:
  ~Point() { cout << "OBJ DES" << endl; }
  static const Point &point(int x = 5, int y = 5) {
    if (!point_) {
      point_ = new Point;
    }
    return *point_;
  }
  void print() const { cout << x << y; }
};

Point *Point::point_ = 0;

int main() {
  Point::point(20).print();
  Point::point(20).print();
  return 0;
}
