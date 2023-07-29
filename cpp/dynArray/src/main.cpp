#include <iostream>
#include "../lib/dynArr.cpp"

int main() {
  int num, flag = -1;
  std::cout << "How many Objects do you want" << std::endl;
  std::cin >> num;
  DynArr arr[num];
  while (flag != 0) {
    std::cout << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cout << "1. Use object by number" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "**********************************" << std::endl;
    std::cin >> flag;
    switch (flag) {
    case 1:
      std::cout << "Enter number from 1 to " << num << "." << std::endl;
      int index;
      std::cin >> index;
      index--;
      arr[index].menu();
      break;
    case 0:
      exit(0);
      break;
    default:
      std::cout << "Invalid use";
      break;
    }
  }
}
