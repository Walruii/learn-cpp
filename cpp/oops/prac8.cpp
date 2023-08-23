#include <iostream>
using namespace std;

class sum {
    private:
        int a, b, total;
    public:
        void getData () {
            cout << "Enter two numbers ";
            cin >> a >> b;
        }
        
        void display () {
            total = a + b;
            cout << "The sum is " << total << endl;
        }
};

int main() {
    sum C;
    C.getData();
    C.display();
    return 0;
}
