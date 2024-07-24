#include "./include/gui.hpp"
#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

gui::gui() : loginInStatus(false), loginedUser(-1), loginedName("") {
  if (!bootloader()) {
    cout << "Didnt Load!" << endl;
  }
  mainMenu();
}

void gui::mainMenu() {
  int flag = 1;
  system("clear");
  while (flag != 0) {
    cout << "\n********************" << endl;
    cout << "Welcome to HDFC BANK." << endl;
    cout << "1. Login" << endl;
    cout << "2. Logout" << endl;
    cout << "3. Create User" << endl;
    cout << "4. Banklog" << endl;
    cout << "5. List users" << endl;
    cout << "6. Delete user" << endl;
    cout << "0. Exit" << endl;
    cout << "********************" << endl;
    cout << "type: ";
    cin >> flag;
    switch (flag) {
    case 0:
      break;
    case 1:
      loginUser();
      break;
    case 2:
      logoutUser();
      break;
    case 3:
      createUser();
      break;
    case 4:
      hdfc.showTransactions();
      break;
    case 5:
      hdfc.listUsers();
      break;
    case 6:
      deleteUser();
      break;
    default:
      break;
    }
  }
}

bool gui::checkPin(int userId) const {
  int pin;
  int tries = 1;
  bool success = false;
  while (success == false && tries != 4) {
    cout << "PIN: ";
    cin >> pin;
    success = hdfc.comparePin(userId, pin);
    tries++;
  }
  if (success) {
    return true;
  }
  return false;
}

void gui::loginUser() {
  int userId;
  cout << "\nLogingin User" << endl;
  cout << "USERID: ";
  cin >> userId;
  if (userId > hdfc.getUserIdCount() || userId == 0) {
    cout << "Invaild userId";
    return;
  }
  if (checkPin(userId)) {
    loginInStatus = true;
    loginedUser = userId;
    loginedName = hdfc.getUser(userId)->getName();
    loggedInMenu();
  } else {
    cout << "Login Failed!";
  }
}

void gui::createUser() {
  string name;
  int pin;
  cout << "\nCreating User" << endl;
  cout << "NAME(No space!): ";
  cin >> name;
  cout << "PIN:";
  cin >> pin;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  int userId = hdfc.createUser(name, pin);
  cout << "Your userId is " << userId << endl;
}

void gui::deleteUser() {
  int userId;
  bool success = false;
  cout << "\nDeleting User" << endl;
  cout << "USERID: ";
  cin >> userId;
  if (userId > hdfc.getUserIdCount() || userId == 0) {
    cout << "Invaild userId";
    return;
  }
  if (checkPin(userId)) {
    hdfc.deleteUser(userId);
  } else {
    cout << "Auth Failed!";
  }
}
void gui::logoutUser() {
  if (loginInStatus == false) {
    cout << "Already Logged out" << endl;
  } else {
    loginInStatus = false;
    loginedUser = -1;
    cout << "Logged out" << endl;
  }
}

void gui::loggedInMenu() {
  int flag = 1;
  system("clear");
  while (flag != 0) {
    cout << "\n********************" << endl;
    cout << "Welcome " << loginedName << "." << endl;
    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Show Balance" << endl;
    cout << "4. Show Transactions" << endl;
    cout << "0. Exit" << endl;
    cout << "********************" << endl;
    cout << "type: ";
    cin >> flag;
    switch (flag) {
    case 0:
      logoutUser();
      break;
    case 1:
      withdraw();
      break;
    case 2:
      deposit();
      break;
    case 3:
      hdfc.showUserBalance(loginedUser);
      break;
    case 4:
      hdfc.showTransactions();
      break;
    default:
      break;
    }
  }
}

void gui::withdraw() {
  double amount;
  cout << "\nWithdraw" << endl;
  cout << "Enter Amount: ";
  cin >> amount;
  if (checkPin(loginedUser)) {
    bool debitSuccess = hdfc.debitUser(loginedUser, amount);
    if (debitSuccess == false) {
      cout << "Transaction failed!";
    } else {
      cout << "Account debited" << endl;
      hdfc.showUserBalance(loginedUser);
    }
  } else {
    cout << "Wrong Pin" << endl;
  }
}

void gui::deposit() {
  double amount;
  cout << "\nDeposit" << endl;
  cout << "Enter Amount: ";
  cin >> amount;
  if (checkPin(loginedUser)) {
    hdfc.creditUser(loginedUser, amount);
    cout << "Account credited" << endl;
    hdfc.showUserBalance(loginedUser);
  } else {
    cout << "Wrong Pin" << endl;
  }
}

bool gui::bootloader() {
  ifstream inputFile("users.txt");
  int userIdCount = 1;
  int logIdCount = 1;

  if (!inputFile.is_open()) {
    cerr << "Error opening file users!" << endl;
    return false;
  }

  // File operations go here

  user u1("test", -1, 0);

  while (inputFile >> u1) {
    hdfc.users.push_back(u1);
  }

  inputFile.close(); // Always close the file when done
  inputFile.open("bankInfo.txt");

  if (!inputFile.is_open()) {
    cerr << "Error opening file bankInfo!" << endl;
    return false;
  }
  inputFile >> userIdCount;
  inputFile >> logIdCount;
  hdfc.setUserIdCount(userIdCount);
  hdfc.setLogIdCount(logIdCount);

  inputFile.close(); // Always close the file when done

  inputFile.open("log.txt");
  if (!inputFile.is_open()) {
    cerr << "Error opening file log!" << endl;
    return false;
  }

  // File operations go here

  transactionLog log(-1, -1, -1, -1);

  while (inputFile >> log) {
    hdfc.logBook.push_back(log);
  }

  inputFile.close(); // Always close the file when done
  return true;
}
