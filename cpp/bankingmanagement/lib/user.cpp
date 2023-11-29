#include "./include/user.hpp"
#include <fstream>
#include <iostream>
using namespace std;

user::user(string name, int userId, int pin)
    : name(name), userId(userId), pin(pin), balance(0) {}

double user::getBalance() const { return balance; }

void user::creditBalance(double amount) { balance += amount; }

int user::debitBalance(double amount) {
  balance -= amount;
  if (balance < 0) {
    balance += amount;
    return -1;
  } else {
    return 1;
  }
}

string user::getName() const { return name; }

int user::getPin() const { return pin; }

void user::setName(string name) { this->name = name; }

int user::getUserId() const { return userId; }

bool user::comparePin(int pin) const {
  if (pin == this->pin) {
    return true;
  } else {
    return false;
  }
}

void user::showBalance() const {
  cout << "Balance of " << name << " is " << balance << "." << endl;
}

ostream &operator<<(ostream &os, const user &user) {
  os << user.name << " " << user.userId << " " << user.pin << " "
     << user.balance;
  return os;
}

// Define the >> operator for reading from a file
istream &operator>>(istream &is, user &user) {
  is >> user.name >> user.userId >> user.pin >> user.balance;
  return is;
}
