#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    string id_book;
    string title;
    string author;
    string intro;
    string category;
    int deposit;
    bool isborrow = false;

    void setid_book(const string& id_book);
    string getid_book() const;

    void settitle(const string& title);
    string gettitle() const;

    void setAuthor(const string& author);
    string getAuthor() const;

    void setIntro(const string& intro);
    string getIntro() const;

    void setCategory(const string& category);
    string getCategory() const;

    void setDeposit(int deposit);
    int getDeposit() const;

    void Borrowed();
    void Returned();
};

#endif