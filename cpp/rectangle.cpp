#include <iostream>

template <class T>
class Rectangle {
    private:

        T length;
        T breadth;

    public:

        Rectangle(T length, T breadth) {
            this->length = length;
            this->breadth = breadth;
        }

        T area() {
            return (length * breadth);
        }

        T perimeter() {
            return (2 * (length + breadth));
        }

        void setLength(T length) {
            this->length = length;
        }

        void setBreadth(T breadth) {
            this->breadth = breadth;
        }

        T getBreadth(T breadth) {
            return breadth;
        }

        T getLength(T length) {
            return length;
        }
};

int main() {
    Rectangle<int> r(10, 5);
    Rectangle<float> r1(10.3, 5.5);
    std::cout << r.area() << "\n" << r.perimeter() << std::endl;
    std::cout << r1.area() << "\n" << r1.perimeter() << std::endl;
}
