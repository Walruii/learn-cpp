#pragma once
#ifndef GUI_HPP
#define GUI_HPP

#include "bank.hpp"
#include "log.hpp"
#include "user.hpp"
#include <iostream>

using namespace std;

class gui {
  bank hdfc;
  bool loginInStatus;
  int loginedUser;
  string loginedName;

public:
  gui();
  void mainMenu();
  void loggedInMenu();
  void loginUser();
  void createUser();
  void deleteUser();
  void logoutUser();
  void withdraw();
  void deposit();
  bool bootloader();
  bool checkPin(int pin) const;
};

#endif // GUI_HPP
