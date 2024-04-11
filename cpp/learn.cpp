#include <iostream>
using namespace std;

int main() {

  int x;
  float y;
  x = 5;
  y = -10;
  try {

    if (x < 0) {
      throw x;
    }

    try {
      if (y < 0) {
        throw y;
      }
    } catch (float x) {
      throw;
    }

    cout << "YAYYYY NO EXECTTOIHNDSFlkJ !!!" << x << endl;

  } catch (int x) {
    cout << x << "EHHHHHHHHHH EXECPTION@!!!!@#@!#!@#" << endl;
  } catch (float x) {
    cout << x << "EHHHHHHHHHH EXECPTIO FOR THE FLAOT ONNEEE" << endl;
  }

  return 0;
}
