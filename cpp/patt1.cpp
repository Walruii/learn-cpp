#include <iostream>
using namespace std;

#define ROWS 14

int main() {

  for (int i = ROWS; i > 0; i--) {
    for (int j = i; j > 0; j--) {
      if (i == ROWS || i == 1 || j == 1 || j == i)
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}
