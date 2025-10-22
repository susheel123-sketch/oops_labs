/*Custom Exception for Library Management System: You are developing a simple library system where
users can borrow, return, and reserve books. The system should handle specific errors, including:
• BookNotAvailableException: Thrown when a user tries to borrow a book that is already issued.
• InvalidOperationException: Thrown when a user tries to perform an invalid operation, such as
returning a book they didn’t borrow.
• MemberNotFoundException: Thrown when a user tries to reserve a book using an invalid or
nonexistent member ID.
Task:
• Create custom exception classes for the above scenarios by inheriting from std::exception or
std::runtime_error.
• Write a class LibraryAccount with the following methods:
– void borrowBook(const std::string& bookTitle): Throws BookNotAvailableException
if the book is already borrowed.
– void returnBook(const std::string& bookTitle): Throws InvalidOperationException
if the user has not borrowed that book.
– void reserveBook(const std::string& memberID, const std::string& bookTitle):
Throws MemberNotFoundException if the member ID is invalid, and BookNotAvailableExceptionImplementation in main():
• Demonstrate exception handling for borrowing, returning, and reserving books.
• Display appropriate error messages when an exception is thrown.*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_set>
using namespace std;



class BookNotAvailableException : public runtime_error {
public:
    BookNotAvailableException(const string& bookTitle)
        : runtime_error("Book not available: " + bookTitle) {}
};

class InvalidOperationException : public runtime_error {
public:
    InvalidOperationException(const string& message)
        : runtime_error("Invalid operation: " + message) {}
};

class MemberNotFoundException : public runtime_error {
public:
    MemberNotFoundException(const string& memberID)
        : runtime_error("Member not found: " + memberID) {}
};
class LibraryAccount {
private:
    unordered_set<string> borrowedBooks;
    unordered_set<string> validMembers = {"123", "456"}; 

public:
    void borrowBook(const string& bookTitle) {
        cout << "Attempting to borrow \"" << bookTitle << "\"..." << endl;

        if (borrowedBooks.count(bookTitle)) {
            throw BookNotAvailableException(bookTitle);
        }

        borrowedBooks.insert(bookTitle);
        cout << "Book borrowed successfully!" << endl;
    }

    void returnBook(const string& bookTitle) {
        cout << "Attempting to return \"" << bookTitle << "\"..." << endl;

        if (!borrowedBooks.count(bookTitle)) {
            throw InvalidOperationException("book not borrowed.");
        }

        borrowedBooks.erase(bookTitle);
        cout << "Book returned successfully!" << endl;
    }

    void reserveBook(const string& memberID, const string& bookTitle) {
        cout << "Attempting to reserve \"" << bookTitle
             << "\" for member ID " << memberID << "..." << endl;

        if (!validMembers.count(memberID)) {
            throw MemberNotFoundException(memberID);
        }

        if (borrowedBooks.count(bookTitle)) {
            throw BookNotAvailableException(bookTitle);
        }

        cout << "Reservation successful!" << endl;
    }
};
int main() {
    LibraryAccount account;

    try {
        account.borrowBook("The Great Gatsby");
        account.borrowBook("The Great Gatsby");
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        account.returnBook("To Kill a Mockingbird");
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        account.reserveBook("789", "1984");
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        account.reserveBook("123", "Pride and Prejudice");
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
