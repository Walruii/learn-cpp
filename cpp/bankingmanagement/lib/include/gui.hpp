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
  void listUsers();
  void logoutUser();
  void withdraw();
  void deposit();
  void bootloader();
};

#endif // GUI_HPP
