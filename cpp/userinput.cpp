#include <iostream>

int main ()
{
    std::string name;
    int age;
    std::cout << "Hello what is your full name: ";
    std::getline(std::cin, name);

    std::cout << "\nWhat is your age: ";
    std::cin >> age;

    std::cout << "\nHello " << name << " You are " << age << " years old :D";

}
