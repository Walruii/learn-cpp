    #include<iostream>
    int main() {
    	int num,factorial=1;
        std::cout << " Enter Number To Find Its Factorial:  ";
        std::cin >> num;
    	for (int a=1;a<=num;a++) {
    		factorial=factorial*a;
    	}
        std::cout << "Factorial of Given Number is =" << factorial << std::endl;
    	return 0;
    }
