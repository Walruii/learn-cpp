#include <iostream>
#include <cmath>

int getDigit(const int ccnum);
int getEvenDigits(const std::string ccnum);
int getOddDigits(const std::string ccnum);

int main ()
{
    std::string ccnum;
    std::cout << "Enter the Credit Card number: ";
    std::cin >> ccnum;
    std::cout << '\n';
    int result = 0;

    result = getEvenDigits(ccnum) + getOddDigits(ccnum);
    
    if (result % 10 == 0)
    {
        std::cout << "The CC is valid" << std::endl;
    }
    else
    {
        std::cout << "The CC is not valid" << std::endl;
    }
}
int getDigit(const int ccnum)
{
    return ccnum % 10 + (ccnum / 10 % 10);
}
int getEvenDigits(const std::string ccnum)
{
    int sum = 0;

    for (int i = ccnum.length() - 2; i >= 0; i -= 2)
    {
        sum += getDigit((ccnum[i] - 48) * 2);
    }
    return sum;
}
int getOddDigits(const std::string ccnum)
{
    int sum = 0;

    for (int i = ccnum.length() - 1; i >= 0; i -=2)
    {
        sum += ccnum[i] - 48;
    }
    return sum;
}
