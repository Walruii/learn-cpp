#include <iostream>
using namespace std;

class Sum {
  int a;
  int b;
  int sum;

public:
  Sum() {
    cout << "Enter first number ";
    cin >> a;
    cout << "Enter second number ";
    cin >> b;
    sum = 0;
  }
  friend void getsum(Sum &s);
  friend void getsum(Sum &s, int a);
};

void getsum(Sum &s) {
  s.sum = s.a + s.b;
  cout << s.sum << endl;
}

void getsum(int a , int b) {
  cout << a + b << endl;
}
void getsum(Sum &s, int a) {
  s.sum += a;
  cout << s.sum << endl;
}

int main() {
  Sum m;
  getsum(m);

  int a;
  cout << "What do you want to add";
  cin >> a;
  getsum(m, a);
  getsum(a, 5);
  return 0;
}
