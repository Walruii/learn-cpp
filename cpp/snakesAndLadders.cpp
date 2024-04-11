#include <iostream>
#include <string>
#include <vector>

class Player {
private:
  std::string name;
  int posOnBoard;
  char symbol;

public:
  Player(std::string name, char symbol);
  std::string getName();
  int getPosOnBoard();
  char getSymbol();
};
Player::Player(std::string name, char symbol)
    : name(name), posOnBoard(0), symbol(symbol) {}
std::string Player::getName() { return name; }
int Player::getPosOnBoard() { return posOnBoard; }
char Player::getSymbol() { return symbol; }

class snakesAndLadders {
private:
  std::vector<std::vector<char>> board;
  Player *P1;
  Player *P2;

public:
  snakesAndLadders();
  void create_board();
  void print_board();
};

snakesAndLadders::snakesAndLadders() : board(100, std::vector<char>(3)) {
  std::string name1;
  std::string name2;
  char symbol;

  std::cout << "Enter Player 1 name" << std::endl;
  std::cin >> name1;
  std::cout << "Enter Player 1 Symbol (for ex: i, o, x...)" << std::endl;
  std::cin >> symbol;
  Player p1(name1, symbol);
  P1 = &p1;

  std::cout << "Enter Player 2 name" << std::endl;
  std::cin >> name2;
  std::cout << "Enter Player 2 Symbol (for ex: i, o, x...)" << std::endl;
  std::cin >> symbol;
  Player p2(name2, symbol);
  P2 = &p2;

  create_board();
}

void snakesAndLadders::create_board() {
  for (int i = 0; i < 100; i++) {
    int temp = i + 1;
    int j = 2;
    while (temp != 0) {
      board[i][j] = char(temp % 10 + 48);
      temp /= 10;
      j--;
    }
    if (j != -1) {
      for (; j >= 0; j--) {
        board[i][j] = ' ';
      }
    }
  }
}

void snakesAndLadders::print_board() {
  bool flag = true;
  int numbers = 100;

  int posOfPlayerOne = P1->getPosOnBoard();
  int posOfPlayerTwo = P2->getPosOnBoard();
  std::cout << posOfPlayerOne << " " << posOfPlayerTwo;

  std::cout << std::endl << "Player 1:" << P1->getName() << std::endl;
  std::cout << "Player 2:" << P2->getName() << std::endl;
  std::cout << std::endl
            << "-------------------------------------------------------------"
            << std::endl;
  while (numbers != 0) {
    int num = numbers;
    if (flag == false) {
      std::cout << "|";
      for (int i = num - 10; i < num; i++) {
        std::cout << ((posOfPlayerOne == i) ? (P1->getSymbol()) : (' '))
                  << board[i][0] << board[i][1] << board[i][2]
                  << ((posOfPlayerTwo == i) ? (P2->getSymbol()) : (' '));
        std::cout << "|";
        numbers--;
      }
    } else {
      std::cout << "|";
      for (int i = num - 1; i > num - 11; i--) {
        std::cout << ((posOfPlayerOne == i) ? (P1->getSymbol()) : (' '))
                  << board[i][0] << board[i][1] << board[i][2]
                  << ((posOfPlayerTwo == i) ? (P2->getSymbol()) : (' '));
        std::cout << "|";
        numbers--;
      }
    }
    if (numbers % 10 == 0) {
      std::cout
          << std::endl
          << "-------------------------------------------------------------"
          << std::endl;
      flag = !flag;
    }
  }
}

int main() {
  snakesAndLadders g1;
  g1.print_board();
  return 0;
}
