#include <iostream>
using namespace std;

int main() {
    int a, b, c, max;
    cout << "Enter the 3 numbers ";
    cin >> a >> b >> c;
    if (a > b) {
        max = a;
    }
    else {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    cout << "The largest number is " << max << endl;
    return 0;
}
