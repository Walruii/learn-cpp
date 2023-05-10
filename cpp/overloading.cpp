#include <iostream>

void bakePizza();
void bakePizza(std::string toppings);
void bakePizza(std::string topping1, std::string topping2);

int main (void)
{
    bakePizza("PEP", "MUS");
}

void bakePizza()
{
    std::cout << "Here is your pizza!";
}
void bakePizza(std::string toppings)
{
    std::cout << "Here is your " << toppings << " pizza!";
}
void bakePizza(std::string topping1, std::string topping2)
{
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!";
}
