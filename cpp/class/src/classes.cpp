#include <iostream>
#include "../lib/include/employee.h"

int main ()
{
    Developer d ("Inderpreet", "Nalla Corp", 18, "cpp");
    Teacher t ("Matthew", "Techers Corp", 18, "Java");
    d.FixBug();
    d.AskForPromotion();
    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
    return 0;
}
