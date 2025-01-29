#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

// 学生信息类
class Student {
public:
    std::string class_;
    int num;
    std::string name;
    std::vector<float> scores;
    float average;

    // 计算平均分
    void calculateAverage() {
        average = 0;
        for (float score : scores) {
            average += score;
        }
        average /= scores.size();
    }
};

// 学生成绩管理系统类
class StudentGradeManagementSystem {
public:
    StudentGradeManagementSystem(int numSubjects) : numSubjects(numSubjects) {}

    // 输入学生成绩
    void input() {
        char sign = 'y';
        while (sign != 'n' && sign != 'N') {
            Student stu;
            std::cout << "班级：";
            std::cin >> stu.class_;
            std::cout << "学号：";
            while (!(std::cin >> stu.num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "输入无效，请输入一个有效的整数学号：";
            }
            if (isDuplicateNum(stu.num)) {
                std::cout << "您输入的学号已存在！请重新输入。" << std::endl;
                continue;
            }
            std::cout << "姓名：";
            std::cin >> stu.name;
            stu.scores.resize(numSubjects);
            for (int j = 0; j < numSubjects; j++) {
                float score;
                do {
                    std::cout << "请输入 " << subjectNames[j] << " 成绩：";
                    while (!(std::cin >> score)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "输入无效，请输入一个有效的成绩：";
                    }
                    if (score > 100 || score < 1) {
                        std::cout << " 对不起，输入的成绩不合法！！\n";
                    }
                } while (score > 100 || score < 1);
                stu.scores[j] = score;
            }
            stu.calculateAverage();
            std::cout << " 平均分为：" << stu.average << std::endl;
            students.push_back(stu);
            std::cout << "======>>    提示：是否继续写入学生成绩?(y/n)";
            std::cin >> sign;
        }
        write();
    }

    // 统计学生数据
    void statistic() {
        read();
        std::cout << std::endl << "======>>    输出学生统计数据    <<======\n" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t" << "平均分" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        for (const auto& stu : students) {
            std::cout << stu.class_ << "\t" << stu.num << "\t" << stu.name << "\t" << stu.average << std::endl;
        }
        std::cout << "---------------------------------------" << std::endl;
        system("pause");
    }

    // 查找学生成绩
    void lookup() {
        read();
        int s;
        std::cout << std::endl << "======>>    查找学生成绩    <<======" << std::endl;
        std::cout << "请输入要查找学生的学号：";
        while (!(std::cin >> s)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入一个有效的整数学号：";
        }
        auto it = std::find_if(students.begin(), students.end(), [s](const Student& stu) { return stu.num == s; });
        if (it == students.end()) {
            std::cout << "======>>    对不起，无法找到该学生......    <<======" << std::endl;
        }
        else {
            std::cout << "----------------------------" << std::endl;
            std::cout << "班级：" << it->class_ << std::endl;
            std::cout << "学号：" << it->num << std::endl;
            std::cout << "姓名：" << it->name << std::endl;
            for (int j = 0; j < numSubjects; j++) {
                std::cout << subjectNames[j] << ":" << it->scores[j] << std::endl;
            }
            std::cout << "平均分：" << it->average << std::endl;
        }
        system("pause");
    }

    // 修改学生成绩
    void modify() {
        read();
        int s;
        std::cout << std::endl << "======>>    修改学生成绩    <<======" << std::endl;
        std::cout << "请输入要修改成绩学生的学号：";
        while (!(std::cin >> s)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入一个有效的整数学号：";
        }
        auto it = std::find_if(students.begin(), students.end(), [s](const Student& stu) { return stu.num == s; });
        if (it == students.end()) {
            std::cout << "======>>    对不起，无法找到该学生......    <<======" << std::endl;
        }
        else {
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            std::cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
            for (const auto& subject : subjectNames) {
                std::cout << subject << "\t";
            }
            std::cout << "平均分" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            std::cout << it->class_ << "\t" << it->num << "\t" << it->name << "\t";
            for (float score : it->scores) {
                std::cout << score << "\t";
            }
            std::cout << it->average << std::endl;
            std::cout << std::endl << "请重新输入该学生成绩： " << std::endl;
            for (int j = 0; j < numSubjects; j++) {
                float score;
                do {
                    std::cout << "请输入 " << subjectNames[j] << " 成绩：";
                    while (!(std::cin >> score)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "输入无效，请输入一个有效的成绩：";
                    }
                    if (score > 100 || score < 1) {
                        std::cout << " 对不起，输入的成绩不合法！！\n";
                    }
                } while (score > 100 || score < 1);
                it->scores[j] = score;
            }
            it->calculateAverage();
            std::cout << "平均分：" << it->average << std::endl;

            char c;
            std::cout << "======>>    是否保存数据 ？(y/n)";
            std::cin >> c;
            if (c != 'n' && c != 'N') {
                write();
            }
        }
        system("pause");
    }

