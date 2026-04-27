#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Error log (basic array)
string errorLog[20];
int errorCount = 0;

void addError(int lineNum, string content, string reason) {
    if (errorCount < 20)
        errorLog[errorCount++] = "Line " + to_string(lineNum) + ": [" + content + "] -> " + reason;
}

void processFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) throw runtime_error("File not found: " + filename);

    string line;
    int lineNum = 0;
    double sum = 0;
    int validCount = 0;

    cout << "\n--- Processing File: " << filename << " ---" << endl;

    // Process line by line (no storing entire file)
    while (getline(file, line)) {
        lineNum++;

        // Try to parse each line as a number directly
        istringstream ss(line);
        double value;

        if (!(ss >> value)) {
            // Corrupted data - non-numeric
            cout << "  [SKIP] Line " << lineNum << ": \"" << line << "\" -> Not a valid number" << endl;
            addError(lineNum, line, "Corrupted/non-numeric data");
            continue;
        }

        // Valid line - process immediately
        sum += value;
        validCount++;
        cout << "  [OK]   Line " << lineNum << ": " << value << endl;
    }

    file.close();

    // Report results
    cout << "\n--- Results ---" << endl;
    cout << "Valid lines   : " << validCount << endl;
    cout << "Invalid lines : " << errorCount << endl;
    cout << "Sum           : " << sum << endl;
    if (validCount > 0)
        cout << "Average       : " << sum / validCount << endl;
}

int main() {
    string filename;
    char choice;

    // Retry mechanism for file not found
    while (true) {
        cout << "Enter file path: ";
        cin >> filename;

        try {
            processFile(filename);
            break; // success - exit loop

        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Retry? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                cout << "Exiting program." << endl;
                break;
            }
        }
    }

    // Display error log
    if (errorCount > 0) {
        cout << "\n--- Error Log ---" << endl;
        for (int i = 0; i < errorCount; i++)
            cout << errorLog[i] << endl;
    }

    return 0;
}
