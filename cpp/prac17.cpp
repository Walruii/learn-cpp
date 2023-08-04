#include <iostream>
using namespace std;

class Student {
private:
  int rollNo;
  string name;

public:
  Student() {
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the Roll No. of the student: ";
    cin >> rollNo;
  }
  void getName() { cout << "The name is " << name << endl; }
  void getRollNo() { cout << "The Roll No. is " << rollNo << endl; }
};

int main() {
  Student s1;
  s1.getName();
  s1.getRollNo();
  return 0;
}
