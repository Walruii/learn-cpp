#include <iostream>
using namespace std;

class Abstract {
  public:
    virtual void print() = 0;
};

class Concrete : public Abstract {
  public:
    void print() { cout << "HELLO" << endl; }
};


int main () {
  Concrete obj;
  obj.print();

  return 0;
}
