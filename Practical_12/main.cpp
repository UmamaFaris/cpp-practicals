
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

// Base class
class LibraryItem {
protected:
    int id;
    string title;

public:
    LibraryItem(int i, string t) {
        id = i;
        title = t;
    }

    virtual void display() const {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
    }

    int getID() const {
        return id;
    }
};

// Derived class
class Book : public LibraryItem {
private:
    string author;
    bool available;

public:
    Book(int i, string t, string a, bool status = true)
        : LibraryItem(i, t) {
        author = a;
        available = status;
    }

    void display() const override {
        LibraryItem::display();
        cout << "Author: " << author << endl;
        cout << "Status: "
             << (available ? "Available" : "Issued") << endl;
        cout << "----------------------" << endl;
    }

    bool isAvailable() const {
        return available;
    }

    void issue() {
        if (!available)
            throw runtime_error("Book is already issued!");

        available = false;
    }

    void returnBook() {
        if (available)
            throw runtime_error("Book is already available!");

        available = true;
    }

    string getAuthor() const {
        return author;
    }

    bool getStatus() const {
        return available;
    }
};

// Library class
class Library {
private:
    vector<Book> books;

    void saveToFile() {
        ofstream file("books.csv");

        if (!file)
            throw runtime_error("File could not be opened!");

        for (const Book &b : books) {
            file << b.getID() << ","
                 << b.getAuthor() << ","
                 << b.isAvailable() << ","
                 << b.getID() << endl;
        }

        file.close();
    }

public:

    // Load books from file
    void loadFromFile() {
        ifstream file("books.csv");

        if (!file)
            return;

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string idText, author, statusText, titleText;

            getline(ss, idText, ',');
            getline(ss, author, ',');
            getline(ss, statusText, ',');
            getline(ss, titleText);

            try {
                int id = stoi(idText);
                bool status = (statusText == "1");

                books.push_back(
                    Book(id, titleText, author, status)
                );
            }
            catch (...) {
                continue;
            }
        }

        file.close();
    }

    // Add book
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        for (const Book &b : books) {
            if (b.getID() == id)
                throw runtime_error("Book ID already exists!");
        }

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        saveToFile();

        cout << "Book added successfully!" << endl;
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available!" << endl;
            return;
        }

        for (const Book &b : books) {
            b.display();
        }
    }

    // Search book
    void searchBook() {
        int id;

        cout << "Enter Book ID to search: ";
        cin >> id;

        for (const Book &b : books) {
            if (b.getID() == id) {
                cout << "Book Found!" << endl;
                b.display();
                return;
            }
        }

        throw runtime_error("Book not found!");
    }

    // Issue book
    void issueBook() {
        int id;

        cout << "Enter Book ID to issue: ";
        cin >> id;

        for (Book &b : books) {
            if (b.getID() == id) {
                b.issue();
                saveToFile();

                cout << "Book issued successfully!" << endl;
                return;
            }
        }

        throw runtime_error("Book not found!");
    }

    // Return book
    void returnBook() {
        int id;

        cout << "Enter Book ID to return: ";
        cin >> id;

        for (Book &b : books) {
            if (b.getID() == id) {
                b.returnBook();
                saveToFile();

                cout << "Book returned successfully!" << endl;
                return;
            }
        }

        throw runtime_error("Book not found!");
    }
};

// Main function
int main() {

    Library library;

    library.loadFromFile();

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {

                case 1:
                    library.addBook();
                    break;

                case 2:
                    library.displayBooks();
                    break;

                case 3:
                    library.searchBook();
                    break;

                case 4:
                    library.issueBook();
                    break;

                case 5:
                    library.returnBook();
                    break;

                case 6:
                    cout << "Thank you for using Library System!" << endl;
                    break;

                default:
                    cout << "Invalid choice!" << endl;
            }
        }
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 6);

    return 0;
}
