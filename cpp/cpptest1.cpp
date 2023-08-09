#include <iostream>
using namespace std;

class Student {
  int rollNo;
  string name;

public:
  // Default constructor
  Student() {
    rollNo = 0;
    name = "Default name";
  }
  // Parameter  constructor
  Student(int roll, string nam) {
    rollNo = roll;
    name = nam;
  }
  // Copy constructor
  Student(Student &s) {
    name = s.name;
    rollNo = s.rollNo;
  }
  // Showing data in the object
  void showData() {
    cout << "Name " << name << endl;
    cout << "Roll No " << rollNo << endl;
  }
  // Deconstructor
  ~Student() { cout << "Object deconstructed" << endl; }
  // passing an object
  void passingObject(Student s1) {
    name = s1.name;
    rollNo = s1.rollNo;
  }
  // return Object
  Student returnObject() {
    Student s1(3, "Return object");
    return s1;
  }
};

int main() {
  // calling default constructor
  Student s1;
  s1.showData();

  // calling parameterized constructor
  Student s2(1, "Inderpreet");
  s2.showData();

  // calling copy constructor
  Student s3(s2);
  s3.showData();

  // calling a fucntion that returns an object
  s2 = s3.returnObject();
  s3.showData();

  return 0;
}
