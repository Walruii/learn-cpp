#include <iostream>
#include <fstream>
using namespace std;

int main() {

  ifstream fin;
  ofstream fout;
  string line;

  fin.open("sample.txt");
  fout.open("text2.txt");

  if (!fin && !fout) {
    exit(0);
  }

  while (getline(fin, line)) {
    fout << line << endl;
  }
  fin.close();
  fout.close();
  fin.open("text2.txt");

  while(getline(fin, line)){
    cout << line << endl;
  }
  fin.close();

  return 0;
}
