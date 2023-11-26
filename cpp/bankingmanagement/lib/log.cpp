#include "./include/log.hpp"
#include <iostream>
using namespace std;

transactionLog::transactionLog(int userId, double amount, int id, int mode)
    : id(id), amount(amount), userId(userId), mode(mode) {}

int transactionLog::getId() { return id; }
double transactionLog::getAmount() { return amount; }
int transactionLog::getUserId() { return userId; }
int transactionLog::getMode() { return mode; }
