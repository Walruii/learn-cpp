/* TIC TAC TOE

1. UI (user interface)
2. TTT LOGIC
  a. user input
  b. check winner
    if true -> end and print winner
    else if all boxes filled then draw <- end
  c. else  user2 input
  d. check winner
    if true -> end and print winner
    else if all boxes filled then draw <- end
2. Print Winner or draw

*/

#include <iostream>
using namespace std;

class TTT {
private:
  char winner = ' ';
  char player1 = 'X';
  char player2 = 'O';
  char board[3][3];
  int counter = 0;

public:
  TTT() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = ' ';
      }
    }

    while (winner == ' ') {
      print_board();
      player_turn(player1);
      counter++;
      winner = check_winner();
      if (counter == 9 || winner != ' ') {
        break;
      }
      print_board();
      player_turn(player2);
      counter++;
      winner = check_winner();
      if (counter == 9 || winner != ' ') {
        break;
      }
    }

    print_board();
    if (winner == ' ') {
      cout << "DRAW" << endl;
    } else if (winner == 'X') {
      cout << "X WON" << endl;
    } else if (winner == 'O') {
      cout << "O WON" << endl;
    }
  }

  void print_board() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]
         << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]
         << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]
         << endl;
  }

  void player_turn(char player) {

    int row;
    int col;

    while (true) {
      cout << "Enter the row" << endl;
      cin >> row;
      cout << "Enter the col" << endl;
      cin >> col;
      row--;
      col--;
      if (check_position(row, col)) {
        board[row][col] = player;
        break;
      }
      cout << "ERROR TRY AGAIN" << endl;
    }
  }

  bool check_position(int row, int col) {
    if (row > 2 || col > 2) {
      return false;
    }
    if (board[row][col] == ' ') {
      return true;
    } else {
      return false;
    }
  }

  char check_winner() {

    // horizontal
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][0] == board[0][2] &&
          board[i][0] != ' ') {
        return board[i][0];
      }
    }

    // vertical
    for (int i = 0; i < 3; i++) {
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i] &&
          board[0][i] != ' ') {
        return board[0][i];
      }
    }

    // diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] &&
        board[0][0] != ' ') {
      return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] &&
        board[0][2] != ' ') {
      return board[0][2];
    }

    return ' ';
  }
};

void start_game();
void print_board(char board[3][3]);
void player_turn(char player, char board[3][3]);
bool check_position(int row, int col, char board[3][3]);
char check_winner(char board[3][3]);

int main() {

  bool flag = true;
  int options;

  while (flag) {
    cout << "Welcome to TTT" << endl;
    cout << "1. Start Game" << endl;
    cout << "0. EXIT" << endl;
    cin >> options;
    switch (options) {
    case 1: {
      TTT tic;
      break;
    }

    case 0:
      flag = false;
      break;
    default:
      break;
    }
  }
}

void start_game() {

  char winner = ' ';
  int counter = 0;
  char board[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  while (winner == ' ') {
    print_board(board);
    player_turn('X', board);
    counter++;
    winner = check_winner(board);
    if (counter == 9 || winner != ' ') {
      break;
    }
    print_board(board);
    player_turn('O', board);
    counter++;
    winner = check_winner(board);
    if (counter == 9 || winner != ' ') {
      break;
    }
  }

  print_board(board);
  if (winner == ' ') {
    cout << "DRAW" << endl;
  } else if (winner == 'X') {
    cout << "X WON" << endl;
  } else if (winner == 'O') {
    cout << "O WON" << endl;
  }
}

void print_board(char board[3][3]) {
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]
       << endl;
  cout << "---|---|---" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]
       << endl;
  cout << "---|---|---" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]
       << endl;
}

void player_turn(char player, char board[3][3]) {

  int row;
  int col;

  while (true) {
    cout << "Enter the row" << endl;
    cin >> row;
    cout << "Enter the col" << endl;
    cin >> col;
    row--;
    col--;
    if (check_position(row, col, board)) {
      board[row][col] = player;
      break;
    }
    cout << "ERROR TRY AGAIN" << endl;
  }
}

bool check_position(int row, int col, char board[3][3]) {
  if (row > 2 || col > 2) {
    return false;
  }
  if (board[row][col] == ' ') {
    return true;
  } else {
    return false;
  }
}

char check_winner(char board[3][3]) {

  // horizontal
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[0][2] &&
        board[i][0] != ' ') {
      return board[i][0];
    }
  }

  // vertical
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] &&
        board[0][i] != ' ') {
      return board[0][i];
    }
  }

  // diagonal
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] &&
      board[0][0] != ' ') {
    return board[0][0];
  }
  if (board[0][2] == board[1][1] && board[0][2] == board[2][0] &&
      board[0][2] != ' ') {
    return board[0][2];
  }

  return ' ';
}
