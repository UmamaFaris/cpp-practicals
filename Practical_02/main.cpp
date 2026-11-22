
#include <iostream>
using namespace std;

class BankAccount {
    
private:
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(int acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }

    // Display account details
    void display() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
        else {
            cout << "Invalid amount or insufficient balance!" << endl;
        }
    }
};

int main() {

    BankAccount acc1(101, 5000);
    BankAccount acc2(102, 8000);

    cout << "Account 1 Details:";
    acc1.display();

    acc1.deposit(1000);
    acc1.withdraw(500);

    cout << "\nUpdated Account 1:";
    acc1.display();

    cout << "\nAccount 2 Details:";
    acc2.display();

    return 0;
}
