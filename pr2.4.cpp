#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "";
        price = 0;
        quantity = 0;
    }

    void setItem(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void addStock(int q) {
        if (q > 0)
            quantity += q;
        else
            cout << "Invalid quantity\n";
    }

    void sellItem(int q) {
        if (q > 0 && q <= quantity)
            quantity -= q;
        else
            cout << "Not enough stock\n";
    }

    void updatePrice(double p) {
        if (p > 0)
            price = p;
        else
            cout << "Invalid price\n";
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        if (quantity < 5)
            cout << "Low Inventory Alert\n";

    }

    int getQuantity() {
        return quantity;
    }

    int getId() {
        return id;
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    for (int i = 0; i < n; i++) {
        int id, qty;
        string name;
        double price;

        cout << "\nEnter details for item " << i + 1 << endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        items[i].setItem(id, name, price, qty);
    }

    int choice;
    do {
        cout << "\n1. Add Stock\n2. Sell Item\n3. Update Price\n4. Display All Items\n5. Item with Maximum Stock\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, qty;
        double price;

        switch (choice) {
        case 1:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> qty;
            for (int i = 0; i < n; i++)
                if (items[i].getId() == id)
                    items[i].addStock(qty);
            break;

        case 2:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to sell: ";
            cin >> qty;
            for (int i = 0; i < n; i++)
                if (items[i].getId() == id)
                    items[i].sellItem(qty);
            break;

        case 3:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;
            for (int i = 0; i < n; i++)
                if (items[i].getId() == id)
                    items[i].updatePrice(price);
            break;

        case 4:
            for (int i = 0; i < n; i++)
                items[i].display();
            break;

        case 5: {
            int maxIndex = 0;
            for (int i = 1; i < n; i++)
                if (items[i].getQuantity() > items[maxIndex].getQuantity())
                    maxIndex = i;

            cout << "\nItem with Maximum Stock:\n";
            items[maxIndex].display();
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
