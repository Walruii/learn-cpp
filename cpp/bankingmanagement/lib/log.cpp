#include "./include/log.hpp"
#include <iostream>
using namespace std;

transactionLog::transactionLog(int userId, double amount, int id, int mode)
    : id(id), amount(amount), userId(userId), mode(mode) {}

int transactionLog::getId() const { return id; }
double transactionLog::getAmount() const { return amount; }
int transactionLog::getUserId() const { return userId; }
int transactionLog::getMode() const { return mode; }

ostream &operator<<(ostream &os, const transactionLog &log) {
  os << log.id << " " << log.userId << " " << log.mode << " " << log.amount;
  return os;
}

// Define the >> operator for reading from a file
istream &operator>>(istream &is, transactionLog &log) {
  is >> log.id >> log.userId >> log.mode >> log.amount;
  return is;
}
