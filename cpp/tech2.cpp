#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string str1 = "HELLO"; // EHLLO
  string str2 = "ELLOH";
  if (str1.length() == str2.length()) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 == str2) {
      cout << "is Anagram";
    } else {
      cout << "Not by words!";
    }
  } else {
    cout << "Not by size!";
  }
  return 0;
}
