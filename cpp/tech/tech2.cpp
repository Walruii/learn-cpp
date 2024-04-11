#include <iostream>
using namespace std;

class myexception : public exception {
  virtual const char* what() const throw() {
    return "My exception";
  }
} ex;

int main () {
  try {
    throw ex;
  } catch (exception& LFC) {
    cout << LFC.what() << endl;
  }
}
