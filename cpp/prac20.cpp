#include <iostream>
using namespace std;

class A {
  public:
  A() {
    cout << "A" << endl;
  }
};
class B : public A {
  public:
  B() {
    cout << "B" << endl;
  }
};
class C : public A {
  public:
  C() {
    cout << "C" << endl;
  }
};
class D : public B {
  public:
  D() {
    cout << "D" << endl;
  }
};
class E : public B {
  public:
  E() {
    cout << "E" << endl;
  }
};
class F : public E {
  public:
  F() {
    cout << "F" << endl;
  }
};
class G : public B {
  public:
  G() {
    cout << "G" << endl;
  }
};
class H : public C {
  public:
  H() {
    cout << "H" << endl;
  }
};
class I : public H {
  public:
  I() {
    cout << "I" << endl;
  }
};
class J : public H {
  public:
  J() {
    cout << "J" << endl;
  }
};

int main() {
  F f;
  I i;
  J j;
  return 0;
}
