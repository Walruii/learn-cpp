#include <iostream>

int getInt() {
  int temp;
  std::cin >> temp;
  while (std::cin.fail()) {
    std::cout << "Error" << std::endl;
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> temp;
  }
  return temp;
}

class DynArr {
private:
  int size;
  int *arr;

public:
  DynArr();
  ~DynArr();
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

DynArr::DynArr() {
  this->size = 3;
  int *newArr = new int[size];
  this->arr = newArr;
  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }
}

DynArr::~DynArr() {
  delete[] arr;
  std::cout << "The array is deleted" << std::endl;
}

void DynArr::menu() {
  int flag = -1;
  while (flag != 0) {
    std::cout << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << "1. Print the Array" << std::endl;
    std::cout << "2. Delete from the Array" << std::endl;
    std::cout << "3. Insert in the Array" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "****************************" << std::endl;
    flag = getInt();
    switch (flag) {
    case 1:
      DynArr::printArr();
      break;
    case 2:
      DynArr::deleteMenu();
      break;
    case 3:
      DynArr::insertMenu();
      break;
    case 0:
      break;
    default:
      std::cout << "Invalid input";
      break;
    }
  }
}

void DynArr::printArr() {
  std::cout << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

void DynArr::deletebyIndex() {
  int index;
  std::cout << "Enter the index you want to delete starting from 1 ";
  std::cin >> index;
  index--;
  if (index > size - 1 || index < 0) {
    std::cout << "Invalid index" << std::endl;
  } else {
    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = size - 1;
  }
}

void DynArr::deleteMenu() {
  int flag;
  std::cout << std::endl;
  std::cout << "**********************************" << std::endl;
  std::cout << "Do you want to" << std::endl;
  std::cout << "1. Delete by index" << std::endl;
  std::cout << "2. Delete by element" << std::endl;
  std::cout << "**********************************" << std::endl;
  std::cout << "Input: ";
  std::cin >> flag;
  switch (flag) {
  case 1:
    DynArr::deletebyIndex();
    DynArr::printArr();
    break;
  case 2:
    DynArr::deleteEle();
    DynArr::printArr();
    break;
  default:
    std::cout << "Invalid input";
    break;
  }
}
void DynArr::deleteEle() {
  int element;
  std::cout << "Enter the element you want to delete ";
  std::cin >> element;
  int index = DynArr::linearSearch(element);
  if (index == -1) {
    std::cout << "Element Not Found!" << std::endl;
  } else {
    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    int *newArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = size - 1;
  }
}

int DynArr::linearSearch(int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}
void DynArr::insertMenu() {
  int flag;
  std::cout << std::endl;
  std::cout << "**********************************" << std::endl;
  std::cout << "Do you want to" << std::endl;
  std::cout << "1. Insert at the last" << std::endl;
  std::cout << "2. Insert at the beginning" << std::endl;
  std::cout << "3. Insert inbetween" << std::endl;
  std::cout << "**********************************" << std::endl;
  std::cout << "Input: ";
  std::cin >> flag;
  switch (flag) {
  case 1:
    DynArr::insertAtLast();
    DynArr::printArr();
    break;
  case 2:
    DynArr::insertAtbeginning();
    DynArr::printArr();
    break;
  case 3:
    DynArr::insertInBet();
    DynArr::printArr();
    break;
  default:
    std::cout << "Invalid input";
    break;
  }
}
void DynArr::insertAtLast() {
  int element;
  std::cout << "Enter the element you want to add ";
  std::cin >> element;
  int *newArr = new int[size + 1];
  for (int i = 0; i < size; i++) {
    newArr[i] = arr[i];
  }
  newArr[size] = element;
  delete[] arr;
  arr = newArr;
  size = size + 1;
}

void DynArr::insertAtbeginning() {
  int element;
  std::cout << "Enter the element you want to add ";
  std::cin >> element;
  int *newArr = new int[size + 1];
  newArr[0] = element;
  for (int i = 0; i < size; i++) {
    newArr[i + 1] = arr[i];
  }
  delete[] arr;
  arr = newArr;
  size = size + 1;
}
void DynArr::insertInBet() {
  int element, index;
  std::cout << "Enter the element you want to add ";
  std::cin >> element;
  std::cout << "Enter the index where you want to add ";
  std::cin >> index;
  index--;
  if (index < 0 || index > size) {
    std::cout << "Invalid index" << std::endl;
  } else {
    int *newArr = new int[size + 1];
    for (int i = 0, a = 0; i < size + 1; i++) {
      if (i == index) {
        newArr[i] = element;
      } else {
        newArr[i] = arr[a];
        a++;
      }
    }
    delete[] arr;
    arr = newArr;
    size = size + 1;
  }
}

int main() {
  int num, flag = -1;
  std::cout << "How many Objects do you want" << std::endl;
  num = getInt();
  DynArr arr[num];
  while (flag != 0) {
    std::cout << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "1. Use object by number" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "**********************************" << std::endl;
    flag = getInt();
    switch (flag) {
    case 1:
      std::cout << "Enter number from 1 to " << num << "." << std::endl;
      int index;
      std::cin >> index;
      index--;
      arr[index].menu();
      break;
    case 0:
      break;
    default:
      std::cout << "Invalid use";
      break;
    }
  }
}
