#include "./include/gui.hpp"
#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <iostream>
#include <vector>

gui::gui() : loginInStatus(false), loginedUser(-1), loginedName("") { mainMenu(); }

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
      listUsers();
      break;
    default:
      break;
    }
  }
}

void gui::loginUser() {
  int userId;
  int pin;
  bool success = false;
  cout << "\nLogingin User" << endl;
  cout << "USERID: ";
  cin >> userId;
  if (userId > hdfc.users.size() || userId == 0) {
    cout << "Invaild userId";
    return;
  }
  while (success == false) {
    cout << "PIN: ";
    cin >> pin;
    success = hdfc.comparePin(userId, pin);
  }

  if (success) {
    loginInStatus = true;
    loginedUser = userId;
    loginedName = hdfc.users[loginedUser - 1].getName();
    loggedInMenu();
  } else {
    cout << "Login Failed!";
  }
}

void gui::createUser() {
  string name;
  int pin;
  cout << "\nCreating User" << endl;
  cout << "NAME: ";
  getchar();
  getline(cin, name);
  cout << "PIN:";
  cin >> pin;
  int userId = hdfc.createUser(name, pin);
  cout << "Your userId is " << userId << endl;
}

void gui::listUsers() {
  for (int i = 0; i < hdfc.users.size(); i++) {
    cout << "UserName: " << hdfc.users[i].getName()
         << " UserId: " << hdfc.users[i].getUserId() + 1
         << " Pin:" << hdfc.users[i].pin << endl;
  }
}

void gui::logoutUser() {
  if (loginInStatus == false) {
    cout << "Already Logged out" << endl;
    return;
  }
  loginInStatus = false;
  loginedUser = -1;
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
  int pin;
  bool success = false;
  cout << "\nWithdraw" << endl;
  cout << "Enter Amount: ";
  cin >> amount;
  while (success == false) {
    cout << "PIN: ";
    cin >> pin;
    success = hdfc.comparePin(loginedUser, pin);
  }
  if (success) {
    hdfc.debitUser(loginedUser, amount);
    cout << "Account debited" << endl;
    hdfc.showUserBalance(loginedUser);
  } else {
    cout << "Wrong Pin" << endl;
  }
}

void gui::deposit() {
  double amount;
  int pin;
  bool success = false;
  cout << "\nDeposit" << endl;
  cout << "Enter Amount: ";
  cin >> amount;
  while (success == false) {
    cout << "PIN: ";
    cin >> pin;
    success = hdfc.comparePin(loginedUser, pin);
  }
  if (success) {
    hdfc.creditUser(loginedUser, amount);
    cout << "Account credited" << endl;
    hdfc.showUserBalance(loginedUser);
  } else {
    cout << "Wrong Pin" << endl;
  }
}
