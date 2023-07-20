#include <iostream>

int main () {

    char names[10][50];
    /* std::string names[10]; */
    int n;
    std::cout << "Enter the number of students up to 10" << std::endl;
    std::cin >> n;
    std::cout << "Enter the names" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << names[i] << std::endl;
    }
    return 0; 
}
