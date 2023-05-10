#include <iostream>
#include <cctype>

char getchoice ();

int main ()
{
    srand(time(NULL));
    int cinput = rand() % 3;
    char arr[3] = {'R', 'P', 'S'};
    std::cout << "*********WELCOME TO RPS**********" << std::endl;
    std::cout << "*********************************" << std::endl;
    char input = getchoice();
    std::cout << "Computer Move: "<< arr[cinput] << std::endl;
    switch (input)
    {
        case 'R' :
            if (arr[cinput] == 'R')
            {
                std::cout << "DRAW" << std::endl;
            }
            else if (arr[cinput] == 'P')
            {
                std::cout << "YOU LOSE" << std::endl;
            }
            else {
                std::cout << "YOU WIN" << std::endl;
            }
            break;
        case 'P' :
            if (arr[cinput] == 'R')
            {
                std::cout << "YOU WIN" << std::endl;
            }
            else if (arr[cinput] == 'P')
            {
                std::cout << "DRAW" << std::endl;
            }
            else {
                std::cout << "YOU LOSE" << std::endl;
            }
            break;
        case 'S' :
            if (arr[cinput] == 'R')
            {
                std::cout << "YOU LOSE" << std::endl;
            }
            else if (arr[cinput] == 'P')
            {
                std::cout << "YOU WIN" << std::endl;
            }
            else {
                std::cout << "YOU LOSE" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid" << std::endl;
            break;
    }
    std::cout << "*********************************" << std::endl;
    std::cout << "*********************************" << std::endl;
}

char getchoice ()
{
    char input;
    do 
    {
        std::cout << "Enter your move: ";
        std::cin >> input;
        input = toupper(input);
    } while (input != 'R' && input != 'P' && input != 'S');
    std::cout << "\n";
    std::cout << "Player Move = " << input << std::endl;
    return input;

}
