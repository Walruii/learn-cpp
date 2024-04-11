#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int rno, fee;
  char name[50];
  ifstream fin("students.txt");
  fin >> rno >> name >> fee;
  fin.close();
  cout << endl << rno << "\t" << name << "\t" << fee << endl;
  return 0;
}
