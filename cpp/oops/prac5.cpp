#include <iostream>
using namespace std;

int main () {
    int arr[10];
    int total = 0;
    cout << "Enter 10 numbers you want average of" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    cout << "Avg of the given numbers is " << total/10 << endl;
    return 0;
}
