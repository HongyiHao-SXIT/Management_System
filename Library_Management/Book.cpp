#include <iostream>
#include "Book.h"

void Book::setid_book(const string& id_book) {
    this->id_book = id_book;
}

string Book::getid_book() const {
    return id_book;
}

void Book::settitle(const string& title) {
    this->title = title;
}

string Book::gettitle() const {
    return title;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

string Book::getAuthor() const {
    return author;
}

void Book::setIntro(const string& intro) {
    this->intro = intro;
}

string Book::getIntro() const {
    return intro;
}

void Book::setCategory(const string& category) {
    this->category = category;
}

string Book::getCategory() const {
    return category;
}

void Book::setDeposit(int deposit) {
    this->deposit = deposit;
}

int Book::getDeposit() const {
    return deposit;
}

void Book::Borrowed() {
    isborrow = true;
}

void Book::Returned() {
    isborrow = false;
}