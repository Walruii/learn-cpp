#pragma once
#include "log.hpp"
#include "user.hpp"
#include <iostream>
#include <vector>

using namespace std;

class bank {
  double MoneyInBank;
  int userIdCount;
  int logIdCount;

public:
  vector<user> users;
  vector<transactionLog> logBook;
  bank();
  void showUserTransactions(int userId) const;
  void showTransactions() const;
  void creditUser(int userId, double amount);
  int debitUser(int userId, double amount);
  int createUser(string name, int pin);
  void deleteUser(int userId, int pin);
  bool comparePin(int userId, int pin) const;
  void showUserBalance(int userId) const;
  void addUserToFile(const user &u1) const;
  void removeUserFromFile(const user &u1) const;
  void addTransaction(int userId, double amount, int mode);
  void addTransactionToFile(const transactionLog &log) const;
  void updateCountToFile() const;
  user *getUser(int userId) const;
  int getUserIdCount() const;
  int getLogIdCount() const;
  void setUserIdCount(int userIdCount);
  void setLogIdCount(int logIdCount);
};
