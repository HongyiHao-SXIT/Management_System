#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include "management_system.h"

using namespace std;

enum class Gender {
    MALE, FEMALE
};

class User {
public:
    string id;
    string name;
    int age;
    int deposit;
    string address;
    Gender gender;
    string phone_number;
    string account;
    string password;
    bool usability = true;

    User() {

    }

    User(string id, string name, int age, int deposit, string address, Gender gender, string phone_number, string account, string password) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->deposit = deposit;
        this->address = address;
        this->gender = gender;
        this->phone_number = phone_number;
        this->account = account;
        this->password = password;
    }

    void Check_Deposit() {
        if (deposit < 0) {
            cout << "Insufficient balance." << endl;
        }
    }

    void setId(string id) {
        this->id = id;
    }

    string getId() {
        return id;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    void setDeposit(int deposit) {
        this->deposit = deposit;
    }

    int getDeposit() {
        return deposit;
    }

    void setAddress(string address) {
        this->address = address;
    }

    string getAddress() {
        return address;
    }

    void setGender(Gender gender) {
        this->gender = gender;
    }

    Gender getGender() {
        return gender;
    }

    void setPhone_number(string phone_number) {
        this->phone_number = phone_number;
    }

    string getPhone_number() {
        return phone_number;
    }

    void setAccount(string account) {
        this->account = account;
    }

    string getAccount() {
        return account;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

    void Fresh_Usability() {
        usability = true;
    }

    void Lock_Account() {
        usability = false;
    }
};

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

void loadUsersFromFile(vector<User>& users) {
    ifstream file("users.txt");
    if (file.is_open()) {
        string id, name, address, account, password;
        int age, deposit;
        int genderInt;
        bool usability;
        while (file >> id >> name >> age >> deposit >> address >> genderInt >> account >> password >> usability) {
            Gender gender = (genderInt == 0) ? Gender::MALE : Gender::FEMALE;
            users.emplace_back(id, name, age, deposit, address, gender, "", account, password);
            users.back().usability = usability;
        }
        file.close();
    }
}

void saveUsersToFile(const vector<User>& users) {
    ofstream file("users.txt");
    if (file.is_open()) {
        for (auto user : users) {
            file << user.id << " " << user.name << " " << user.age << " " << user.deposit << " "
                 << user.address << " " << (user.gender == Gender::MALE ? 0 : 1) << " "
                 << user.account << " " << user.password << " " << user.usability << endl;
        }
        file.close();
    }
}

bool registerUser(vector<User>& users) {
    string newAccount, newPassword;
    cout << "Please enter a new username: ";
    cin >> newAccount;

    for (auto user : users) {
        if (user.getAccount() == newAccount) {
            cout << "This username already exists. Please choose another one." << endl;
            return false;
        }
    }

    cout << "Please enter a password: ";
    cin >> newPassword;

    string newId = to_string(users.size() + 1);
    string newName = "NewUser";
    int newAge = 20;
    int newDeposit = 0;
    string newAddress = "Unknown";
    Gender newGender = Gender::MALE;

    users.emplace_back(newId, newName, newAge, newDeposit, newAddress, newGender, "", newAccount, newPassword);
    saveUsersToFile(users);
    cout << "Registration successful!" << endl;
    return true;
}

bool login(vector<User>& users, string& input_username) {
    string input_password;
    cout << "Please enter your username: ";
    cin >> input_username;
    cout << "Please enter your password: ";
    cin >> input_password;

    for (auto& user : users) {
        if (user.getAccount() == input_username && user.getPassword() == input_password && user.usability) {
            return true;
        }
    }
    return false;
}

int menu();

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

int main() {    
    vector<User> users;
    vector<Book> books;
    loadUsersFromFile(users);

    while (true) {
        cout << "Please select an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        int option;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == 1) {
            registerUser(users);
        } else if (option == 2) {
            int num_try = 0;
            string input_username;
            while (num_try < 3) {
                if (login(users, input_username)) {
                    int choice;
                    do {
                        choice = menu();
                        switch (choice) {
                            case 1:
                                addBook(books);
                                break;
                            case 2:
                                displayAllBooks(books);
                                break;
                            case 3:
                                searchBook(books);
                                break;
                            case 4:
                                borrowBook(books);
                                break;
                            case 5:
                                returnBook(books);
                                break;
                            case 6:
                                deleteBook(books);
                                break;
                            case 7:
                                modifyBook(books);
                                break;
                            case 8:
                                displayBorrowedBooks(books);
                                break;
                            case 0:
                                cout << "Exiting the library system." << endl;
                                break;
                        }
                        system("pause");
                    } while (choice != 0);
                    break;
                }
                ++num_try;
                if (num_try < 3) {
                    cout << "Login failed. Incorrect username or password. You have " << 3 - num_try << " attempts left." << endl;
                }
            }
            if (num_try == 3) {
                cout << "You have tried 3 times but failed to log in. The program has exited and your account has been locked. Please contact the administrator" << endl;
                for (auto& user : users) {
                    if (user.getAccount() == input_username) {
                        user.Lock_Account();
                    }
                }
            }
        }
    }
    return 0;
}