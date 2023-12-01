#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <iostream>
using namespace std;

class user {
  string name;
  int userId;
  double balance;
  int pin;

public:
  user(string name, int userId, int pin);
  bool creditBalance(double amount);
  bool debitBalance(double amount);
  int getPin() const;
  string getName() const;
  int getUserId() const;
  double getBalance() const;
  void setName(string name);
  bool comparePin(int pin) const;
  friend std::ostream &operator<<(std::ostream &os, const user &user);
  friend std::istream &operator>>(std::istream &is, user &user);
};

#endif // USER_HPP
