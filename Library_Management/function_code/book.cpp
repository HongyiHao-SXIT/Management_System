#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>


class Book {
    public:
        string id_book;
        string title;
        string author;
        string intro;
        string category;
        int deposit;
        bool isborrow = false;
    
        void setid_book(string id_book) {
            this->id_book = id_book;
        }
    
        string getid_book() {
            return id_book;
        }
    
        void settitle(string title) {
            this->title = title;
        }
    
        string gettitle() {
            return title;
        }
    
        void setAuthor(string author) {
            this->author = author;
        }
    
        string getAuthor() {
            return author;
        }
    
        void setIntro(string intro) {
            this->intro = intro;
        }
        string getIntro() {
            return intro;
        }
    
        void setCategory(string category) {
            this->category = category;
        }
    
        string getCategory() {
            return category;
        }
    
        void setDeposit(int deposit) {
            this->deposit = deposit;
        }
    
        int getDeposit() {
            return deposit;
        }
    
        void Borrowed() {
            isborrow = true;
        }
    
        void Returned() {
            isborrow = false;
        }
    };