#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    void Input(Student* stu, int numSubjects);
    void Statistic(Student* stu, int numSubjects);
    void Lookup(Student* stu, int numSubjects);
    void Modify(Student* stu, int numSubjects);
    void Delete(Student* stu, int numSubjects);
    void Insert(Student* stu, int numSubjects);
    void Sort(Student* stu, int numSubjects);
    void Write(Student* stu, int n, int numSubjects);
    int Read(Student* stu, int numSubjects);

    void Write(Student* stu, int n, int numSubjects) {
        fstream myFile;
        myFile.open("score.txt", ios::out | ios::binary);
        if (!myFile) {
            cout << "score.txt can't open!" << endl;
            abort();
        }
        int count = n;
        myFile << count << endl << numSubjects << endl;
        for (int i = 0; i < count; i++) {
            myFile << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t";
            for (int j = 0; j < numSubjects; j++) {
                myFile << stu[i].scores[j] << "\t";
            }
            myFile << stu[i].average << endl;
        }
        myFile.close();
    }

    int Read(Student* stu, int numSubjects) {
        fstream myFile;
        myFile.open("score.txt", ios::in | ios::binary);
        if (!myFile) {
            cout << "score.txt can't open!" << endl;
            abort();
        }
        int count;
        int subNum;
        myFile.seekg(0);
        myFile >> count >> subNum;
        if (subNum!= numSubjects) {
            cout << "课程数量不匹配，读取数据可能出错！" << endl;
            return 0;
        }
        for (int i = 0; i < count; i++) {
            myFile >> stu[i].class_0 >> stu[i].num >> stu[i].name;
            for (int j = 0; j < numSubjects; j++) {
                myFile >> stu[i].scores[j];
            }
            myFile >> stu[i].average;
        }
        myFile.close();
        return count;
    }

    void Input(Student* stu, int numSubjects) {
        system("cls");
        int i = 0;
        int flag;
        char sign = '0';
        cout << endl << "======>>    请输入学生成绩    <<======" << endl;
        while (sign!= 'n' && sign!= 'N') {
            cout << "班级：";
            cin >> stu[i].class_0;
            cout << "学号：";
            cin >> stu[i].num;
            int c = 0;
            while (c < i) {
                c++;
                if (stu[i].num == stu[i - c].num) {
                    cout << "您输入的学号已存在！请重新输入。" << endl;
                    goto input_loop;
                }
            }
            cout << "姓名：";
            cin >> stu[i].name;
            for (int j = 0; j < numSubjects; j++) {
                do {
                    flag = 0;
                    cout << "请输入 " << subjectNames[j] << " 成绩：";
                    cin >> stu[i].scores[j];
                    if (stu[i].scores[j] > 100 || stu[i].scores[j] < 1) {
                        cout << " 对不起,合法数据！！\n";
                    }
                    else {
                        flag = 1;
                    }
                } while (flag == 0);
            }
            stu[i].average = 0;
            for (int k = 0; k < numSubjects; k++) {
                stu[i].average += stu[i].scores[k];
            }
            stu[i].average /= numSubjects;
            cout << " 平均分为：" << stu[i].average << endl;
            cout << "======>>    提示：是否继续写入学生成绩?(y/n)";
            cin >> sign;
            i++;
            input_loop:;
        }
        Write(stu, i, numSubjects);
    }

    void Statistic(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        cout << endl << "======>>    输出学生统计数据    <<======\n" << endl;
        cout << "---------------------------------------" << endl;
        cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t" << "平均分" << endl;
        cout << "---------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].average << endl;
        }
        cout << "---------------------------------------" << endl;
        system("pause");
    }

    void Lookup(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        int s;
        int i = 0;
        cout << endl << "======>>    查找学生成绩    <<======" << endl;
        cout << "请输入要查找学生的学号：";
        cin >> s;
        while ((stu[i].num - s)!= 0 && i < n) i++;
        if (i == n) {
            cout << "======>>    对不起，无法找到该学生......    <<======" << endl;
        }
        else {
            cout << "----------------------------" << endl;
            cout << "班级：" << stu[i].class_0 << endl;
            cout << "学号：" << stu[i].num << endl;
            cout << "姓名：" << stu[i].name << endl;
            for (int j = 0; j < numSubjects; j++) {
                cout << subjectNames[j] << ":" << stu[i].scores[j] << endl;
            }
            cout << "平均分：" << stu[i].average << endl;
        }
    }

    void Modify(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        int s;
        int i = 0;
        cout << endl << "======>>    修改学生成绩    <<======" << endl;
        cout << "请输入要修改成绩学生的学号：";
        cin >> s;
        while ((stu[i].num - s)!= 0 && i < n) i++;
        if (i == n) {
            cout << "======>>    对不起，无法找到该学生......    <<======" << endl;
        }
        else {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
            for (int j = 0; j < numSubjects; j++) {
                cout << subjectNames[j] << "\t";
            }
            cout << "平均分" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t";
            for (int j = 0; j < numSubjects; j++) {
                cout << stu[i].scores[j] << "\t";
            }
            cout << stu[i].average << endl;
            cout << endl << "请重新输入该学生成绩： " << endl;
            for (int j = 0; j < numSubjects; j++) {
                cout << "请输入 " << subjectNames[j] << " 成绩：";
                cin >> stu[i].scores[j];
            }
            stu[i].average = 0;
            for (int k = 0; k < numSubjects; k++) {
                stu[i].average += stu[i].scores[k];
            }
            stu[i].average /= numSubjects;
            cout << "平均分：" << stu[i].average << endl;

            char c;
            cout << "======>>    是否保存数据 ？(y/n)";
            cin >> c;
            if (c!= 'n' && c!= 'N')
                Write(stu, n, numSubjects);
        }
    }

    void Delete(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        int s;
        int i = 0, j;
        cout << endl << "======>>    删除学生成绩    <<======" << endl;
        cout << "请输入要删除的学生的学号：";
        cin >> s;
        while ((stu[i].num - s)!= 0 && i < n) i++;
        if (i == n) {
            cout << "======>>    对不起，无法找到该学生......    <<======" << endl;
        }
        else {
            for (j = i; j < n - 1; j++) {
                strcpy(stu[j].class_0, stu[j + 1].class_0);
                stu[j].num = stu[j + 1].num;
                strcpy(stu[j].name, stu[j + 1].name);
                for (int k = 0; k < numSubjects; k++) {
                    stu[j].scores[k] = stu[j + 1].scores[k];
                }
                stu[j].average = stu[j + 1].average;
            }
            cout << "======>>    提示：已成功删除！" << endl;
        }
        Write(stu, n - 1, numSubjects);
    }

    void Insert(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        char s = '0';
        cout << endl << "=======>>    增加学生成绩    <<========" << endl;
        while (s!= 'n' && s!= 'N') {
            cout << "班级：";
            cin >> stu[n].class_0;
            cout << "学号：";
            cin >> stu[n].num;
            cout << "姓名：";
            cin >> stu[n].name;
            for (int j = 0; j < numSubjects; j++) {
                cout << "请输入 " << subjectNames[j] << " 成绩：";
                cin >> stu[n].scores[j];
            }
            stu[n].average = 0;
            for (int k = 0; k < numSubjects; k++) {
                stu[n].average += stu[n].scores[k];
            }
            stu[n].average /= numSubjects;
            cout << "平均分：" << stu[n].average << endl;
            n++;
            cout << "======>>    是否继续插入(y/n)";
            cin >> s;
        }
        Write(stu, n, numSubjects);
    }

    void Sort(Student* stu, int numSubjects) {
        system("cls");
        int i, j, k;
        float s;
        char t[20];
        cout << endl << "======>>    降序排列    <<======" << endl;
        int n = Read(stu, numSubjects);
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - 1; j++) {
                if (stu[j].average < stu[j + 1].average) {
                    strcpy(t, stu[j + 1].class_0);
                    strcpy(stu[j + 1].class_0, stu[j].class_0);
                    strcpy(stu[j].class_0, t);
                    //num
                    k = stu[j + 1].num;
                    stu[j + 1].num = stu[j].num;
                    stu[j].num = k;

                    //name
                    strcpy(t, stu[j + 1].name);
                    strcpy(stu[j + 1].name, stu[j].name);
                    strcpy(stu[j].name, t);
                    //scores
                    for (int m = 0; m < numSubjects; m++) {
                        s = stu[j + 1].scores[m];
                        stu[j + 1].scores[m] = stu[j].scores[m];
                        stu[j].scores[m] = s;
                    }
                    //average
                    s = stu[j + 1].average;
                    stu[j + 1].average = stu[j].average;
                    stu[j].average = s;
                }
            }
        }
        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
        for (int j = 0; j < numSubjects; j++) {
            cout << subjectNames[j] << "\t";
        }
        cout << "平均分" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t";
            for (int j = 0; j < numSubjects; j++) {
                cout << stu[i].scores[j] << "\t";
            }
            cout << stu[i].average << endl;
        }
        Write(stu, n, numSubjects);
    }

    void Output(Student* stu, int numSubjects) {
        system("cls");
        int n = Read(stu, numSubjects);
        cout << endl << "======>>    显示全部学生成绩    <<======" << endl;
        if (!stu) {
            cout << "没有记录";
        }
        else {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "班级" << "\t" << "学号" << "\t" << "姓名" << "\t";
            for (int j = 0; j < numSubjects; j++) {
                cout << subjectNames[j] << "\t";
            }
            cout << "平均分" << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < n; i++) {
                cout << stu[i].class_0 << "\t" << stu[i].num << "\t" << stu[i].name << "\t";
                for (int j = 0; j < numSubjects; j++) {
                    cout << stu[i].scores[j] << "\t";
                }
                cout << stu[i].average << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
        }
    }

