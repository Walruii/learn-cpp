#include <fstream>
#include <iostream>
using namespace std;

int main() {
  fstream myfile("myfile.txt", ios::out);
  myfile << "123456789";
  myfile.seekp(5);
  myfile << "*";
  myfile.close();
  myfile.open("myfile.txt", ios::in);
  myfile.seekg(3);
  string myline;
  while (myfile.good()) {
    getline(myfile, myline);
    cout << myline << endl;
  }
  return 0;
}
