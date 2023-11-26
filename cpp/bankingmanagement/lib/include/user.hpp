#pragma once
#include <iostream>
using namespace std;

class user {
  string name;
  int userId;
  double balance;

public:
  int pin;
  user(string name, int userId, int pin);
  double const getBalance();
  void showBalance();
  void creditBalance(double amount);
  int debitBalance(double amount);
  string const getName();
  void setName(string name);
  int const getUserId();
  bool const comparePin(int pin);
};

