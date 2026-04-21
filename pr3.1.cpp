#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n, double salary, double b = 500.0) {
        name = n;
        basicSalary = (salary >= 0) ? salary : 0;
        bonus = (b >= 0) ? b : 0;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    string getGrade() {
        double total = totalSalary();
        if (total >= 50000) return "A";
        else if (total >= 30000) return "B";
        else if (total >= 15000) return "C";
        else return "D";
    }

    void updateBonus(double newBonus) {
        if (newBonus >= 0)
            bonus = newBonus;
    }

    void display() {
        cout << "Name        : " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus       : " << bonus << endl;
        cout << "Total Salary: " << totalSalary() << endl;
        cout << "Grade       : " << getGrade() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee** employees = new Employee*[n];

    for (int i = 0; i < n; i++) {
        string name;
        double salary, bonus;
        int choice;

        cout << "\nEmployee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;

        cout << "Basic Salary: ";
        cin >> salary;
        while (salary < 0) {
            cout << "Salary cannot be negative. Enter again: ";
            cin >> salary;
        }

        cout << "Use default bonus(1) or custom bonus(2)? ";
        cin >> choice;

        if (choice == 2) {
            cout << "Enter bonus amount: ";
            cin >> bonus;
            while (bonus < 0) {
                cout << "Bonus cannot be negative. Enter again: ";
                cin >> bonus;
            }
            employees[i] = new Employee(name, salary, bonus);
        } else {
            employees[i] = new Employee(name, salary);
        }
    }

    cout << "\n Employee Details " << endl;
    for (int i = 0; i < n; i++) {
        employees[i]->display();
    }

    char appraisal;
    cout << "\nDo you want to update bonus for any employee? (y/n): ";
    cin >> appraisal;

    if (appraisal == 'y' || appraisal == 'Y') {
        int idx;
        double newBonus;
        cout << "Enter employee number (1 to " << n << "): ";
        cin >> idx;
        while (idx < 1 || idx > n) {
            cout << "Invalid. Enter employee number (1 to " << n << "): ";
            cin >> idx;
        }
        cout << "Enter new bonus: ";
        cin >> newBonus;
        while (newBonus < 0) {
            cout << "Bonus cannot be negative. Enter again: ";
            cin >> newBonus;
        }
        employees[idx - 1]->updateBonus(newBonus);
        cout << "\n Updated Details" << endl;
        employees[idx - 1]->display();
    }

    for (int i = 0; i < n; i++) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}
