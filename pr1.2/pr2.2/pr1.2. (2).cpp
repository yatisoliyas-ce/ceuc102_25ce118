#include <iostream>
using namespace std;

class Book
{
    int id;
    char title[30];
    char author[30];
    int copies;

public:
    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        cout << "Enter Copies: ";
        cin >> copies;
    }

    int getId()
    {
        return id;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book Issued\n";
        }
        else
            cout << "No copies available\n";
    }

    void returnBook()
    {
        copies++;
        cout << "Book Returned\n";
    }
};

int main()
{
    Book b[50];
    int total = 0, choice, id;

    do
    {
        cout << "\n1.Add Book\n2.Issue Book\n3.Return Book\n4.Total Books\n5.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b[total].addBook();
            total++;
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            for (int i = 0; i < total; i++)
                if (b[i].getId() == id)
                    b[i].issueBook();
            break;

        case 3:
            cout << "Enter Book ID: ";
            cin >> id;
            for (int i = 0; i < total; i++)
                if (b[i].getId() == id)
                    b[i].returnBook();
            break;

        case 4:
            cout << "Total Books: " << total << endl;
        }
    } while (choice != 5);

    return 0;
}
