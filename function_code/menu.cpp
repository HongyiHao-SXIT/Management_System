#include <iostream>
#include <limits>
#include <cstdlib>

// 使用命名空间 std
using namespace std;

int menu() {
    char choose;
    do {
        system("cls");
        cout << "******************************************************" << endl;
        cout << "----------------欢迎使用学生成绩管理系统---------------" << endl;
        cout << "    *          【1】输入学生成绩                  *    " << endl;
        cout << "    *          【2】显示统计数据                  *    " << endl;
        cout << "    *          【3】查找学生成绩                  *    " << endl;
        cout << "    *          【4】修改学生成绩                  *    " << endl;
        cout << "    *          【5】删除学生成绩                  *    " << endl;
        cout << "    *          【6】插入学生成绩                  *    " << endl;
        cout << "    *          【7】按平均分排列                  *    " << endl;
        cout << "    *          【8】显示学生成绩                  *    " << endl;
        cout << "    *          【0】退出管理系统                  *    " << endl;
        cout << "******************************************************" << endl;
        cout << "请选择您的操作 (0 - 8):" << endl;
        cin >> choose;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲区
    } while (choose < '0' || choose > '8');
    return (choose - '0');
}