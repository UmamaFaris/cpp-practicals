
#include <iostream>
#include <utility>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:

    // Default Constructor
    Array() {
        size = 0;
        arr = nullptr;
        cout << "Default Constructor\n";
    }

    // Parameterized Constructor
    Array(int n) {
        size = n;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = (i + 1) * 10;
        }

        cout << "Parameterized Constructor\n";
    }

    // Copy Constructor
    Array(const Array& obj) {
        size = obj.size;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }

        cout << "Copy Constructor\n";
    }

    // Copy Assignment
    Array& operator=(const Array& obj) {
        if (this != &obj) {
            delete[] arr;
            size = obj.size;
            arr = new int[size];

            for (int i = 0; i < size; i++) {
                arr[i] = obj.arr[i];
            }
        }

        cout << "Copy Assignment\n";
        return *this;
    }

    // Move Constructor
    Array(Array&& obj) noexcept {
        size = obj.size;
        arr = obj.arr;

        obj.size = 0;
        obj.arr = nullptr;

        cout << "Move Constructor\n";
    }

    // Move Assignment
    Array& operator=(Array&& obj) noexcept {
        if (this != &obj) {
            delete[] arr;

            size = obj.size;
            arr = obj.arr;

            obj.size = 0;
            obj.arr = nullptr;
        }

        cout << "Move Assignment\n";
        return *this;
    }

    // Display Function
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Array() {
        delete[] arr;
        cout << "Destructor Called\n";
    }
};

int main() {

    Array a1;
    Array a2(3);

    cout << "Original Array: ";
    a2.display();

    Array a3 = a2;

    cout << "Copied Array: ";
    a3.display();

    Array a4(2);
    a4 = a2;

    cout << "Assigned Array: ";
    a4.display();

    Array a5 = move(a2);

    cout << "Moved Array: ";
    a5.display();

    Array a6(1);
    a6 = move(a3);

    cout << "Move Assigned Array: ";
    a6.display();

    return 0;
}
