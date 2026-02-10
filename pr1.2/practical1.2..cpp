#include <iostream>
using namespace std;

struct Book
{
    int id;
    char title[30];
    char author[30];
    int copies;
};

int totalBooks = 0;

void addBook(Book b[])
{
    cout << "Enter Book ID: ";
    cin >> b[totalBooks].id;
    cout << "Enter Title: ";
    cin >> b[totalBooks].title;
    cout << "Enter Author: ";
    cin >> b[totalBooks].author;
    cout << "Enter Copies: ";
    cin >> b[totalBooks].copies;
    totalBooks++;
}

void issueBook(Book b[], int id)
{
    for (int i = 0; i < totalBooks; i++)
    {
        if (b[i].id == id && b[i].copies > 0)
        {
            b[i].copies--;
            cout << "Book Issued\n";
            return;
        }
    }
    cout << "Book not available\n";
}

void returnBook(Book b[], int id)
{
    for (int i = 0; i < totalBooks; i++)
    {
        if (b[i].id == id)
        {
            b[i].copies++;
            cout << "Book Returned\n";
            return;
        }
    }
}

void displayTotalBooks()
{
    cout << "Total Books: " << totalBooks << endl;
}

int main()
{
    Book b[50];
    int choice, id;

    do
    {
        cout << "\n1.Add Book\n2.Issue Book\n3.Return Book\n4.Total Books\n5.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1: addBook(b); break;
        case 2: cout << "Enter ID: "; cin >> id; issueBook(b, id); break;
        case 3: cout << "Enter ID: "; cin >> id; returnBook(b, id); break;
        case 4: displayTotalBooks(); break;
        }
    } while (choice != 5);

    return 0;
}
