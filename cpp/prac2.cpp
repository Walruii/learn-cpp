#include <iostream>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = a;
}

void swapByRef(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main () {
    int x = 5;
    int y = 7;
    
    swapByRef(&x, &y);
    std::cout << x << ", " << y << std::endl;
    return 0;
}
