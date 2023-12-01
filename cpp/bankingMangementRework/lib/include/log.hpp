#pragma once
#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
using namespace std;

class transactionLog {
  int id;
  double amount;
  int userId;
  int mode; // 1 for credit , 0 for debit

public:
  transactionLog(int userId, double amount, int id, int mode);
  int getId() const;
  double getAmount() const;
  int getUserId() const;
  int getMode() const;
  friend std::ostream &operator<<(std::ostream &os, const transactionLog &log);
  friend std::istream &operator>>(std::istream &is, transactionLog &log);
};

#endif // LOG_HPP
