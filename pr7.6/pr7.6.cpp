#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
    int* resource;
public:
    Derived() {
        resource = new int(42);
        cout << "Derived constructor\n";
    }
    ~Derived() {
        delete resource;
        cout << "Derived destructor\n";
    }
};

int main() {
    cout << "--- With virtual destructor ---\n";
    Base* obj = new Derived();
    delete obj;

    return 0;
}
