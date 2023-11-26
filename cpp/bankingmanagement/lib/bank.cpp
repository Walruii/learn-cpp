#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <iostream>
#include <vector>
using namespace std;

bank::bank() : MoneyInBank(0) {}
void bank::creditUser(int userId, double amount) {
  users[userId - 1].creditBalance(amount);
}

int bank::debitUser(int userId, double amount) {
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

void bank::showTransactions() {
  cout << "ID\t\t"
       << "USERID\t\t"
       << "MODE\t\t"
       << "AMOUNT" << endl;

  for (int i = 0; i < logBook.size(); i++) {
    cout << logBook[i].getId() << "\t\t" << logBook[i].getUserId() << "\t\t"
         << logBook[i].getMode() << "\t\t" << logBook[i].getAmount();
  }
}
