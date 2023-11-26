#pragma once
#include "log.hpp"
#include "user.hpp"
#include "bank.hpp"
#include <iostream>

using namespace std;

class gui {
  bank hdfc;
  bool loginInStatus;
  int loginedUser;
  public:
  gui();
  void mainMenu();
  void logedInMenu();
  void loginUser();
  void createUser();
  void listUsers();
  void logoutUser();
  void withdraw();
  void deposit();
};
