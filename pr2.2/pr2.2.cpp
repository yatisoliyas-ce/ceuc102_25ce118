#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int m1, m2, m3;

public:
    Student() {
        rollNo = 0;
        name = "Test";
        m1 = m2 = m3 = 50;
    }

    Student(int r, string n, int a, int b, int c) {
        rollNo = r;
        name = n;
        m1 = (a >= 0 && a <= 100) ? a : 0;
        m2 = (b >= 0 && b <= 100) ? b : 0;
        m3 = (c >= 0 && c <= 100) ? c : 0;
    }

    float average() {
        return (m1 + m2 + m3) / 3.0;
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << " " << m2 << " " << m3;
        cout << "\nAverage: " << average() << endl;
    }

    float getAverage() {
        return average();
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[10];

    for (int i = 0; i < n; i++) {
        int roll, a, b, c;
        string name;

        cout << "\nRoll No: ";
        cin >> roll;
        cout << "Name: ";
        cin >> name;
        cout << "Enter 3 marks: ";
        cin >> a >> b >> c;

        s[i] = Student(roll, name, a, b, c);
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    int top = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].getAverage() > s[top].getAverage())
            top = i;
    }

    cout << "\nHighest Average Student:\n";
    s[top].display();

    return 0;
}
