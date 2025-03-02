#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include "User.h"
#include "Book.h"

using namespace std;

void loadUsersFromFile(vector<User>& users);
void saveUsersToFile(const vector<User>& users);

bool login(vector<User>& users, string& input_username);
bool registerUser(vector<User>& users);

int menu();


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