#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

class Person{
    public:
    int id;
    string name;
    int age;
    int deposit;
    string address;
    Gender gender;
    string account;
    string password;
    
    void check_deposit(){
        if(deposit < 0){
            cout<<"余额不足"<<endl;
        }
    }

};

enum class Gender{
    MALE, FEMALE
};

int main(){
    std::cout<< "Hello world"<<std::endl;
    return 0;
}