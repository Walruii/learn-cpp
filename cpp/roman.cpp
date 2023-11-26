#include <iostream>
using namespace std;

int converter(string s) {
  int i = 0;
  int sum = 0;
  while (i != s.length()) {
    switch (s[i]) {
    case 'I':
      if (s[i + 1] == 'V') {
        sum += 4;
        i += 2;
      } else if (s[i + 1] == 'X') {
        sum += 9;
        i += 2;
      } else {
        sum += 1;
        i++;
      }
      break;
    case 'V':
      sum += 50;
      i++;
      break;
    case 'X':
      if (s[i + 1] == 'L') {
        sum += 40;
        i += 2;
      } else if (s[i + 1] == 'L') {
        sum += 90;
        i += 2;
      } else {
        sum += 10;
        i++;
      }
      break;
    case 'L':
      sum += 50;
      i++;
      break;
    case 'C':
      if (s[i + 1] == 'D') {
        sum += 400;
        i += 2;
      } else if (s[i + 1] == 'M') {
        sum += 900;
        i += 2;
      } else {
        sum += 100;
        i++;
      }
      break;
    case 'D':
      sum += 500;
      i++;
      break;
    case 'M':
      sum += 1000;
      i++;
      break;
    default:
      break;
    }
  }
  return sum;
}

int main() {
  string toBeConverted = "LVIII";
  cout << converter(toBeConverted) << endl;

  return 0;
}
