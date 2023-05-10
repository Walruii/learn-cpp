#include <iostream>
#include <queue>

void qp(std::queue<int> numbers)
{
    while (!numbers.empty())
    {
        std::cout << numbers.front() << ' ';
        numbers.pop();
    }
}

int main ()
{
    std::queue<int> numbers;

    numbers.push(1);
    numbers.push(2);
    numbers.push(3);

    qp(numbers);

    numbers.pop();
    numbers.push(1);

    qp(numbers);

    std::cout << numbers.size();
    return 0;
}
