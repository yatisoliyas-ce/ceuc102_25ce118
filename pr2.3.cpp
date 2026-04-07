#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    int id;
    double balance;
    string transactions[100];
    int tCount;

public:
    Account(string n, int i, double b) {
        name = n;
        id = i;
        balance = b;
        tCount = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions[tCount] = "Deposit: +" + to_string(amount);
            tCount++;
            cout << "Deposit successful\n";
        } else {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions[tCount] = "Withdraw: -" + to_string(amount);
            tCount++;
            cout << "Withdrawal successful\n";
        } else {
            cout << "Invalid withdrawal\n";
        }
    }

    void showSummary() {
        cout << "\n Account Summary \n";
        cout << "Customer Name: " << name << endl;
        cout << "Account ID: " << id << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "Last Transactions:\n";

        int start = (tCount > 3) ? tCount - 3 : 0;
        for (int i = start; i < tCount; i++) {
            cout << transactions[i] << endl;
        }
    }
};

int main() {
    string name;
    int id;
    double balance;

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter account ID: ";
    cin >> id;

    cout << "Enter initial balance: ";
    cin >> balance;

    Account acc(name, id, balance);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Summary\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                acc.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                acc.withdraw(amount);
                break;

            case 3:
                acc.showSummary();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
