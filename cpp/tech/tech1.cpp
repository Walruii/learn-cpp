#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<int, int> mapS;
    unordered_map<int, int> mapT;
    for (char char1 : s) {
      if (mapS.count(char1)) {
        mapS[char1];
      } else {
        mapS.insert({char1, 1});
      }
    }

    for (char char2 : t) {
      if (mapT.count(char2)) {
        mapT[char2]++;
      } else {
        mapT.insert({char2, 1});
      }
    }
    if (mapS == mapT) {
      return true;
    }
    return false;
  }
};

class Test {
  static int x;
  int *ptr;
  int y;
};

int main() {
  Test t;
  cout << sizeof(t) << " ";
  cout << sizeof(Test *);
}
