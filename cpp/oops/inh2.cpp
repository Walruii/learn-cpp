#include <iostream>
using namespace std;

class A {
  public:
  A(){
    cout << "A";
  }
};
class B {
  public:
  B(){
    cout << "B";
  }
};
class C : public A, public B {
  public:
  C(){
    cout << "C";
  }
};

int main() {
  C c;
  return 0;
}
