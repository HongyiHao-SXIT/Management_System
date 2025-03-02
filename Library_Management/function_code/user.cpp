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