    // 删除学生成绩
    void remove() {
        read();
        int s;
        std::cout << std::endl << "======>>    删除学生成绩    <<======" << std::endl;
        std::cout << "请输入要删除的学生的学号：";
        while (!(std::cin >> s)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入一个有效的整数学号：";
        }
        auto it = std::find_if(students.begin(), students.end(), [s](const Student& stu) { return stu.num == s; });
        if (it == students.end()) {
            std::cout << "======>>    对不起，无法找到该学生......    <<======" << std::endl;
        }
        else {
            students.erase(it);
            std::cout << "======>>    提示：已成功删除！" << std::endl;
            write();
        }
        system("pause");
    }

    // 插入学生成绩
    void insert() {
        read();
        char s = 'y';
        while (s != 'n' && s != 'N') {
            Student stu;
            std::cout << "班级：";
            std::cin >> stu.class_;
            std::cout << "学号：";
            while (!(std::cin >> stu.num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "输入无效，请输入一个有效的整数学号：";
            }
            if (isDuplicateNum(stu.num)) {
                std::cout << "您输入的学号已存在！请重新输入。" << std::endl;
                continue;
            }
            std::cout << "姓名：";
            std::cin >> stu.name;
            stu.scores.resize(numSubjects);
            for (int j = 0; j < numSubjects; j++) {
                float score;
                do {
                    std::cout << "请输入 " << subjectNames[j] << " 成绩：";
                    while (!(std::cin >> score)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "输入无效，请输入一个有效的成绩：";
                    }
                    if (score > 100 || score < 1) {
                        std::cout << " 对不起，输入的成绩不合法！！\n";
                    }
                } while (score > 100 || score < 1);
                stu.scores[j] = score;
            }
            stu.calculateAverage();
            std::cout << "平均分：" << stu.average << std::endl;
            students.push_back(stu);
            std::cout << "======>>    是否继续插入(y/n)";
            std::cin >> s;
        }
        write();
    }

    // 按平均分排序
    void sort() {
        read();
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.average > b.average;
        });
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        std::cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
        for (const auto& subject : subjectNames) {
            std::cout << subject << "\t";
        }
        std::cout << "平均分" << std::endl;
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        for (const auto& stu : students) {
            std::cout << stu.class_ << "\t" << stu.num << "\t" << stu.name << "\t";
            for (float score : stu.scores) {
                std::cout << score << "\t";
            }
            std::cout << stu.average << std::endl;
        }
        write();
        system("pause");
    }

    // 显示全部学生成绩
    void output() {
        read();
        std::cout << std::endl << "======>>    显示全部学生成绩    <<======" << std::endl;
        if (students.empty()) {
            std::cout << "没有记录";
        }
        else {
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            std::cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
            for (const auto& subject : subjectNames) {
                std::cout << subject << "\t";
            }
            std::cout << "平均分" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            for (const auto& stu : students) {
                std::cout << stu.class_ << "\t" << stu.num << "\t" << stu.name << "\t";
                for (float score : stu.scores) {
                    std::cout << score << "\t";
                }
                std::cout << stu.average << std::endl;
            }
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
        }
        system("pause");
    }

    // 设置科目名称
    void setSubjectNames(const std::vector<std::string>& names) {
        subjectNames = names;
    }

