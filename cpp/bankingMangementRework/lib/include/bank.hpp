#pragma once
#ifndef BANK_HPP
#define BANK_HPP

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
  bool creditUser(int userId, double amount);
  bool debitUser(int userId, double amount);
  int createUser(string name, int pin);
  bool deleteUser(int userId);
  bool comparePin(int userId, int pin) const;
  void showUserTransactions(int userId) const;
  void showTransactions() const;
  void showUserBalance(int userId) const;
  void listUsers() const;
  bool addUserToFile(const user &u1) const;
  bool removeUserFromFile(const user &u1) const;
  bool addTransaction(int userId, double amount, int mode);
  bool addTransactionToFile(const transactionLog &log) const;
  bool updateUser(int userId) const;
  bool updateCountToFile() const;
  user *getUser(int userId) const;
  int getUserIdCount() const;
  int getLogIdCount() const;
  void setUserIdCount(int userIdCount);
  void setLogIdCount(int logIdCount);
};

#endif // BANK_HPP
