#include "./include/list.hpp"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ToDoItem::ToDoItem() : item("NA"), status(false) {}
ToDoItem::ToDoItem(string item) : item(item), status(false) {}
ToDoItem::ToDoItem(string item, bool status) : item(item), status(status) {}
void ToDoItem::setItem(string item) { this->item = item; }
void ToDoItem::setStatus() { status = !status; }
string const ToDoItem::getItem() { return item; }
bool const ToDoItem::getStatus() { return status; }

list::list() {
  ToDoItem l1;
  thelist.push_back(l1);
}
void list::menu() {
  int flag;
  string line;
  int todoNumber;
  while (1) {
    system("clear");
    show();
    cout << "\n*************************TO DO LIST "
            "APP*********************************"
         << endl;
    cout << "1. Show | 2. Add | 3. Status | 4. Delete | 5. Edit | 6 Save | "
            "0. Exit"
         << endl;
    cout << "****************************************************************"
            "********"
         << endl;
    cin >> flag;
    switch (flag) {
    case 0:
      exit(0);
      break;
    case 1:
      show();
      break;
    case 2:
      cout << "Todo: ";
      getchar();
      getline(cin, line);
      addToDoItem(line);
      break;
    case 3:
      cout << "Todo Number: ";
      cin >> todoNumber;
      changeStatus(todoNumber);
      break;
    case 4:
      cout << "Todo Number: ";
      cin >> todoNumber;
      deleteToDoItem(todoNumber);
      break;
    case 5:
      cout << "Todo Number: ";
      cin >> todoNumber;
      cout << "Todo: ";
      getchar();
      getline(cin, line);
      editTodo(todoNumber, line);
      break;
    case 6:
      cout << "Save as: ";
      getchar();
      getline(cin, line);
      saveToFile(line);
      break;
    default:
      break;
    }
  }
}

void const list::show() {
  cout << endl;
  for (int i = 0; i < thelist.size(); i++) {
    cout << i + 1 << ". " << thelist[i].getItem();
    if (thelist[i].getStatus()) {
      cout << "\t\t\t\t [X]" << endl;
    } else {
      cout << "\t\t\t\t [ ]" << endl;
    }
  }
}

void list::addToDoItem(ToDoItem item) { thelist.push_back(item); }

void list::deleteToDoItem(int todoNumber) {
  thelist.erase(thelist.begin() + todoNumber - 1);
}

void list::changeStatus(int todoNumber) { thelist[todoNumber - 1].setStatus(); }

void list::editTodo(int todoNumber, string text) {
  thelist[todoNumber - 1].setItem(text);
}

void const list::saveToFile(string nameOffile) {
  ofstream fout;
  fout.open("lists/" + nameOffile + ".txt");
  if (fout) {
    for (int i = 0; i < thelist.size(); i++) {
      fout << thelist[i].getItem() << endl;
      fout << thelist[i].getStatus() << endl;
    }
    cout << "SAVED!";
  }
  fout.close();
}

startMenu::startMenu() {
  int flag;
  while (1) {
    cout << "1. New | 2. Old | 0. Exit" << endl;
    cin >> flag;
    switch (flag) {
    case 0:
      exit(0);
      break;
    case 1:
      l1.menu();
      break;
    case 2:
      l1.deleteToDoItem(1);
      readFromFile();
      l1.menu();
      break;
    }
  }
}

void startMenu::readFromFile() {
  string status;
  string nameOffile;
  bool b_status;
  string todo;
  cout << "Name of List: ";
  getchar();
  getline(cin, nameOffile);
  ifstream fin;
  fin.open("lists/" + nameOffile + ".txt");
  if (fin) {
    while (!fin.eof()) {
      getline(fin, todo);
      getline(fin, status);
      if (status == "0") {
        b_status = false;
      } else {
        b_status = true;
      }
      cout << todo << endl;
      if (todo != "") {
        ToDoItem item1(todo, b_status);
        l1.addToDoItem(item1);
      }
    }
  } else {
    cout << "File not Found! New Todo!";
  }
}
