#include <iostream>
using namespace std;

class game {
private:
  int board[10][10];

public:
  game();
  void print_board();
};

game::game() {
  int num = 100;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = num;
      num--;
    }
  }
}

void game::print_board() {
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 10; j++) {
        cout << board[i][j];
        cout << "\t";
      }
    } else {
      for (int j = 9; j >= 0; j--) {
        cout << board[i][j];
        cout << "\t";
      }
    }
    cout << endl;
  }
}
int main() {
  game g1;
  g1.print_board();
  return 0;
}
