#include <iostream>

int main ()
{
    srand(time(0));

    int randNum = (rand() % 3) + 1;
    switch (randNum)
    {
        case 1: std::cout << "You won nothing 1";
                break;
        case 2: std::cout << "You won nothing 2";
                break;
        case 3: std::cout << "You won nothing 3";
                break;
    }

}
