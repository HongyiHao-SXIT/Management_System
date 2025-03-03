#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include "Book.h"

void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Please enter the book ID: ";
    cin >> newBook.id_book;
    cout << "Please enter the book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Please enter the book author: ";
    getline(cin, newBook.author);
    cout << "Please enter the book introduction: ";
    getline(cin, newBook.intro);
    cout << "Please enter the book deposit: ";
    cin >> newBook.deposit;
    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
    
}

void displayAllBooks(const vector<Book>& books) {
    cout << "All books in the library:" << endl;
    for (const auto& book : books) {
        cout << "ID: " << book.id_book << ", Title: " << book.title << ", Author: " << book.author
             << ", Deposit: " << book.deposit << ", Borrowed: " << (book.isborrow ? "Yes" : "No") << endl;
    }
}

void searchBook(const vector<Book>& books) {
    string keyword;
    cout << "Please enter the keyword (title or author) to search: ";
    cin.ignore();
    getline(cin, keyword);
    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos) {
            cout << "ID: " << book.id_book << ", Title: " << book.title << ", Author: " << book.author
                 << ", Deposit: " << book.deposit << ", Borrowed: " << (book.isborrow ? "Yes" : "No") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with the given keyword." << endl;
    }
}

void borrowBook(vector<Book>& books) {
    string bookId;
    cout << "Please enter the ID of the book you want to borrow: ";
    cin >> bookId;
    for (auto& book : books) {
        if (book.id_book == bookId) {
            if (book.isborrow) {
                cout << "This book is already borrowed." << endl;
            } else {
                book.Borrowed();
                cout << "You have successfully borrowed the book." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void returnBook(vector<Book>& books) {
    string bookId;
    cout << "Please enter the ID of the book you want to return: ";
    cin >> bookId;
    for (auto& book : books) {
        if (book.id_book == bookId) {
            if (!book.isborrow) {
                cout << "This book is not borrowed." << endl;
            } else {
                book.Returned();
                cout << "You have successfully returned the book." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void deleteBook(vector<Book>& books) {
    string bookId;
    cout << "Please enter the ID of the book you want to delete: ";
    cin >> bookId;
    auto it = remove_if(books.begin(), books.end(), [bookId](const Book& book) {
        return book.id_book == bookId;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book deleted successfully." << endl;
    } else {
        cout << "Book not found." << endl;
    }
}

void modifyBook(vector<Book>& books) {
    string bookId;
    cout << "Please enter the ID of the book you want to modify: ";
    cin >> bookId;
    for (auto& book : books) {
        if (book.id_book == bookId) {
            cout << "Please enter the new title (leave blank to keep unchanged): ";
            cin.ignore();
            string newTitle;
            getline(cin, newTitle);
            if (!newTitle.empty()) {
                book.settitle(newTitle);
            }
            cout << "Please enter the new author (leave blank to keep unchanged): ";
            string newAuthor;
            getline(cin, newAuthor);
            if (!newAuthor.empty()) {
                book.setAuthor(newAuthor);
            }
            cout << "Please enter the new introduction (leave blank to keep unchanged): ";
            string newIntro;
            getline(cin, newIntro);
            if (!newIntro.empty()) {
                book.setIntro(newIntro);
            }
            cout << "Please enter the new deposit (leave blank to keep unchanged): ";
            string depositStr;
            getline(cin, depositStr);
            if (!depositStr.empty()) {
                book.setDeposit(stoi(depositStr));
            }
            cout << "Book information modified successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void displayBorrowedBooks(const vector<Book>& books) {
    cout << "Borrowed books in the library:" << endl;
    bool found = false;
    for (const auto& book : books) {
        if (book.isborrow) {
            cout << "ID: " << book.id_book << ", Title: " << book.title << ", Author: " << book.author
                 << ", Deposit: " << book.deposit << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books are currently borrowed." << endl;
    }
}
