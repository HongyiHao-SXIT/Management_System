#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>

using namespace std;

enum class Gender {
    MALE, FEMALE
};

class Person {
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
    
    Person(string id, string name, int age, int deposit, string address, Gender gender, string phone_number, string account, string password) {
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

    void check_deposit() {
        if (deposit < 0) {
            cout << "Insufficient balance." << endl;
        }
    }

    void setid(string id) {
        this->id = id;
    }

    string getid() {
        return id;
    }

    void setname(string name) {
        this->name = name;
    }

    string getname() {
        return name;
    }

    void setage(int age) {
        this->age = age;
    }

    int getage() {
        return age;
    }

    void setdeposit(int deposit) {
        this->deposit = deposit;
    }

    int getdeposit() {
        return deposit;
    }

    void setaddress(string address) {
        this->address = address;
    }

    string getaddress() {
        return address;
    }

    void setgender(Gender gender) {
        this->gender = gender;
    }

    Gender getgender() {
        return gender;
    }

    void setPhone_number(string phone_number){
        this->phone_number;
    }

    string setPhone_number(){
        return phone_number;
    }

    void setaccount(string account) {
        this->account = account;
    }

    string getaccount() {
        return account;
    }

    void setpassword(string password) {
        this->password = password;
    }

    string getpassword() {
        return password;
    }

    void fresh_usability() {
        usability = true;
    }

    void lock_account() {
        usability = false;
    }
};

class Book {
public:
    string id_book;
    string title;
    string author;
    string intro;
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

    void setauthor(string author) {
        this->author = author;
    }

    string getauthor() {
        return author;
    }

    void setintro(string intro) {
        this->intro = intro;
    }

    string getintro() {
        return intro;
    }

    void setdeposit(int deposit) {
        this->deposit = deposit;
    }

    int getdeposit() {
        return deposit;
    }

    void borrowed() {
        isborrow = true;
    }

    void returned() {
        isborrow = false;
    }
};

void loadUsersFromFile(vector<Person>& users) {
    ifstream file("users.txt");
    if (file.is_open()) {
        string id, name, address, account, password;
        int age, deposit;
        int genderInt;
        bool usability;
        while (file >> id >> name >> age >> deposit >> address >> genderInt >> account >> password >> usability) {
            Gender gender = (genderInt == 0) ? Gender::MALE : Gender::FEMALE;
            users.emplace_back(id, name, age, deposit, address, gender, account, password);
            users.back().usability = usability;
        }
        file.close();
    }
}

void saveUsersToFile(const vector<Person>& users) {
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

// 注册函数
bool registerUser(vector<Person>& users) {
    string newAccount, newPassword;
    cout << "Please enter a new username: ";
    cin >> newAccount;

    for (auto user : users) {
        if (user.getaccount() == newAccount) {
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

    users.emplace_back(newId, newName, newAge, newDeposit, newAddress, newGender, newAccount, newPassword);
    saveUsersToFile(users);
    cout << "Registration successful!" << endl;
    return true;
}

bool login(vector<Person>& users) {
    string input_username, input_password;
    cout << "Please enter your username: ";
    cin >> input_username;
    cout << "Please enter your password: ";
    cin >> input_password;

    for (auto& user : users) {
        if (user.getaccount() == input_username && user.getpassword() == input_password && user.usability) {
            return true;
        }
    }
    return false;
}

int menu() {
    char choose;
    do {
        system("cls");
        cout << "******************************************************" << endl;
        //cout << "Hello"<<.name<<endl;
        cout << "------------------Welcome to Library------------------" << endl;
        cout << "    *          【1】Add a new book                 *    " << endl;
        cout << "    *          【2】Display all books              *    " << endl;
        cout << "    *          【3】Search for a book              *    " << endl;
        cout << "    *          【4】Borrow a book                  *    " << endl;
        cout << "    *          【5】Return a book                  *    " << endl;
        cout << "    *          【6】Delete a book                  *    " << endl;
        cout << "    *          【7】Modify book information        *    " << endl;
        cout << "    *          【8】Display borrowed books         *    " << endl;
        cout << "    *          【0】Exit the library system        *    " << endl;
        cout << "******************************************************" << endl;
        cout << "Please select your operation (0 - 8):" << endl;
        cin >> choose;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choose < '0' || choose > '8');
    return (choose - '0');
}

int main() {
    vector<Person> users;
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
        relogin:
            cout << "Start" << endl;
            if (!login(users)) {
                ++num_try;
                if (num_try == 3) {
                    cout << "You have tried 3 times but failed to log in. The program has exited and your account has been locked. Please contact the administrator" << endl;

                    for (auto& user : users) {
                        if (user.getaccount() == "admin") {
                            user.lock_account();
                            break;
                        }
                    }
                    saveUsersToFile(users);
                    return 1;
                }
                cout << "Login failed. Incorrect username or password. You have " << 3 - num_try << " attempts left." << endl;
                goto relogin;
            }
            menu();
            break;
        } else if (option == 3) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}