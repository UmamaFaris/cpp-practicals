
#include <iostream>
using namespace std;

int main()
{
    // Constant
    const int BONUS = 5;

    // Variables
    int num1, num2;

    // Taking input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Arithmetic operator
    int sum = num1 + num2;
    int total = sum + BONUS;

    // Display output
    cout << "\nSum = " << sum << endl;
    cout << "Total with bonus = " << total << endl;

    // Relational operator
    if (num1 > num2)
        cout << "First number is greater." << endl;
    else
        cout << "First number is not greater." << endl;

    // Logical operator
    if (num1 > 0 && num2 > 0)
        cout << "Both numbers are positive." << endl;
    else
        cout << "Both numbers are not positive." << endl;

    return 0;
}
