#include <iostream>
using namespace std;

int hcf(int n1, int n2) {
  int min = n1 < n2 ? n1 : n2;
  for (int i = min; i >= 1; i--) {
    if (n1 % i == 0 && n2 % i == 0) {
      return i;
    }
  }
  return 1;
}

int main() {
  int n1, n2;
  cout << "Enter two numbers ";
  cin >> n1 >> n2;
  cout << hcf(n1, n2) << endl;
}
