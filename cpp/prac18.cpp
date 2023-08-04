#include <iostream>
using namespace std;

class Student {
private:
  int rollNo;
  string name;

public:
  Student(int roll, string nam);
  Student(const Student& s1);
    void getName();
    void getRollNo(); 
};

Student::Student(int roll, string nam) {
  rollNo = roll;
  name = nam;
}

Student::Student(const Student& s1) {
  rollNo = s1.rollNo;
  name = s1.name;
}

/* Student::Student() { */
/*     cout << "Enter the name of the student: "; */
/*     cin >> name; */
/*     cout << "Enter the Roll No. of the student: "; */
/*     cin >> rollNo; */
/* } */

void Student::getName() { cout << "The name is " << name << endl; }

void Student::getRollNo() { cout << "The Roll No. is " << rollNo << endl; }

int main() {
  int roll = 34;
  string name = "Inder";

  Student s1(roll, name);
  Student s2(s1);
  s2.getName();
  s2.getRollNo();
  return 0;
}
