#include <iostream>
#include <cmath>

int main ()
{
    double base;
    double height;
    double hypo;

    std::cout << "Enter the base and height respectively: ";
    std::cin >> base >> height;
    hypo = sqrt(pow(base, 2) + pow(height, 2));
    std::cout << '\n'<< hypo; 
}
