#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Account Class
class BankAccount {
protected:
    int accNumber;
    double balance;
    vector<string> history;

public:
    BankAccount(int num, double bal) : accNumber(num), balance(bal) {
        cout << "Account " << accNumber << " created.\n";
    }
    ~BankAccount() {
        cout << "Account " << accNumber << " closed.\n";
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back("Deposited: " + to_string(amount));
        cout << "Deposited " << amount << ". Balance: " << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!\n";
            return;
        }
        balance -= amount;
        history.push_back("Withdrew: " + to_string(amount));
        cout << "Withdrew " << amount << ". Balance: " << balance << "\n";
    }

    void undoLast() {
        if (history.empty()) {
            cout << "No transactions to undo.\n";
            return;
        }
        cout << "Undone: " << history.back() << "\n";
        history.pop_back();
    }

    void displayDetails() {
        cout << "\nAccount No: " << accNumber << "\nBalance: " << balance << "\n";
        cout << "Transaction History:\n";
        for (auto& t : history) cout << "  " << t << "\n";
    }
};

// Savings Account
class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int num, double bal, double rate)
        : BankAccount(num, bal), interestRate(rate) {}

    void addInterest() {
        double interest = balance * interestRate / 100;
        deposit(interest);
        cout << "Interest added at " << interestRate << "%\n";
    }
};

// Current Account
class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(int num, double bal, double limit)
        : BankAccount(num, bal), overdraftLimit(limit) {}

    void withdraw(double amount) {
        if (amount > balance + overdraftLimit) {
            cout << "Exceeds overdraft limit!\n";
            return;
        }
        balance -= amount;
        history.push_back("Withdrew: " + to_string(amount));
        cout << "Withdrew " << amount << ". Balance: " << balance << "\n";
    }
};

// Main
int main() {
    SavingsAccount sa(101, 1000, 5);
    sa.deposit(500);
    sa.addInterest();
    sa.undoLast();
    sa.displayDetails();

    cout << "\n";

    CurrentAccount ca(202, 500, 200);
    ca.deposit(300);
    ca.withdraw(900);  // uses overdraft
    ca.displayDetails();

    return 0;
}
