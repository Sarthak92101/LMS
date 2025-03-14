#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
};

class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

    void sortBooks() {
        for (int i = 0; i < bookCount - 1; ++i) {
            for (int j = 0; j < bookCount - i - 1; ++j) {
                if (books[j].title > books[j + 1].title) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

public:
    Library() : bookCount(0) {}

    void addBook(const string& title, const string& author) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount].title = title;
            books[bookCount].author = author;
            bookCount++;
            cout << "Book added successfully.\n";
        } else {
            cout << "Library is full. Cannot add more books.\n";
        }
    }

    void removeBook(const string& title) {
        int index = -1;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title == title) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < bookCount - 1; ++i) {
                books[i] = books[i + 1];
            }
            bookCount--;
            cout << "Book removed successfully.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void searchBook(const string& query) {
        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title.find(query) != string::npos || books[i].author.find(query) != string::npos) {
                cout << "Book found: " << books[i].title << " by " << books[i].author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the query.\n";
        }
    }

    void listBooks() {
        if (bookCount == 0) {
            cout << "No books available in the library.\n";
            return;
        }
        sortBooks();
        cout << "Books in the library (sorted alphabetically):\n";
        for (int i = 0; i < bookCount; ++i) {
            cout << books[i].title << " by " << books[i].author << endl;
        }
    }

    int getBookCount() const {
        return bookCount;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. List All Books\n";
        cout << "5. View Total Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
            break;
        case 2:
            cout << "Enter book title to remove: ";
            getline(cin, title);
            library.removeBook(title);
            break;
        case 3:
            cout << "Enter title or author to search: ";
            getline(cin, title);
            library.searchBook(title);
            break;
        case 4:
            library.listBooks();
            break;
        case 5:
            cout << "Total books available: " << library.getBookCount() << endl;
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
