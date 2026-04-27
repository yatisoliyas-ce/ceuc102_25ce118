#include <iostream>
#include <string>
using namespace std;

// Custom exception class
class InsufficientFundsException : public exception {
    double balance, amount;
public:
    InsufficientFundsException(double b, double a) : balance(b), amount(a) {}
    const char* what() const noexcept override {
        return "Insufficient funds for withdrawal!";
    }
    void display() const {
        cout << "  Attempted: " << amount << ", Available: " << balance << endl;
    }
};

// Transaction log
string logs[20];
int logIndex = 0;

void addLog(string msg) {
    if (logIndex < 20) logs[logIndex++] = msg;
}

// BankAccount class
class BankAccount {
    double balance;
public:
    BankAccount(double initial) : balance(initial) {}

    void deposit(double amount) {
        addLog("-> Entering deposit()");
        if (amount <= 0) throw invalid_argument("Deposit amount must be positive!");
        balance += amount;
        addLog("   Deposit successful: " + to_string(amount));
        addLog("<- Exiting deposit()");
    }

    void withdraw(double amount) {
        addLog("-> Entering withdraw()");
        if (amount <= 0) throw invalid_argument("Withdrawal amount must be positive!");
        if (amount > balance) throw InsufficientFundsException(balance, amount);
        balance -= amount;
        addLog("   Withdrawal successful: " + to_string(amount));
        addLog("<- Exiting withdraw()");
    }

    double getBalance() { return balance; }
};

int main() {
    BankAccount account(500.0);
    cout << "Initial Balance: " << account.getBalance() << endl;

    // 1. Successful deposit
    cout << "\n[Test 1] Depositing 200..." << endl;
    try {
        addLog("-> Entering main() - deposit");
        account.deposit(200);
        addLog("<- Exiting main() - deposit");
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        addLog("   Exception: invalid deposit");
    }

    // 2. Successful withdrawal
    cout << "\n[Test 2] Withdrawing 100..." << endl;
    try {
        addLog("-> Entering main() - withdraw");
        account.withdraw(100);
        addLog("<- Exiting main() - withdraw");
    } catch (const InsufficientFundsException& e) {
        cout << "Error: " << e.what() << endl;
        e.display();
        addLog("   Exception: InsufficientFunds");
    }

    // 3. Failed withdrawal
    cout << "\n[Test 3] Withdrawing 1000 (should fail)..." << endl;
    try {
        addLog("-> Entering main() - failed withdraw");
        account.withdraw(1000);
        addLog("<- Exiting main() - failed withdraw");
    } catch (const InsufficientFundsException& e) {
        cout << "Error: " << e.what() << endl;
        e.display();
        addLog("   Exception caught: InsufficientFundsException");
    }

    // Final balance
    cout << "\nFinal Balance: " << account.getBalance() << endl;

    // Display full log
    cout << "\n--- Transaction Log / Stack Unwind Trace ---" << endl;
    for (int i = 0; i < logIndex; i++)
        cout << logs[i] << endl;

    return 0;
}
