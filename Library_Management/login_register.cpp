#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>
#include "menu.h"
#include "User.h"
#include "Book.h"
#include "Fileio.h"


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
    