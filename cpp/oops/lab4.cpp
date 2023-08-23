#include <iostream>
int main()
{
     int n, num, digit, rev = 0;

     std::cout << "Enter a positive number: ";
     std::cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     std::cout << " The reverse of the number is: " << rev << std::endl;

     if (n == rev)
         std::cout << " The number is a palindrome.";
     else
         std::cout << " The number is not a palindrome.";

    return 0;
}
