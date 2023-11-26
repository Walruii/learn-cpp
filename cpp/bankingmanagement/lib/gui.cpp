#include "./include/gui.hpp"
#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <iostream>
#include <vector>

gui::gui() : loginInStatus(false), loginedUser(-1) { mainMenu(); }

void gui::mainMenu() {
  int flag = 1;
  system("clear");
  while (flag != 0) {
    cout << "\n********************" << endl;
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
    success = hdfc.users[userId - 1].comparePin(pin);
  }

  if (success) {
    loginInStatus = true;
    loginedUser = userId;
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
  cout << "size: " << hdfc.users.size();
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
    cout << "Already Loged out" << endl;
    return;
  }
  loginInStatus = false;
  loginedUser = -1;
};

void gui::logedInMenu() {
  int flag = 1;
  system("clear");
  while (flag != 0) {
    cout << "\n********************" << endl;
    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Show Transactions" << endl;
    cout << "0. Exit" << endl;
    cout << "********************" << endl;
    cout << "type: ";
    cin >> flag;
    switch (flag) {
    case 0:
      break;
    case 1:
      withdraw();
      break;
    case 2:
      deposit();
      break;
    case 3:
      break;
    default:
      break;
    }
  }
}

void gui::withdraw() {}

void gui::deposit() {}
