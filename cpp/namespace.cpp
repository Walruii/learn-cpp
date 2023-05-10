#include <iostream>

namespace gamer
{
    int x = 2;
}
namespace hehe
{
    int x = 5;
}

int main ()
{
    int x;
    x = 6;


    std::cout << x << gamer::x << hehe::x;
}
