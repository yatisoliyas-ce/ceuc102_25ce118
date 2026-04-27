#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Directory: folder name -> list of files
map<string, vector<string>> directory;

void addFolder(string folder) {
    if (directory.find(folder) != directory.end())
        cout << "Folder already exists: " << folder << endl;
    else {
        directory[folder] = {};
        cout << "Folder created: " << folder << endl;
    }
}

void addFile(string folder, string file) {
    if (directory.find(folder) == directory.end()) {
        cout << "Folder not found: " << folder << endl;
        return;
    }
    // Prevent duplicate filenames
    for (string f : directory[folder])
        if (f == file) { cout << "File already exists in " << folder << endl; return; }

    directory[folder].push_back(file);
    cout << "File \"" << file << "\" added to \"" << folder << "\"" << endl;
}

void displayAll() {
    if (directory.empty()) { cout << "Directory is empty." << endl; return; }

    cout << "\n--- Directory Structure ---" << endl;
    // map auto-sorts folders alphabetically
    for (auto it = directory.begin(); it != directory.end(); it++) {
        cout << "[" << it->first << "] (" << it->second.size() << " files)" << endl;
        if (it->second.empty())
            cout << "   (no files)" << endl;
        else
            for (string f : it->second)
                cout << "   - " << f << endl;
    }
    cout << "---------------------------" << endl;
}

int main() {
    int choice;
    string folder, file;

    do {
        cout << "\n1. Add Folder" << endl;
        cout << "2. Add File to Folder" << endl;
        cout << "3. Display All" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Folder name: ";
                cin >> folder;
                addFolder(folder);
                break;

            case 2:
                cout << "Folder name: ";
                cin >> folder;
                cout << "File name: ";
                cin >> file;
                addFile(folder, file);
                break;

            case 3:
                displayAll();
                break;

            case 0:
                cout << "Exiting." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
