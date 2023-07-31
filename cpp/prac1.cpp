#include <iostream>
using namespace std;

int main () {

    char names[10][50];
    int n;
    cout << "Enter the number of students up to 10" << endl;
    cin >> n;
    cout << "Enter the names" << endl;
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }
    return 0; 
}
