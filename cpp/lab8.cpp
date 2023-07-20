#include <iostream>

int main() {
    int arr[100];
    int n;
    std::cout << "Enter the amount of numbers" << std::endl;
    std::cin >> n;

    std::cout << "Enter the numbers" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i == n-1) {
            continue;
        } else {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    return 0;
}
