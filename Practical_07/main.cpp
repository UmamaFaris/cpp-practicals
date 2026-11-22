
#include <iostream>
using namespace std;

// Function Overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Complex Number Class
class ComplexNumber {
public:
    int real, imaginary;

    ComplexNumber(int r, int i) {
        real = r;
        imaginary = i;
    }

    // Operator Overloading
    ComplexNumber operator+(ComplexNumber obj) {
        ComplexNumber temp(0, 0);

        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;

        return temp;
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {

    // Function Overloading
    cout << "Integer Addition: " << add(10, 20) << endl;

    cout << "Double Addition: " << add(5.5, 4.5) << endl;

    // Operator Overloading
    ComplexNumber c1(10, 5);
    ComplexNumber c2(5, 3);

    ComplexNumber c3 = c1 + c2;

    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Addition Result: ";
    c3.display();

    return 0;
}
