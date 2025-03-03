#include <iostream>
#include "User.h"
using namespace std;

User::User() : deposit(0), age(0), usability(true) {}

void User::Check_Deposit() const {
    if (deposit < 0) {
        cout << "Insufficient balance." << endl;
    }
}

void User::setId(const string& id) {
    this->id = id;
}

string User::getId() const {
    return id;
}

void User::setName(const string& name) {
    this->name = name;
}

string User::getName() const {
    return name;
}

void User::setAge(int age) {
    this->age = age;
}

int User::getAge() const {
    return age;
}

void User::setDeposit(int deposit) {
    this->deposit = deposit;
}

int User::getDeposit() const {
    return deposit;
}

void User::setAddress(const string& address) {
    this->address = address;
}

string User::getAddress() const {
    return address;
}

void User::setGender(Gender gender) {
    this->gender = gender;
}

Gender User::getGender() const {
    return gender;
}

void User::setPhone_number(const string& phone_number) {
    this->phone_number = phone_number;
}

string User::getPhone_number() const {
    return phone_number;
}

void User::setAccount(const string& account) {
    this->account = account;
}

string User::getAccount() const {
    return account;
}

void User::setPassword(const string& password) {
    this->password = password;
}

string User::getPassword() const {
    return password;
}

void User::Fresh_Usability() {
    usability = true;
}

void User::Lock_Account() {
    usability = false;
}