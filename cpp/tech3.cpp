#include <iostream>
using namespace std;

class demo1 {};
class demo2 : public demo1 {};

int main() {
  try {
    throw 10;
  } catch (...) {
    cout << "ss";
  } catch (int param) {
    cout << param;
  }
}
