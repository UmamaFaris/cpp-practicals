
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generic Stack class
template <class T>
class Stack {
private:
    vector<T> items;

public:

    // Add element
    void push(T value) {
        items.push_back(value);
    }

    // Remove element
    void pop() {
        if (items.empty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            items.pop_back();
        }
    }

    // Display top element
    void top() {
        if (items.empty()) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "Top element: "
                 << items.back() << endl;
        }
    }

    // Check empty
    bool isEmpty() {
        return items.empty();
    }
};

int main() {

    // Integer Stack
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Integer Stack:" << endl;
    s1.top();
    s1.pop();
    s1.top();

    // Float Stack
    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);

    cout << "\nFloat Stack:" << endl;
    s2.top();

    // String Stack
    Stack<string> s3;
    s3.push("Hello");
    s3.push("World");

    cout << "\nString Stack:" << endl;
    s3.top();

    // Empty Stack Test
    cout << "\nEmpty Stack Test:" << endl;
    s3.pop();
    s3.pop();
    s3.pop();

    return 0;
}
