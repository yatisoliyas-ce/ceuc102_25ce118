#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    double principal;
    double annualRate;
    int tenureMonths;
    double emi;

public:
    Loan() {
        loanID = 0;
        principal = 0;
        annualRate = 0;
        tenureMonths = 0;
        emi = 0;
    }

    Loan(int id, double p, double r, int t) {
        loanID = id;
        principal = p;
        annualRate = r;
        tenureMonths = t;
        calculateEMI();
    }

    void setLoan(int id, double p, double r, int t) {
        loanID = id;
        principal = p;
        annualRate = r;
        tenureMonths = t;
        calculateEMI();
    }

    void calculateEMI() {
        if (principal > 0 && annualRate > 0 && tenureMonths > 0) {
            double monthlyRate = annualRate / (12 * 100);
            double power = pow(1 + monthlyRate, tenureMonths);
            emi = (principal * monthlyRate * power) / (power - 1);
        } else {
            emi = 0;
        }
    }

    double getEMI() {
        return emi;
    }

    void display() {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Principal: " << principal << endl;
        cout << "Annual Interest Rate: " << annualRate << endl;
        cout << "Tenure (Months): " << tenureMonths << endl;
        cout << "Monthly EMI: " << emi << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of loans: ";
    cin >> n;

    Loan loans[100];

    for (int i = 0; i < n; i++) {
        int id, t;
        double p, r;

        cout << "\nEnter details for loan " << i + 1 << endl;
        cout << "Loan ID: ";
        cin >> id;
        cout << "Principal Amount: ";
        cin >> p;
        cout << "Annual Interest Rate (%): ";
        cin >> r;
        cout << "Tenure (Months): ";
        cin >> t;

        loans[i].setLoan(id, p, r, t);
    }

    for (int i = 0; i < n; i++)
        loans[i].display();

    if (n >= 2) {
        int first = 0, second = 1;

        if (loans[second].getEMI() > loans[first].getEMI()) {
            int temp = first;
            first = second;
            second = temp;
        }

        for (int i = 2; i < n; i++) {
            if (loans[i].getEMI() > loans[first].getEMI()) {
                second = first;
                first = i;
            } else if (loans[i].getEMI() > loans[second].getEMI() && i != first) {
                second = i;
            }
        }

        cout << "\nLoan with 2nd Highest EMI:";
        loans[second].display();
    }

    return 0;
}
