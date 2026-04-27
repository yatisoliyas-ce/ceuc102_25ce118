#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator: ";
        if (!(cin >> a)) throw invalid_argument("Invalid input! Please enter integers only.");

        cout << "Enter denominator: ";
        if (!(cin >> b)) throw invalid_argument("Invalid input! Please enter integers only.");

        if (b == 0) throw runtime_error("Division by zero is not allowed!");

        // Division performed immediately during input extraction
        cout << "Result: " << a / b << endl;

    } catch (const invalid_argument& e) {
        cout << "Input Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Math Error: " << e.what() << endl;
    }

    return 0;
}
