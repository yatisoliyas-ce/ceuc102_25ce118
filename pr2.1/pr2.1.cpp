#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    void setDimensions(float l, float w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            cout << "Invalid dimensions! Setting to 1 by default.\n";
            length = 1;
            width = 1;
        }
    }

    float getArea() {
        return length * width;
    }

    float getPerimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }

    void updateDimensions(float l, float w) {
        setDimensions(l, w);
    }

    float getLength() {
        return length;
    }

    float getWidth() {
        return width;
    }
};

int main() {
    int n;
    cout << "Enter number of rectangles: ";
    cin >> n;

    Rectangle r[10];

    for (int i = 0; i < n; i++) {
        float l, w;
        cout << "\nEnter length and width for rectangle " << i + 1 << ": ";
        cin >> l >> w;
        r[i].setDimensions(l, w);
    }

    cout << "Rectangle Details\n";
    for (int i = 0; i < n; i++) {
        cout << "\nRectangle " << i + 1 << endl;
        r[i].display();
    }

    if (n >= 2) {
        if (r[0].getArea() > r[1].getArea())
            cout << "\nRectangle 1 is larger.\n";
        else if (r[0].getArea() < r[1].getArea())
            cout << "\nRectangle 2 is larger.\n";
        else
            cout << "\nBoth rectangles have equal area.\n";
    }

    return 0;
}
