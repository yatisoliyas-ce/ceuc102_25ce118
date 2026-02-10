#include <iostream>
using namespace std;

class bank_account
{
    char account_name[25];
    int accountno;
    double balance;

public:
    void createacc();
    char s(int);
    void depositmoney();
    void withdrawmoney();
    void checkaccbalance();
};

char bank_account::s(int accno)
{
    if (accountno == accno)
        return 'V';
    else
        return 'I';
}

void bank_account::createacc()
{
    cout << "enter your name\n";
    cin >> account_name;
    cout << "enter your account number\n";
    cin >> accountno;
    cout << "enter your initial balance\n";
    cin >> balance;
}

void bank_account::depositmoney()
{
    double dmoney;
    cout << "enter the amount of money you want to deposit\n";
    cin >> dmoney;
    balance += dmoney;
}

void bank_account::withdrawmoney()
{
    double wmoney;
    cout << "enter the amount of money you want to withdraw\n";
    cin >> wmoney;
    if (wmoney <= balance)
        balance -= wmoney;
    else
        cout << "invalid balance\n";
}

void bank_account::checkaccbalance()
{
    cout << "your current balance is " << balance << endl;
}

int main()
{
    bank_account acc[50];
    int choice;
    int accno;
    int b = 0;
    int i;
    char f;

    cout << "Welcome to our bank\n";

do {
menu:
    cout << "\nChoose an Operation:\n";
    cout << "1. Create an account\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check balance\n";
    cout << "5. exit\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        acc[b].createacc();
        b++;
        goto menu;

    case 2:
        cout << "enter your account number\n";
        cin >> accno;

        for (i = 0; i < b; i++)
        {
            if (acc[i].s(accno) == 'V')
            {
                acc[i].depositmoney();
                goto menu;
            }
        }
        cout << "invalid account number\n";
        goto menu;

    case 3:
        cout << "enter your account number\n";
        cin >> accno;

        for (i = 0; i < b; i++)
        {
            if (acc[i].s(accno) == 'V')
            {
                acc[i].withdrawmoney();
                goto menu;
            }
        }
        cout << "invalid account number\n";
        goto menu;

    case 4:
        cout << "enter your account number\n";
        cin >> accno;

        for (i = 0; i < b; i++)
        {
            f = acc[i].s(accno);
            if (f == 'V')
            {
                acc[i].checkaccbalance();
                goto menu;
            }
        }
        cout << "invalid account number\n";
        goto menu;

    case 5:
        break;
    }

} while (choice != 5);

    return 0;
}
