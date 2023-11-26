#include <iostream>
using namespace std;

class A {
  public:
     void draw () {
      cout << "HELLO A";
    }
};
class B: public A {
  public:
     void draw () {
      cout << "HELLO B";
    }
};
class C : public B {
  public:
     virtual void draw () {
      cout << "HELLO C";
    }
};
class D : public C {
  public:
     void draw () {
      cout << "HELLO D";
    }
};

int main () {

  C * ptrC;
  B b;
  C c;
  D d;

  ptrC = &d;

  ptrC->draw();




  return 0;
}
