#include <iostream>
using namespace std;

void permute(string& a, int l, int r) {
  if (l == r) {
    cout << a << endl;
  } else {
    for (int i = l; i <= r; i++) {
      swap(a[l], a[i]);
      permute(a, l+1, r);
      swap(a[l], a[i]);
    }
  }
}

int main() {
  string str = "ABC";
  int n = str.size();
  permute(str, 0, n - 1);
  return 0;
}

/*
 ABC > i 0 l 0
 ABC > i 1 l 1 
 ABC > i 2 l 2 P!
 ACB < i 2 l 1
 ACB > i 2 l 2 P!
 ABC < i 2 l 1
 ABC < i 0 l 0
 BAC < i 1 l 0
 BAC > i 1 l 1
 BAC > i 2 l 2 P!
 BAC > i 1 l 1
 BCA > i 2 l 1 
 BCA > i 2 l 2 P!


 */
