#pragma once
#include "log.hpp"
#include "user.hpp"
#include <iostream>
#include <vector>

using namespace std;

class bank {
  double MoneyInBank;
  vector<transactionLog> logBook;

public:
  vector<user> users;
  bank();
  void addTransaction(int userId, double amount, int mode);
  void showTransactions();
  void creditUser(int userId, double amount);
  int debitUser(int userId, double amount);
  int createUser(string name, int pin);
  void deleteUser(int userId, int pin);
};
