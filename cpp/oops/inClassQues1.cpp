#include <iostream>
using namespace std;

class A {
public:
  A() { cout << "A" << endl; }
  ~A() { cout << "A DESTROYED" << endl; }
};

class C : virtual public A {
public:
  C() { cout << "C" << endl; }
  ~C() { cout << "C DESTROYED" << endl; }
};

class B : virtual public A, public C {
public:
  B() { cout << "B" << endl; }
  ~B() { cout << "B DESTROYED" << endl; }
};

class D : public A {
public:
  D() { cout << "D" << endl; }
  ~D() { cout << "D DESTROYED" << endl; }
};

class E : public B {
public:
  E() { cout << "E" << endl; }
  ~E() { cout << "E DESTROYED" << endl; }
};

class F : public B {
public:
  F() { cout << "F" << endl; }
  ~F() { cout << "F DESTROYED" << endl; }
};

class H : virtual public C {
public:
  H() { cout << "H" << endl; }
  ~H() { cout << "H DESTROYED" << endl; }
};

class G : virtual public C, public H {
public:
  G() { cout << "G" << endl; }
  ~G() { cout << "G DESTROYED" << endl; }
};

class M : public G {
public:
  M() { cout << "M" << endl; }
  ~M() { cout << "M DESTROYED" << endl; }
};

class O : public D {
public:
  O() { cout << "O" << endl; }
  ~O() { cout << "O DESTROYED" << endl; }
};

class P : public D {
public:
  P() { cout << "P" << endl; }
  ~P() { cout << "P DESTROYED" << endl; }
};

class I : public O {
public:
  I() { cout << "I" << endl; }
  ~I() { cout << "I DESTROYED" << endl; }
};

class J : public O {
public:
  J() { cout << "J" << endl; }
  ~J() { cout << "J DESTROYED" << endl; }
};

class K : public P {
public:
  K() { cout << "K" << endl; }
  ~K() { cout << "K DESTROYED" << endl; }
};

class L : public P {
public:
  L() { cout << "L" << endl; }
  ~L() { cout << "L DESTROYED" << endl; }
};

int main() {

  E e;
  return 0;
}