private:
    int numSubjects;
    std::vector<Student> students;
    std::vector<std::string> subjectNames;

    // 写入文件
    void write() {
        std::ofstream myFile("score.txt");
        if (!myFile) {
            std::cout << "score.txt can't open!" << std::endl;
            return;
        }
        myFile << students.size() << std::endl << numSubjects << std::endl;
        for (const auto& stu : students) {
            myFile << stu.class_ << "\t" << stu.num << "\t" << stu.name << "\t";
            for (float score : stu.scores) {
                myFile << score << "\t";
            }
            myFile << stu.average << std::endl;
        }
        myFile.close();
    }

    // 读取文件
    void read() {
        std::ifstream myFile("score.txt");
        if (!myFile) {
            students.clear();
            return;
        }
        int count;
        int subNum;
        myFile >> count >> subNum;
        if (subNum != numSubjects) {
            std::cout << "课程数量不匹配，读取数据可能出错！" << std::endl;
            students.clear();
            myFile.close();
            return;
        }
        students.resize(count);
        for (int i = 0; i < count; i++) {
            myFile >> students[i].class_ >> students[i].num >> students[i].name;
            students[i].scores.resize(numSubjects);
            for (int j = 0; j < numSubjects; j++) {
                myFile >> students[i].scores[j];
            }
            myFile >> students[i].average;
        }
        myFile.close();
    }

    // 检查学号是否重复
    bool isDuplicateNum(int num) {
        for (const auto& stu : students) {
            if (stu.num == num) {
                return true;
            }
        }
        return false;
    }
};

// 简单的登录验证函数
bool login() {
    const std::string correctUsername = "admin";
    const std::string correctPassword = "password";

    std::string username, password;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入密码: ";
    std::cin >> password;

    return (username == correctUsername && password == correctPassword);
}

// 菜单函数
int menu() {
    char c;
    do {
        system("cls");
        std::cout << "******************************************************" << std::endl;
        std::cout << "----------------欢迎使用学生成绩管理系统---------------" << std::endl;
        std::cout << "    *          【1】输入学生成绩                  *    " << std::endl;
        std::cout << "    *          【2】显示统计数据                  *    " << std::endl;
        std::cout << "    *          【3】查找学生成绩                  *    " << std::endl;
        std::cout << "    *          【4】修改学生成绩                  *    " << std::endl;
        std::cout << "    *          【5】删除学生成绩                  *    " << std::endl;
        std::cout << "    *          【6】插入学生成绩                  *    " << std::endl;
        std::cout << "    *          【7】按平均分排列                  *    " << std::endl;
        std::cout << "    *          【8】显示学生成绩                  *    " << std::endl;
        std::cout << "    *          【0】退出管理系统                  *    " << std::endl;
        std::cout << "******************************************************" << std::endl;
        std::cout << "请选择您的操作 (0 - 8):" << std::endl;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
    } while (c < '0' || c > '8');
    return (c - '0');
}

int main() {
    if (!login()) {
        std::cout << "登录失败，程序退出。" << std::endl;
        return 1;
    }
    int numSubjects;
    std::cout << "请输入课程的数量：";
    while (!(std::cin >> numSubjects)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效，请输入一个有效的整数课程数量：";
    }
    std::cin.ignore();  // 清除输入缓冲区多余的换行符

    std::vector<std::string> subjectNames(numSubjects);
    for (int i = 0; i < numSubjects; i++) {
        std::cout << "请输入第 " << (i + 1) << " 门课程名称：";
        std::getline(std::cin, subjectNames[i]);
    }

    StudentGradeManagementSystem system(numSubjects);
    system.setSubjectNames(subjectNames);

    for (;;) {
        switch (menu()) {
        case 1:
            system.input();
            break;
        case 2:
            system.statistic();
            break;
        case 3:
            system.lookup();
            break;
        case 4:
            system.modify();
            break;
        case 5:
            system.remove();
            break;
        case 6:
            system.insert();
            break;
        case 7:
            system.sort();
            break;
        case 8:
            system.output();
            break;
        case 0:
            std::cout << std::endl << "================感谢您使用学生成绩管理系统==============\n" << std::endl;
            return 0;
        }
    }
    return 0;
}