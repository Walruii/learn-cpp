#include <iostream>

int main ()
{
    std::string name;
    name.empty() ? std::cout << "Empty\n" : std::cout << "Full\n";
    std::cin >> name;
    std::cout << "Hello " << name << '\n';
    name.empty() ? std::cout << "Empty" : std::cout << "Full";
}
