#pragma once
#include <iostream>
using namespace std;

class ToDoItem {
  string item;
  bool status;

public:
  ToDoItem();
  ToDoItem(string item);
  ToDoItem(string item, bool status);
  void setItem(string item);
  void setStatus();
  string const getItem();
  bool const getStatus();
};

class list {
  vector<ToDoItem> thelist;

public:
  list();
  void menu();
  void const show();
  void addToDoItem(ToDoItem item);
  void deleteToDoItem(int todoNumber);
  void changeStatus(int todoNumber);
  void editTodo(int todoNumber, string text);
  void const saveToFile(string nameOffile);
};

class startMenu {
  list l1;

public:
  startMenu();
  void readFromFile();
};
