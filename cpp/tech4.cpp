#include <iostream>
using namespace std;

int main() {
  string str = "abcxyzzdefghxijklmnxopqrstuvwxyzzzx";
  string str2 = "xyzzz";

  for (int i = 0; i < str.length(); i++) {

    if (str[i] == str2[0]) {
      int flag = -1;
      int j = 1;
      for (j = 1; j < str2.length(); j++) {
        if (str[i + j] == str2[j]) {
          flag = 1;
        } else {
          flag = -1;
          break;
        }
      }
      i = i + j - 1;

      if (flag == 1) {
        cout << "at index" << i << endl;
        break;
      }
    }
  }

  return 0;
}
