#include <fstream>
#include <iostream>
using namespace std;

int main() {

  ofstream fout;
  string line;

  fout.open("sample.txt");

  while (fout) {
    getline(cin, line);

    // for exiting
    if (line == "-1")
      break;
    fout << line << endl;
  }

  fout.close();

  ifstream fin;

  fin.open("sample.txt");

  while (getline(fin, line)) {
    cout << line << endl;
  }

  return 0;
}
