#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

class Library {
private:
    vector<Book> books;
    int nextId = 1;

public:
    void addBook(const string& title, const string& author) {
        Book newBook = {nextId++, title, author, true};
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "List of Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << '\n';
        }
    }

    void searchBook(const string& title) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(title) != string::npos) {
                cout << "Found Book - ID: " << book.id
                     << ", Title: " << book.title
                     << ", Author: " << book.author
                     << ", Available: " << (book.isAvailable ? "Yes" : "No") << '\n';
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the title \"" << title << "\".\n";
        }
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "Book issued successfully.\n";
                } else {
                    cout << "Book is already issued.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // To ignore leftover newline character from previous input

        switch (choice) {
            case 1: {
                string title, author;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                string title;
                cout << "Enter title to search: ";
                getline(cin, title);
                library.searchBook(title);
                break;
            }
            case 4: {
                int id;
                cout << "Enter book ID to issue: ";
                cin >> id;
                library.issueBook(id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}