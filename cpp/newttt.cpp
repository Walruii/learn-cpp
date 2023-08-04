#include <cstdlib>
#include <cwchar>
#include <iostream>
#include <time.h>
using namespace std;

class ttt {
private:
  char board[3][3];
  char player;
  char player2;
  int empty_spaces;

public:
  ttt();
  void initialise_board();
  void print_board();
  void player1_move();
  void player2_move();
  void computer_move();
  bool check_empty(int row, int col);
  char check_winner();
  void gamePvP();
  void gamePvC();
};

ttt::ttt() {
  player = 'X';
  player2 = 'O';
  int flag = -1;
  while (flag != 0) {
    initialise_board();
    cout << "*******************" << endl;
    cout << "1. PvP" << endl;
    cout << "2. PvC" << endl;
    cout << "0. Exit" << endl;
    cout << "*******************" << endl;
    cout << "Input: ";
    cin >> flag;
    switch (flag) {
    case 1:
      gamePvP();
      break;
    case 2:
      gamePvC();
      break;
    case 0:
      exit(0);
      break;
    default:
      break;
    }
  }
}

void ttt::initialise_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
  empty_spaces = 9;
}

void ttt::print_board() {
  cout << endl;
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]
       << " " << endl;
  cout << "-----------" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]
       << " " << endl;
  cout << "-----------" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]
       << " " << endl;
  cout << endl;
}

bool ttt::check_empty(int row, int col) {
  if (board[row][col] == ' ') {
    return true;
  } else {
    return false;
  }
}

void ttt::player1_move() {
  int row_move;
  int col_move;
  bool flag = false;
  cout << "Your move" << endl;
  do {
    cout << "row: ";
    cin >> row_move;
    row_move--;
    cout << "col: ";
    cin >> col_move;
    col_move--;
    flag = check_empty(row_move, col_move);
    if (flag == false) {
      cout << "The position is already in use" << endl;
    }
  } while (flag == false);
  cout << "Computer move" << endl;
  board[row_move][col_move] = player;
  empty_spaces--;
}

void ttt::player2_move() {
  int row_move;
  int col_move;
  bool flag = false;
  cout << "Your move" << endl;
  do {
    cout << "row: ";
    cin >> row_move;
    row_move--;
    cout << "col: ";
    cin >> col_move;
    col_move--;
    flag = check_empty(row_move, col_move);
    if (flag == false) {
      cout << "The position is already in use" << endl;
    }
  } while (flag == false);
  cout << "Computer move" << endl;
  board[row_move][col_move] = player2;
  empty_spaces--;
}

void ttt::computer_move() {
  srand(time(0));
  int row_move;
  int col_move;
  int flag = false;
  do {
    row_move = rand() % 3;
    col_move = rand() % 3;
    flag = check_empty(row_move, col_move);
  } while (flag == false);
  board[row_move][col_move] = player2;
  empty_spaces--;
}

char ttt::check_winner() {

  // Checking rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }
  }

  // Checking columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }

  // Checking diagonal
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
  }

  if (empty_spaces == 0) {
    cout << "Draw";
    exit(0);
  }
  return ' ';
};

void ttt::gamePvC() {
  print_board();
  char winner = ' ';
  while (winner == ' ') {
    player1_move();
    print_board();
    winner = check_winner();
    if (winner != ' ') {
      break;
    }
    computer_move();
    print_board();
    winner = check_winner();
    if (winner != ' ') {
      break;
    }
  }
  if (winner == player) {
    cout << "YOU WIN!" << endl;
  } else {
    cout << "YOU LOSE!" << endl;
  }
}

void ttt::gamePvP() {
  print_board();
  char winner = ' ';
  while (winner == ' ') {
    player1_move();
    print_board();
    winner = check_winner();
    if (winner != ' ') {
      break;
    }
    player2_move();
    print_board();
    winner = check_winner();
    if (winner != ' ') {
      break;
    }
  }
  if (winner == player) {
    cout << "Player 1 WINS!" << endl;
  } else {
    cout << "Player 2 WINS!" << endl;
  }
}

int main() {
  ttt t1;
  return 0;
}
