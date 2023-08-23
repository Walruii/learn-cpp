#include <iostream>

int main() {
    int num;
    std::cout << "Enter the number" << std::endl;
    std::cin >> num;
    int counter = 0;
    for (int i = num; i > 1; i--)
    {
        if (num % i == 0){
            counter++;
        }
    }
    if (counter == 1) {
        std::cout << "The number is a prime number";
    } else {
        std::cout << "The number is not a prime number";
    }
    return 0;
}
