#include <iostream>

int main ()
{
    srand(time(NULL));

    int num1 = (rand() % 6) + 1;
    std::cout << num1;
}
