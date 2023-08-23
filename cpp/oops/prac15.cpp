#include <iostream>
using namespace std;

class MyClass {
private:
  int myMember;

public:
  void setData() {
    cout << "Enter a value";
    cin >> myMember;
  }

  void getData() {
    cout << "Enter value is " << myMember << endl;
  }
};

int main() {
  MyClass obj1;
  obj1.setData();
  obj1.getData();
  
  return 0;
}
