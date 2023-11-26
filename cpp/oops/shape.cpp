#include <iostream>
using namespace std;

class shape {

  public:

  virtual void draw () {
    cout << "drawing a shape" << endl;
  }

  void show() {
    cout << "showing a shape" << endl;
  }
  
};

class circle : public shape {
  
  public:

  void draw() {
    cout << "drawing a circle" << endl;
  }
  
  void show() {
    cout << "showing a circle" << endl;
  }

};

class square : public shape {
  
  public:

  void draw() {
    cout << "drawing a square" << endl;
  }
  
  void show() {
    cout << "showing a square" << endl;
  }

};


int main () {

  shape * ptrShape;

  circle cl1;
  square sh1;

  ptrShape = &cl1;
  ptrShape = &sh1;

  ptrShape->draw();
  ptrShape->show();


  return 0;
}
