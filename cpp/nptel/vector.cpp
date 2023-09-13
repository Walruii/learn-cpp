#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {

  /* vector<vector<int>> v = {{1, 2, 4, 5, 6}, {2, 2, 4, 6}}; */
  /* for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); ++i) { */
  /*   /1* cout << *i << " "; *1/ */
  /*   for (vector<int>::iterator j = i->begin(); j != i->end(); ++j) { */
  /*     cout << *j << " "; */
  /*   } */
  /*   cout << endl; */
  /* }; */

  /* stack<int> s; */
  /* s.push(1); */
  /* s.push(2); */
  /* s.push(3); */
  /* s.push(4); */
  /* s.push(5); */

  /* while (s.empty() != 1) { */
  /*   cout << s.top(); */
  /*   s.pop(); */
  /* } */

  /* queue<int> q; */
  /* q.push(1); */
  /* q.push(2); */
  /* q.push(3); */
  /* q.push(4); */
  /* q.push(5); */
  /* while (q.empty() != 1) { */
  /*   cout << q.front(); */
  /*   q.pop(); */
  /* } */

  int a = 5;
  int &x = a;
  int b = 1;
  int &y = b;

  cout << a << b << endl;
  swap(a, b);
  cout << a << b << endl;
  swap(x, y);
  cout << a << b << endl;
}
