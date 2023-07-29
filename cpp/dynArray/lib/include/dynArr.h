#pragma once
#include <iostream>

class DynArr {
private:
  int size;
  int *arr;

public:
  DynArr();
  void menu();
  void printArr();
  void deleteEle();
  int linearSearch(int key);
  void deletebyIndex();
  void deleteMenu();
  void insertMenu();
  void insertAtLast();
  void insertAtbeginning();
  void insertInBet();
};
