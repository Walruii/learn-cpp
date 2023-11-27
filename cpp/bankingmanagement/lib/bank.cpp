#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <iostream>
#include <vector>
using namespace std;

bank::bank() : MoneyInBank(0) {}
void bank::creditUser(int userId, double amount) {
  addTransaction(userId, amount, 1);
  users[userId - 1].creditBalance(amount);
}

int bank::debitUser(int userId, double amount) {
  addTransaction(userId, amount, 0);
  return users[userId - 1].debitBalance(amount);
}

int bank::createUser(string name, int pin) {
  int userId = users.size();
  user user1(name, userId, pin);
  users.push_back(user1);
  cout << "User Created!" << endl;
  return userId + 1;
}

void bank::deleteUser(int userId, int pin) {
  if (users[userId - 1].comparePin(pin)) {
    users.erase(users.begin() + userId - 1);
    cout << "User deleted!" << endl;
  }
};

void bank::addTransaction(int userId, double amount, int mode) {
  int id = logBook.size() + 1;
  transactionLog log(userId, amount, id, mode);
  logBook.push_back(log);
}

void bank::showUserTransactions(int userId) {
  cout << "ID\t\t"
       << "USERID\t\t"
       << "MODE\t\t"
       << "AMOUNT" << endl;

  for (int i = 0; i < logBook.size(); i++) {
    if (logBook[i].getUserId() == userId) {
      string mode = (logBook[i].getMode()) ? "Credit" : "Debit";
      cout << logBook[i].getId() << "\t\t" << logBook[i].getUserId() << "\t\t"
           << mode << "\t\t" << logBook[i].getAmount() << endl;
    }
  }
}

void bank::showTransactions() {
  cout << "ID\t\t"
       << "USERID\t\t"
       << "MODE\t\t"
       << "AMOUNT" << endl;

  for (int i = 0; i < logBook.size(); i++) {
    string mode = (logBook[i].getMode()) ? "Credit" : "Debit";
    cout << logBook[i].getId() << "\t\t" << logBook[i].getUserId() << "\t\t"
         << mode << "\t\t" << logBook[i].getAmount() << endl;
  }
}

bool bank::comparePin(int userId, int pin) {
  return users[userId - 1].comparePin(pin);
}

void bank::showUserBalance(int userId) { users[userId - 1].showBalance(); }