private:
    int num;
    char name[8];
    char class_0[20];
    float* scores;
    float average;
    static char* subjectNames;
};

char* Student::subjectNames = nullptr;

int menu(int numSubjects) {
    char c;
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
        cout << "请选择您的操作 (0-8):" << endl;
        c = getchar();
    } while (c < '0' || c > '8');
    return (c - '0');
}

int main() {
    int numSubjects;
    cout << "请输入课程的数量：";
    cin >> numSubjects;
    cin.ignore();  // 清除输入缓冲区多余的换行符

    char** subjectNamesArr = new char* [numSubjects];
    for (int i = 0; i < numSubjects; i++) {
        subjectNamesArr[i] = new char[50];  // 假设科目名最长50个字符，可按需调整
        cout << "请输入第 " << (i + 1) << " 门课程名称：";
        cin.getline(subjectNamesArr[i], 50);
    }

    Student* students = new Student[100];
    Student::subjectNames = new char* [numSubjects];
    for (int i = 0; i < numSubjects; i++) {
        Student::subjectNames[i] = subjectNamesArr[i];
    }

    for (;;) {
        switch (menu(numSubjects)) {
            case 1:
                students->Input(students, numSubjects);
                break;
            case 2:
                students->Statistic(students, numSubjects);
                break;
            case 3:
                students->Lookup(students, numSubjects);
                system("pause");
                break;
            case 4:
                students->Modify(students, numSubjects);
                system("pause");
                break;
            case 5:
                students->Delete(students, numSubjects);
                system("pause");
                break;
            case 6:
                students->Insert(students, numSubjects);
                system("pause");
                break;
            case 7:
                students->Sort(students, numSubjects);
                system("pause");
                break;
            case 8:
                students->Output(students, numSubjects);
                system("pause");
                break;
            case 0:
                cout << endl << "================感谢您使用学生成绩管理系统==============\n" << endl;
                // 释放动态分配的内存
                for (int i = 0; i < numSubjects; i++) {
                    delete[] subjectNamesArr[i];
                }
                delete[] subjectNamesArr;
                delete[] students;
                delete[] Student::subjectNames;
                return 0;
        }
    }
    return 0;
}