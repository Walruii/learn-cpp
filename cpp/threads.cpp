#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void myFunctionOnTheTheard() {
  for (int i = 0; i <= 100; i++) {
    cout << i << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}

int main() {
  thread myThread(myFunctionOnTheTheard);
  for (int i = 0; i <= 100; i++) {
    cout << i << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
  return 0;
}
