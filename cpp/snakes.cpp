#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#define HEIGHT 10
#define WIDTH 30

class game {
private:
  char screen[HEIGHT][WIDTH];

public:
  game();
  void initialise_screen();
  void print_screen();
  void snake();
  void food();
};

game::game() {
  initialise_screen();
  food();
  print_screen();
}

void game::initialise_screen() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      screen[i][j] = ' ';
    }
  }
}

void game::print_screen() {
  for (int i = 0; i < HEIGHT; i++) {
    if (i == 0) {
      for (int j = 0; j < WIDTH + 2; j++)
        cout << "-";
      cout << endl;
    }
    for (int j = 0; j < WIDTH; j++) {
      if (j == 0)
        cout << "|";
      cout << screen[i][j];
    }
    cout << "|" << endl;
  }
  for (int j = 0; j < WIDTH + 2; j++)
    cout << "-";
  cout << endl;
}

void game::food() {
  srand(time(0));
  int row = rand() % HEIGHT;
  int col = rand() % WIDTH;
  screen[row][col] = 'x';
}

int main() {
  game g1;
  return 0;
}
