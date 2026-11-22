
#include <iostream>
#include <stdexcept>
using namespace std;

// Base Exception Class
class BankException : public runtime_error {
public:
    BankException(string msg) : runtime_error(msg) {}
};

// Custom Exception 1
class InsufficientFunds : public BankException {
public:
    InsufficientFunds() : BankException("Insufficient Balance!") {}
};

// Custom Exception 2
class InvalidAmount : public BankException {
public:
    InvalidAmount() : BankException("Invalid Amount!") {}
};

// Bank Account Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {

        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance = balance - amount;

        cout << "Withdrawal Successful!" << endl;
    }

    void showBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {

    BankAccount account(5000);

    cout << "Initial Account Details:" << endl;
    account.showBalance();

    // Successful Transaction
    try {
        account.withdraw(1000);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    account.showBalance();

    // Insufficient Balance
    try {
        account.withdraw(6000);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    // Invalid Amount
    try {
        account.withdraw(-500);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const InsufficientFunds& e) {
        cout << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.showBalance();

    return 0;
}
