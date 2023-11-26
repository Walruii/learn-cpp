#include <iostream>
using namespace std;

class Abstract {
public:
  virtual void draw() = 0;
};

class Derived1 : public Abstract {
public:
  void draw() { cout << "hello this is pookie bear speaking from 1"; }
};

class Derived2 : public Abstract {
public:
  void draw() { cout << "hello this is pookie bear speaking from 2"; }
};

int main() {

  Abstract *ptrAb;
  Derived1 ob1;
  Derived2 ob2;

  ptrAb = &ob2;
  ptrAb->draw();

  return 0;
}
