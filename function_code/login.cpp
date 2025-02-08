#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool login(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::cerr << "无法打开用户文件。" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string stored_username, stored_password;
        std::getline(iss, stored_username, ':');
        std::getline(iss, stored_password);

        if (stored_username == username && stored_password == password) {
            std::cout << "登录成功！" << std::endl;
            file.close();
            return true;
        }
    }

    std::cout << "用户名或密码错误，请重试。" << std::endl;
    file.close();
    return false;
}

int main() {
    std::string input_username, input_password;
    std::cout << "请输入用户名: ";
    std::cin >> input_username;
    std::cout << "请输入密码: ";
    std::cin >> input_password;

    login(input_username, input_password);

    return 0;
}