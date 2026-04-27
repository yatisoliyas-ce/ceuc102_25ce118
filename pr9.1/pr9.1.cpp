#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, val;
    vector<int> v;

    cout << "How many integers? ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }

    // Original
    cout << "\nOriginal   : ";
    for (int x : v) cout << x << " ";

    // Method 1: std::reverse()
    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());
    cout << "\nMethod 1 (std::reverse)  : ";
    for (int x : v1) cout << x << " ";

    // Method 2: Manual reversal using iterators
    vector<int> v2 = v;
    auto left  = v2.begin();
    auto right = v2.end() - 1;
    while (left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
    cout << "\nMethod 2 (Manual swap)   : ";
    for (int x : v2) cout << x << " ";

    cout << endl;
    return 0;
}
