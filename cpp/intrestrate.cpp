#include <iostream>
using namespace std;

int main() {
  int N;
  int n1 = 0;
  int n2 = 1;
  int next;
  cin >> N;
  for (int i = 0; i < N; i++) {
    if (i <= 1) {
      next = i;
    } else {
      next = n1 + n2;
      n1 = n2;
      n2 = next;
    }
    cout << next << " ";
  }
  return 0;
}
