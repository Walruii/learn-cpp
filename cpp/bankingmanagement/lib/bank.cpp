#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bank::bank() : MoneyInBank(0), userIdCount(1), logIdCount(1) {}
void bank::creditUser(int userId, double amount) {
  addTransaction(userId, amount, 1);
  user *usr1 = getUser(userId);
  usr1->creditBalance(amount);
}

int bank::debitUser(int userId, double amount) {
  user *usr1 = getUser(userId);
  int success = usr1->debitBalance(amount);
  if (success == -1) {
    return -1;
  }
  addTransaction(userId, amount, 0);
  return 1;
}

user *bank::getUser(int userId) const {
  for (const auto &currentUser : users) {
    if (currentUser.getUserId() == userId) {
      return const_cast<user *>(
          &currentUser); // Safe because it's a copy of the iterator
    }
  }
  return nullptr;
}

int bank::createUser(string name, int pin) {
  int id = userIdCount;
  user user1(name, id, pin);
  userIdCount++;
  updateCountToFile();
  users.push_back(user1);
  addUserToFile(user1);
  cout << "User Created!" << endl;
  return id;
}

void bank::deleteUser(int userId, int pin) {
  for (vector<user>::iterator it = users.begin(); it != users.end(); it++) {
    if (it->getUserId() == userId) {
      if (it->getPin() == pin) {
        removeUserFromFile(*it);
        users.erase(it);
        cout << "User deleted!" << endl;
        return;
      }
      cout << "Incorrect Pin";
      break;
    }
  }
  cout << "User not found!" << endl;
};

void bank::addTransaction(int userId, double amount, int mode) {
  int id = logIdCount;
  logIdCount++;
  updateCountToFile();
  transactionLog log(userId, amount, id, mode);
  addTransactionToFile(log);
  logBook.push_back(log);
}

void bank::showUserTransactions(int userId) const {
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

void bank::showTransactions() const {
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

bool bank::comparePin(int userId, int pin) const {
  user *usr1 = getUser(userId);
  if (!usr1) {
    return false;
  }
  return usr1->comparePin(pin);
}

void bank::showUserBalance(int userId) const {
  user *usr1 = getUser(userId);
  usr1->showBalance();
}

void bank::addUserToFile(const user &u1) const {
  ofstream outputFile("users.txt", ios::app);

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  outputFile << u1 << endl;

  outputFile.close();
}

void bank::removeUserFromFile(const user &u1) const {

  ifstream inputFile("users.txt");
  ofstream outputFile("temp.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  // File operations go here

  user fileUser("test", -1, -1);
  while (!inputFile.eof()) {

    inputFile >> fileUser;
    if (u1.getUserId() != fileUser.getUserId()) {
      outputFile << fileUser << endl;
    }
  }

  inputFile.close(); // Always close the file when done
  outputFile.close();

  inputFile.open("temp.txt");
  outputFile.open("users.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  while (inputFile >> fileUser) {
    outputFile << fileUser << endl;
  }
}

void bank::addTransactionToFile(const transactionLog &log) const {

  ofstream outputFile("log.txt", ios::app);

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  outputFile << log << endl;

  outputFile.close();
}

void bank::updateCountToFile() const {
  ofstream outputFile("bankInfo.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }

  outputFile << userIdCount << " " << logIdCount << endl;

  outputFile.close();
}
int bank::getUserIdCount() const { return userIdCount; }
int bank::getLogIdCount() const { return logIdCount; }
void bank::setUserIdCount(int userIdCount) { this->userIdCount = userIdCount; }
void bank::setLogIdCount(int logIdCount) { this->logIdCount = logIdCount; }
