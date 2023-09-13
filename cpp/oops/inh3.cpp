#include <iostream>
using namespace std;

class A {
  public:
  A(){
    cout << "A";
  }
};
class B : public A {
  public:
  B(){
    cout << "B";
  }
};
class C : public B {
  public:
  C(){
    cout << "C";
  }
};
class D : public C {
  public:
  D(){
    cout << "D";
  }
};
class E : public D {
  public:
  E(){
    cout << "E";
  }
};

int main() {
  E e;
  return 0;
}
