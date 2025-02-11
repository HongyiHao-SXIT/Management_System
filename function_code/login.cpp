#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool login(string username, string password) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        cerr << "Unable to open user file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string stored_username, stored_password;
        getline(iss, stored_username, ':');
        getline(iss, stored_password);

        if (stored_username == username && stored_password == password) {
            cout << "Login successful!" << endl;
            file.close();
            return true;
        }
    }

    cout << "Incorrect username or password. Please try again." << endl;
    file.close();
    return false;
}

int main() {
    string input_username, input_password;
    cout << "Please enter your username: ";
    cin >> input_username;
    cout << "Please enter your password: ";
    cin >> input_password;

    login(input_username, input_password);

    return 0;
}