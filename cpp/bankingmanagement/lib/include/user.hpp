#pragma once
#include <iostream>
using namespace std;

class user {
  string name;
  int userId;
  double balance;
  int pin;

public:
  user(string name, int userId, int pin);
  void creditBalance(double amount);
  int debitBalance(double amount);
  int getPin() const;
  string getName() const;
  int getUserId() const;
  double getBalance() const;
  void showBalance() const;
  void setName(string name);
  bool comparePin(int pin) const;
  friend std::ostream &operator<<(std::ostream &os, const user &user);
  friend std::istream &operator>>(std::istream &is, user &user);
};
