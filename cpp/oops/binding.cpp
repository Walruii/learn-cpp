#include <iostream>
using namespace std;

class Base {
  public: 
    void show1() {
      cout << "early binded" << endl;
    }

    virtual void show2() {
      cout << "late binded" << endl;
    }
};

class Derived : public Base {
  public: 
    void show1() {
      cout << "early binded" << endl;
    }

    void show2() {
      cout << "late binded" << endl;
    }
};

int main () {
  Base *b;
  Derived d;
  b = &d;
  b->show1();
  b->show2();
  return 0;
}
