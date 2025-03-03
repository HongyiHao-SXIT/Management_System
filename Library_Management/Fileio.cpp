// FileIO.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FileIO.h"
#include "User.h"

// 从文件加载用户信息
void loadUsersFromFile(std::vector<User>& users) {
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string id, name, address, account, password;
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

// 将用户信息保存到文件
void saveUsersToFile(const std::vector<User>& users) {
    std::ofstream file("users.txt");
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.id << " " << user.name << " " << user.age << " " << user.deposit << " "
                 << user.address << " " << (user.gender == Gender::MALE ? 0 : 1) << " "
                 << user.account << " " << user.password << " " << user.usability << std::endl;
        }
        file.close();
    }
}