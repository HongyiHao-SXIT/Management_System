#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

bool registerUser(string filename) {
    string newUsername, newPassword;
    cout << "请输入要注册的用户名: ";
    cin >> newUsername;

    ifstream inFile(filename);
    if (inFile.is_open()) {
        string storedUsername, storedPassword;
        while (inFile >> storedUsername >> storedPassword) {
            if (storedUsername == newUsername) {
                cout << "该用户名已存在，请选择其他用户名。" << endl;
                inFile.close();
                return false;
            }
        }
        inFile.close();
    }

    cout << "请输入密码: ";
    cin >> newPassword;

    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << newUsername << " " << newPassword << endl;
        outFile.close();
        cout << "注册成功！" << endl;
        return true;
    } else {
        cout << "无法打开文件进行写入操作。" << endl;
        return false;
    }
}

bool login(const string& filename) {
    string inputUsername, inputPassword;
    cout << "请输入用户名: ";
    cin >> inputUsername;
    cout << "请输入密码: ";
    cin >> inputPassword;

    ifstream inFile(filename);
    if (inFile.is_open()) {
        string storedUsername, storedPassword;
        while (inFile >> storedUsername >> storedPassword) {
            if (storedUsername == inputUsername && storedPassword == inputPassword) {
                inFile.close();
                cout << "登录成功！" << endl;
                return true;
            }
        }
        inFile.close();
    }
    cout << "用户名或密码错误，请重试。" << endl;
    return false;
}

int main() {
    const string filename = "users.txt";
    int choice;
    do {
        cout << "请选择操作:" << endl;
        cout << "1. 注册" << endl;
        cout << "2. 登录" << endl;
        cout << "3. 退出" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(filename);
                break;
            case 2:
                login(filename);
                break;
            case 3:
                cout << "退出程序。" << endl;
                break;
            default:
                cout << "无效的选择，请重新输入。" << endl;
        }
    } while (choice != 3);

    return 0;
}