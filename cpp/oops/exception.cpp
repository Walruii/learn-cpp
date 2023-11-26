#include <iostream>
using namespace std;

/*
  int x
  > 10 success
  < 10 error
  1 = error (system hang)
  2 = (disc fail)
  3 = no internet
 */

int main() {

  int x = 11;
  float y;
  y = 5 ;

  try {
    // ALOT OF CODE
    cout << "testing 1" << endl;
    if (x < 10) {
      throw x;
    }
    cout << "testing 2" << endl;
    if (y < 10) {
      throw y;
    }
    
    cout << "SUCCESS";

  } catch (char) {

  }

  return 0;
}
