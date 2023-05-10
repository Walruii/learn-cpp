#include <iostream>

int main (int argc, char *argv[])
{
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess;
    int tries = 0;

    std::cout << "Welcome to guessing game!" << std::endl;
    do
    {
        std::cout << "Enter your guess: " << std::endl;
        std::cin >> guess;
        tries++;
        if(guess > number)
            std::cout << "LOWER!" << std::endl;
        else 
            std::cout << "HIGHER!" << std::endl;
    } while(guess != number);
    std::cout << "You took " << tries << " tries." << std::endl;
    return 0;
}
