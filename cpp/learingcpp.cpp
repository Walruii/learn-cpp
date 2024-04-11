#include <iostream>
using namespace std;

int fibo(int nthLocation) {
  if (nthLocation <= 1) {
    return nthLocation;
  }

  return fibo(nthLocation - 1) + fibo(nthLocation - 2);
}

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int nthLocationFibo = fibo(i);
    cout << nthLocationFibo << endl;
  }

  return 0;
}
