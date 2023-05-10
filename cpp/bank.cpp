#include <iostream>

void bankBalance(double balance);
double bankDeposit();
double bankWithdraw(double balance);
void bankExit();

int main () 
{
    double balance = 0;
    int choice;
    do {
        std::cout << "**************************************" << std::endl;
        std::cout << "********WELCOME TO THE BANK***********" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << '\n';
        std::cout << "1. Show Bank Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << "**************************************" << std::endl;
        std::cout << '\n';

        std::cin >> choice;
        std::cin.clear();
        fflush(stdin);

        switch (choice)
        {
            case 1: bankBalance(balance);
                    break;
            case 2: balance += bankDeposit();
                    bankBalance(balance);
                    break;
            case 3: balance -= bankWithdraw(balance);
                    bankBalance(balance);
                    break;
            case 4: bankExit();
                    break;
            default: std::cout << "Invaild choice" << std::endl;
        }
    } while (choice != 4);
}

void bankBalance(double balance)
{
    std::cout << "Your Bank Balance is $" << balance << "." << std::endl;

}
double bankDeposit()
{
    double amount;
    if (amount < 0)
    {
        std::cout << "Invaild Amount!" << std::endl;
        return 0;
    }
    else 
    {
        return amount;
    }

}
double bankWithdraw(double balance)
{
    double amount;
    if (amount < 0)
    {
        std::cout << "Invalid Usage" << std::endl;
        return 3;
    }
    else if (amount > balance)
    {
        std::cout << "Invalid Amount" << std::endl;
        return 4;
    }
    else 
    {
        return amount;
    }

}

void bankExit()
{
    std::cout << "Thanks for Visting!" << std::endl;
}


