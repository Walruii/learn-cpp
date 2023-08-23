#include <iostream>

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n-1);
}
int main () {
    int n;
    std::cout << "Enter the number you want to find factorial of ";
    std::cin >> n;
    std::cout << std::endl << "The factorial of " << n << " is " << fact(n) << std::endl;
    return 0;
}
