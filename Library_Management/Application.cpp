#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include "headfile/menu.h"
#include "headfile/User.h"
#include "headfile/Book.h"

using namespace std;
void registerUser(vector<User>& users);
bool login(vector<User>& users, string& username);
int menu();
void addBook(vector<Book>& books);
void displayAllBooks(const vector<Book>& books);
void searchBook(const vector<Book>& books);
void borrowBook(vector<Book>& books);
void returnBook(vector<Book>& books);
void deleteBook(vector<Book>& books);
void modifyBook(vector<Book>& books);
void displayBorrowedBooks(const vector<Book>& books);

void loadUsersFromFile(vector<User>& users);
void saveUsersToFile(const vector<User>& users);

int menu();

int main() {
    vector<User> users;
    vector<Book> books;

    while (true) {
        cout << "Please select an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        int option;
        while (true) {
            cin >> option;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number: ";
            } else if (option < 1 || option > 3) {
                cout << "Invalid option. Please enter a number between 1 and 3: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

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
                        cout << "Press Enter to continue...";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        } else if (option == 3) {
            cout << "Exiting the program." << endl;
            break;
        }
    }

    return 0;
}