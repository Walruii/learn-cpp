#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
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
  void setName(std::string nameOfPlayer);
  void setSymbol(char sym);
  void setPosOnBoard(int pos);
};

Player::Player(std::string name, char symbol)
    : name(name), posOnBoard(1), symbol(symbol) {}
std::string Player::getName() { return name; }
int Player::getPosOnBoard() { return posOnBoard; }
char Player::getSymbol() { return symbol; }
void Player::setName(std::string nameOfPlayer) { name = nameOfPlayer; }
void Player::setSymbol(char sym) { symbol = sym; }
void Player::setPosOnBoard(int pos) { posOnBoard = pos; }

class snakesAndLadders {
private:
  std::vector<std::vector<char>> board;
  std::unordered_map<int, int> snakes;
  std::unordered_map<int, int> ladders;
  Player P1;
  Player P2;

public:
  snakesAndLadders();
  void createBoard();
  void createSnakesAndLadders();
  void printBoard();
  void movePlayer(int playerNo, int move);
  int dice();
  int checkWinner();
};

snakesAndLadders::snakesAndLadders()
    : board(100, std::vector<char>(3)), P1(" ", 'X'), P2(" ", 'O') {
  std::string name;
  char symbol;
  int flag = 0;
  int mode = -1;
  std::cout << "Enter Player 1 name" << std::endl;
  std::cin >> name;
  std::cout << "Enter Player 1 Symbol (for ex: i, o, x...)" << std::endl;
  std::cin >> symbol;
  P1.setName(name);
  P1.setSymbol(symbol);

  std::cout << "Enter Player 2 name" << std::endl;
  std::cin >> name;
  std::cout << "Enter Player 2 Symbol (for ex: i, o, x...)" << std::endl;
  std::cin >> symbol;
  P2.setName(name);
  P2.setSymbol(symbol);

  std::cout << "Enter What Mode You Want to play" << std::endl;
  std::cout << "1. Random Gen Dice" << std::endl;
  std::cout << "2. Own Physical Dice" << std::endl;
  std::cin >> mode;
  createSnakesAndLadders();
  createBoard();

  while (flag == 0) {
    printBoard();
    std::cout << "Roll Dice For " << P1.getName() << std::endl;
    std::cout << "Press Enter to Continue...";
    std::cin.get();
    movePlayer(1, mode);
    flag = checkWinner();
    if (flag != 0)
      break;
    printBoard();
    std::cout << "Roll Dice For " << P2.getName() << std::endl;
    std::cout << "Press Enter to Continue...";
    std::cin.get();
    movePlayer(2, mode);
    flag = checkWinner();
  }
  printBoard();
  if (flag == 1) {
    std::cout << P1.getName() << " WINS!!";
  } else {
    std::cout << P2.getName() << " WINS!!";
  }
}

void snakesAndLadders::createBoard() {
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

void snakesAndLadders::printBoard() {
  system("clear");
  bool flag = true;
  int numbers = 100;

  int posOfPlayerOne = P1.getPosOnBoard();
  int posOfPlayerTwo = P2.getPosOnBoard();
  std::cout << std::endl
            << "Player 1: " << P1.getName() << " Pos: " << posOfPlayerOne
            << std::endl;
  std::cout << "Player 2: " << P2.getName() << " Pos: " << posOfPlayerTwo
            << std::endl;
  std::cout << std::endl
            << "-------------------------------------------------------------"
            << std::endl;
  while (numbers != 0) {
    int num = numbers;
    if (flag == false) {
      std::cout << "|";
      for (int i = num - 10; i < num; i++) {
        std::cout << "\033[31m"
                  << ((posOfPlayerOne == i + 1) ? (P1.getSymbol()) : (' '))
                  << "\033[0m" << board[i][0] << board[i][1] << board[i][2]
                  << "\033[31m"
                  << ((posOfPlayerTwo == i + 1) ? (P2.getSymbol()) : (' '))
                  << "\033[0m";
        std::cout << "|";
        numbers--;
      }
    } else {
      std::cout << "|";
      for (int i = num - 1; i > num - 11; i--) {
        std::cout << "\033[31m"
                  << ((posOfPlayerOne == i + 1) ? (P1.getSymbol()) : (' '))
                  << "\033[0m" << board[i][0] << board[i][1] << board[i][2]
                  << "\033[31m"
                  << ((posOfPlayerTwo == i + 1) ? (P2.getSymbol()) : (' '))
                  << "\033[0m";
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
void snakesAndLadders::createSnakesAndLadders() {
  // snakes
  snakes[17] = 7;
  snakes[54] = 34;
  snakes[62] = 19;
  snakes[64] = 60;
  snakes[87] = 24;
  snakes[93] = 73;
  snakes[95] = 75;
  snakes[99] = 78;
  // ladders
  ladders[4] = 14;
  ladders[9] = 31;
  ladders[20] = 38;
  ladders[28] = 84;
  ladders[40] = 59;
  ladders[63] = 81;
}

void snakesAndLadders::movePlayer(int playerNo, int mode) {
  Player *player = nullptr;
  if (playerNo == 1)
    player = &P1;
  else
    player = &P2;

  int IncPos;
  if (mode == 1)
    IncPos = dice();
  else {
    std::cout << std::endl
              << "Enter The Number You Got From Your Dice!" << std::endl;
    std::cin >> IncPos;
  }
  int playerPos = player->getPosOnBoard();
  playerPos += IncPos;
  std::cout << std::endl << "You Got a " << IncPos << std::endl;
  std::cout << "Press Enter to Continue...";
  std::cin.get();
  if (playerPos > 100) {
    std::cout << std::endl
              << "Which will make Higher Than 100. Better Luck Next Time!";
    std::cout << "Press Enter to Continue...";
    std::cin.get();
    return;
  }
  if (snakes.count(playerPos) != 0) {
    std::cout << std::endl
              << "OH NO! " << player->getName() << " Got Eated by a snake!!"
              << std::endl;
    std::cout << "From " << playerPos << " To " << snakes[playerPos]
              << std::endl;
    std::cout << "Press Enter to Continue...";
    std::cin.get();
    playerPos = snakes[playerPos];
  } else if (ladders.count(playerPos) != 0) {
    std::cout << std::endl
              << "NICE! " << player->getName() << " Found A Ladder!!"
              << std::endl;
    std::cout << "From " << playerPos << " To " << ladders[playerPos]
              << std::endl;
    std::cout << "Press Enter to Continue...";
    std::cin.get();
    playerPos = ladders[playerPos];
  }
  player->setPosOnBoard(playerPos);
  if (IncPos == 6) {
    printBoard();
    std::cout << player->getName() << " Hit a 6 And Will Get a Extra Chance";
    movePlayer(playerNo, mode);
  }
  player = nullptr;
}

int snakesAndLadders::dice() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 6);
  return distrib(gen);
}

int snakesAndLadders::checkWinner() {
  int posOfPlayerOne = P1.getPosOnBoard();
  int posOfPlayerTwo = P2.getPosOnBoard();
  if (posOfPlayerOne == 100)
    return 1;
  if (posOfPlayerTwo == 100)
    return 2;
  return 0;
}

int main() {
  snakesAndLadders g1;
  return 0;
}
