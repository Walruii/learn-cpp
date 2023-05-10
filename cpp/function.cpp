#include <iostream>

double area1(double size);

int main ()
{
    double size;
    double area;
    std::cout << "Enter length " << std::endl;
    std::cin >> size;
    area = area1(size);
    std::cout << area;

}

double area1(double size)
{
    return size * size;
}
