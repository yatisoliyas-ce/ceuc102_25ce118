#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, val;
    vector<int> v;
    set<int> s;

    cout << "How many integers? ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
        s.insert(val); // duplicates auto-removed, auto-sorted
    }

    // Original vector (with duplicates)
    cout << "\nOriginal (with duplicates) : ";
    for (int x : v) cout << x << " ";

    // Display unique elements using set iterator
    cout << "\nUnique (via set iterator)  : ";
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    // Convert set back to vector
    vector<int> unique_v(s.begin(), s.end());
    cout << "\nConverted back to vector   : ";
    for (int x : unique_v) cout << x << " ";

    cout << "\n\nDuplicates removed : " << v.size() - s.size() << endl;
    cout << "Unique count       : " << s.size() << endl;

    return 0;
}
