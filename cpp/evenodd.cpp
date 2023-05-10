#include <iostream>

int main ()
{
    int n;

    std::cin >> n;
    n % 2 ? std::cout << "odd" : std::cout << "even";
}
