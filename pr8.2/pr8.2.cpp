#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// Custom exception for negative numbers
class NegativeNumberException : public exception {
    double value;
public:
    NegativeNumberException(double v) : value(v) {}
    const char* what() const noexcept override {
        return "Cannot compute square root of a negative number!";
    }
    double getValue() const { return value; }
};

// Custom exception for extremely large numbers
class LargeNumberException : public exception {
    double value;
public:
    LargeNumberException(double v) : value(v) {}
    const char* what() const noexcept override {
        return "Number is too large to process!";
    }
    double getValue() const { return value; }
};

int main() {
    double num;
    char retry;

    do {
        try {
            cout << "Enter a number: ";
            if (!(cin >> num)) throw invalid_argument("Invalid input! Please enter a numeric value.");

            if (num < 0)        throw NegativeNumberException(num);
            if (num > 1e15)     throw LargeNumberException(num);

            cout << "Square root of " << num << " = " << sqrt(num) << endl;

        } catch (const NegativeNumberException& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Invalid value entered: " << e.getValue() << endl;
        } catch (const LargeNumberException& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Value entered: " << e.getValue() << endl;
        } catch (const invalid_argument& e) {
            cout << "Input Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Try another number? (y/n): ";
        cin >> retry;

    } while (retry == 'y' || retry == 'Y');

    cout << "Program ended." << endl;
    return 0;
}
