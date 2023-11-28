#include "./include/user.hpp"
#include <iostream>
#include <fstream>
using namespace std;

user::user(string name, int userId, int pin)
    : name(name), userId(userId), pin(pin | 1111), balance(0) {}

double const user::getBalance() { return balance; }

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

string const user::getName() { return name; }

void user::setName(string name) { this->name = name; }

int const user::getUserId() { return userId; }

bool const user::comparePin(int pin) {
  if (pin == this->pin) {
    return true;
  } else {
    return false;
  }
}

void user::showBalance() {
  cout << "Balance of " << name << " is " << balance << "." << endl;
}

ostream &operator<<(ostream &os, const user &user) {
  os << user.name << " " << user.userId << " " << user.pin << " " << user.balance;
  return os;
}

// Define the >> operator for reading from a file
istream &operator>>(istream &is, user &user) {
  is >> user.name >> user.userId >> user.pin >> user.balance;
  return is;
}
