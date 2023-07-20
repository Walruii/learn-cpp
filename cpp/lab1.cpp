#include <iostream>

int main() {
    int num1;
    std::cout << "Enter the number." << std::endl;
    std::cin >> num1;

    if (num1 % 2 == 0) {
        std::cout << "The number is even." << std::endl;

    } else {
        std::cout << "The number is odd." << std::endl;

    }
    return 0;
}
