#include <iostream>
using namespace std;

class Data {

    private:

    /* int arr[6] = {13, 21, 14, 19, 41, 28}; */
    int *arr = new int[6];
    int n = sizeof(arr)/sizeof(arr[0]);
    public:

    void getArr() {
        cout << "Printing the arr" << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl << endl;
    }
    void menu() {
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        cout << "1. Insert at the last" << endl;
        cout << "2. Insert in between" << endl;
        cout << "3. Insert at the first" << endl;
        cout << "0. Exit" << endl;
        cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        cout << "waiting for your input: ";
    }

    void addingLast() {
        int elem;
        cout << "what is the element you want to add: ";
        cin >> elem;

        int *p = (int*)malloc((n+1)*sizeof(int));
        for (int i = 0; i < n; i++) {
            p[i] = arr[i];
        }
        p[n] = elem;
        for (int i = 0; i < n+1; i++) {
            cout << p[i] << " ";
        }
        getArr();
    }

};

int main() {
        Data d1;
        d1.getArr();
        int flag = 1;
        while (flag != 0) {
            d1.menu();
            cin >> flag;
            switch (flag) {
                case (1):  
                    d1.addingLast();
                    break;
                case (2):  
                    break;
                case (3):  
                    break;
                case (0):
                    exit(0);
                    break;
                
                default:
                    cout << "Wrong usage" << endl;
                    break;
            }
        }
    return 0;
}
