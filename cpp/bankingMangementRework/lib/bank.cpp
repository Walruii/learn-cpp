#include "./include/bank.hpp"
#include "./include/log.hpp"
#include "./include/user.hpp"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bank::bank() : MoneyInBank(0), userIdCount(1), logIdCount(1) {}
int bank::getUserIdCount() const { return userIdCount; }
int bank::getLogIdCount() const { return logIdCount; }
void bank::setUserIdCount(int userIdCount) { this->userIdCount = userIdCount; }
void bank::setLogIdCount(int logIdCount) { this->logIdCount = logIdCount; }

bool bank::creditUser(int userId, double amount) {
  user *usr1 = getUser(userId);
  if (usr1) {
    addTransaction(userId, amount, 1);
    usr1->creditBalance(amount);
    updateUser(userId);
    return true;
  }
  return false;
}

bool bank::debitUser(int userId, double amount) {
  user *usr1 = getUser(userId);
  int success = usr1->debitBalance(amount);
  if (!success) {
    return success;
  }
  addTransaction(userId, amount, 0);
  updateUser(userId);
  return success;
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

bool bank::deleteUser(int userId) {
  for (vector<user>::iterator it = users.begin(); it != users.end(); it++) {
    if (it->getUserId() == userId) {
      removeUserFromFile(*it);
      users.erase(it);
      return true;
    }
  }
  return false;
};

bool bank::addTransaction(int userId, double amount, int mode) {
  int id = logIdCount;
  logIdCount++;
  updateCountToFile();
  transactionLog log(userId, amount, id, mode);
  addTransactionToFile(log);
  logBook.push_back(log);
  return true;
}

void bank::showUserTransactions(int userId) const {
  cout << "ID\t\t" << "USERID\t\t" << "MODE\t\t" << "AMOUNT" << endl;

  for (int i = 0; i < logBook.size(); i++) {
    if (logBook[i].getUserId() == userId) {
      string mode = (logBook[i].getMode()) ? "Credit" : "Debit";
      cout << logBook[i].getId() << "\t\t" << logBook[i].getUserId() << "\t\t"
           << mode << "\t\t" << logBook[i].getAmount() << endl;
    }
  }
}

void bank::showTransactions() const {
  cout << "ID\t\t" << "USERID\t\t" << "MODE\t\t" << "AMOUNT" << endl;

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
  if (usr1) {
    cout << "Balance of " << usr1->getName() << " is " << usr1->getBalance()
         << "." << endl;
  } else {
    cout << "User Not Found!";
  }
}

bool bank::addUserToFile(const user &u1) const {
  ofstream outputFile("users.txt", ios::app);

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  outputFile << u1 << endl;

  outputFile.close();
  return true;
}

bool bank::removeUserFromFile(const user &u1) const {

  ifstream inputFile("users.txt");
  ofstream outputFile("temp.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file! temp.txt" << endl;
    return false;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file! users.txt" << endl;
    return false;
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
    return false;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  while (inputFile >> fileUser) {
    outputFile << fileUser << endl;
  }
  return true;
}

bool bank::addTransactionToFile(const transactionLog &log) const {

  ofstream outputFile("log.txt", ios::app);

  if (!outputFile.is_open()) {
    cerr << "Error opening file! log.txt" << endl;
    return false;
  }

  outputFile << log << endl;

  outputFile.close();
  return true;
}

bool bank::updateCountToFile() const {
  ofstream outputFile("bankInfo.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  outputFile << userIdCount << " " << logIdCount << endl;

  outputFile.close();
  return true;
}

void bank::listUsers() const {
  for (int i = 0; i < users.size(); i++) {
    cout << "UserName: " << users[i].getName()
         << " UserId: " << users[i].getUserId() << " Pin:" << users[i].getPin()
         << endl;
  }
}

bool bank::updateUser(int userId) const {
  user *usr = getUser(userId);
  ifstream inputFile("users.txt");
  ofstream outputFile("temp.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file! temp.txt" << endl;
    return false;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file! users.txt" << endl;
    return false;
  }

  // File operations go here

  user fileUser("test", -1, -1);
  while (inputFile >> fileUser) {
    if (usr->getUserId() != fileUser.getUserId()) {
      outputFile << fileUser << endl;
    } else {
      outputFile << usr->getName() << " " << usr->getUserId() << " "
                 << usr->getPin() << " " << usr->getBalance() << endl;
    }
  }

  inputFile.close(); // Always close the file when done
  outputFile.close();

  inputFile.open("temp.txt");
  outputFile.open("users.txt");

  if (!outputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  if (!inputFile.is_open()) {
    cerr << "Error opening file!" << endl;
    return false;
  }

  while (inputFile >> fileUser) {
    outputFile << fileUser << endl;
  }
  return true;
}
