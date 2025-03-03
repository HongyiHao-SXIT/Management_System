#ifndef USER_H
#define USER_H

#include <string>
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

    User();
    User(const string& id, const string& name, int age, int deposit, const string& address, Gender gender, const string& phone_number, const string& account, const string& password);

    void Check_Deposit() const;
    void setId(const string& id);
    string getId() const;
    void setName(const string& name);
    string getName() const;
    void setAge(int age);
    int getAge() const;
    void setDeposit(int deposit);
    int getDeposit() const;
    void setAddress(const string& address);
    string getAddress() const;
    void setGender(Gender gender);
    Gender getGender() const;
    void setPhone_number(const string& phone_number);
    string getPhone_number() const;
    void setAccount(const string& account);
    string getAccount() const;
    void setPassword(const string& password);
    string getPassword() const;
    void Fresh_Usability();
    void Lock_Account();
};

#endif