#pragma once
#include <iostream>
using namespace std;

class transactionLog {
  int id;
  double amount;
  int userId;
  int mode; // 1 for credit , 0 for debit

public:
  transactionLog(int userId, double amount, int id, int mode);
  int getId();
  double getAmount();
  int getUserId();
  int getMode();
};
