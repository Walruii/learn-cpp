#include <iostream>

int fib (int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return (fib(n-1)+fib(n-2));
}

int main () {
    int n;
    std::cout << "Enter the number till you want the series ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
