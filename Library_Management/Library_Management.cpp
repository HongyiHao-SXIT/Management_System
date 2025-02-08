#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <stdlib.h>

using namespace std;

enum class Gender{
    MALE, FEMALE
};

class Person{
    public:
    string id;
    string name;
    int age;
    int deposit;
    string address;
    Gender gender;
    string account;
    string password;

    Person(string id, string name, int age, int deposite, string address, Gender gender, string account, string password){
        this->id = id;
        this->name = name;
        this->age = age;
        this->deposit = deposite;
        this->address = address;
        this->gender = gender;
        this->account = account;
        this->password = password;
    }

    void check_deposit(){
        if(deposit < 0){
            cout<<""<<endl;
        }
    }

    void setid(string id){
        this->id = id;
    }

    string getid(){
        return id;
    }

    void setname(string name){
        this->name = name;
    }

    string getname(){
        return name;
    }

    void setage(int age){
        this->age = age;
    }

    int getage(){
        return age;
    }

    void setdeposit(int deposit){
        this->deposit = deposit;
    }

    int getdeposit(){
        return deposit;
    }

    void setaddress(string address){
        this->address = address;
    }

    string getaddress(){
        return address;
    }

    void setgender(Gender gender){
        this->gender = gender;
    }

    Gender getgender(){
        return gender;
    }

    void setaccount(string account){
        this->account = account;
    }

    string getaccount(){
        return account;
    }

    void setpassword(string password){
        this->password = password;
    }

    string getpassword(){
        return password;
    }
};

class Book{
    public:
    string id_book;
    string title;
    string author;
    string intro;
    int deposit;
    bool isborrow = false;

    void setid_book(string id_book){
        this->id_book = id_book;
    }

    string getid_book(){

        return id_book;
    }

    void settitle(string title){
        this->title = title;
    }

    string gettitle(){

        return title;
    }

    void setauthor(string author){
        this->author = author;
    }

    string getauthor(){

        return author;
    }

    void setintro(string intro){
        this->intro = intro;
    }

    string getintro(){

        return intro;
    }

    void setdeposit(int deposit){
        this->deposit = deposit;
    }

    int getdeposit(){
        return deposit;
    }

    void borrowed(){
        isborrow = true;
    }

    void returned(){
        isborrow = false;
    }

};

bool login() {
    string correctUsername = "admin";
    string correctPassword = "password";

    string input_username, input_password;
    cout << "请输入用户名 ";
    cin >> input_username;
    cout << "请输入密码：";
    cin >> input_password;

    return (input_username == correctUsername && input_password == correctPassword);
}

int menu() {
    char choose;
    do {
        system("cls");
        cout << "******************************************************" << endl;
        cout << "-----------------------Welcome------------------------" << endl;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choose < '0' || choose > '8');
    return (choose - '0');
}
int main(){
    int num_try = 0;
    relogin:
    cout<< "Start"<<endl;
    if(!login()){
        ++num_try;
        if(num_try == 3){
            return 1;
        }
        cout<<"登录失败,用户名或密码错误,您还有 "<< 3-num_try<<"次尝试机会"<<endl;
        goto relogin;
    }
    menu();

    return 0;
}