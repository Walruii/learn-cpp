#include <iostream>
#include <stack>


int main ()
{
    std::stack<std::string> games;

    games.push("Minecraft");
    games.push("GTA Sana Andreas");
    games.push("Hollow Knight");

    //std::cout << games.top();

    while (!games.empty())
    {
        std::cout << games.top() << std::endl;
        games.pop();
    }
    return 0;

}
