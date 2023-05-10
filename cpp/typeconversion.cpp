#include <iostream>

int main ()
{
    int marks = 56;
    int max_marks = 100;

    double percentage = marks / (double) max_marks * 100;

    std::cout << percentage << '%';
}
