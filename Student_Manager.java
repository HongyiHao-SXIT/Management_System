import java.util.Scanner;

class Student {
    private int num;
    private String name;
    private String class_0;
    private float[] scores;
    private float average;
    private static String[] subjectNames;

    // 输入学生成绩信息的方法
    public void input(int numSubjects) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n======>>    请输入学生成绩    <<======");
        int i = 0;
        char sign = '0';
        while (sign!= 'n' && sign!= 'N') {
            System.out.print("班级：");
            class_0 = scanner.nextLine();
            System.out.print("学号：");
            num = scanner.nextInt();
            boolean flag = false;
            for (int c = 0; c < i; c++) {
                if (students[c].num == num) {
                    System.out.println("您输入的学号已存在！请重新输入。");
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            scanner.nextLine(); // 处理换行符
            System.out.print("姓名：");
            name = scanner.nextLine();
            scores = new float[numSubjects];
            for (int j = 0; j < numSubjects; j++) {
                int inputFlag = 0;
                while (inputFlag == 0) {
                    System.out.print("请输入 " + subjectNames[j] + " 成绩：");
                    scores[j] = scanner.nextFloat();
                    if (scores[j] > 100 || scores[j] < 1) {
                        System.out.println(" 对不起,合法数据！！\n");
                    } else {
                        inputFlag = 1;
                    }
                }
            }
            average = 0;
            for (int k = 0; k < numSubjects; k++) {
                average += scores[k];
            }
            average /= numSubjects;
            System.out.println(" 平均分为：" + average);
            System.out.print("======>>    提示：是否继续写入学生成绩?(y/n)");
            sign = scanner.next().charAt(0);
            scanner.nextLine(); // 处理换行符
            i++;
        }
        write(i);
    }

    // 统计学生成绩信息的方法
    public void statistic() {
        int n = read();
        System.out.println("\n======>>    输出学生统计数据    <<======\n");
        System.out.println("---------------------------------------");
        System.out.println("班级\t学号\t姓名\t平均分");
        System.out.println("---------------------------------------");
        for (int i = 0; i < n; i++) {
            System.out.println(students[i].class_0 + "\t" + students[i].num + "\t" + students[i].name + "\t" + students[i].average);
        }
        System.out.println("---------------------------------------");
    }

    // 查找学生成绩信息的方法
    public void lookup() {
        int n = read();
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n======>>    查找学生成绩    <<======");
        System.out.print("请输入要查找学生的学号：");
        int s = scanner.nextInt();
        int i = 0;
        while (i < n && students[i].num!= s) {
            i++;
        }
        if (i == n) {
            System.out.println("======>>    对不起，无法找到该学生......    <<======");
        } else {
            System.out.println("----------------------------");
            System.out.println("班级：" + students[i].class_0);
            System.out.println("学号：" + students[i].num);
            System.out.println("姓名：" + students[i].name);
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.println(subjectNames[j] + ":" + students[i].scores[j]);
            }
            System.out.println("平均分：" + students[i].average);
        }
    }

    // 修改学生成绩信息的方法
    public void modify() {
        int n = read();
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n======>>    修改学生成绩    <<======");
        System.out.print("请输入要修改成绩学生的学号：");
        int s = scanner.nextInt();
        int i = 0;
        while (i < n && students[i].num!= s) {
            i++;
        }
        if (i == n) {
            System.out.println("======>>    对不起，无法找到该学生......    <<======");
        } else {
            System.out.println("------------------------------------------------------------------------------------");
            System.out.println("班级\t学号\t姓名\t");
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print(subjectNames[j] + "\t");
            }
            System.out.println("平均分");
            System.out.println("------------------------------------------------------------------------------------");
            System.out.println(students[i].class_0 + "\t" + students[i].num + "\t" + students[i].name + "\t");
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print(students[i].scores[j] + "\t");
            }
            System.out.println(students[i].average);

            System.out.println("\n请重新输入该学生成绩： ");
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print("请输入 " + subjectNames[j] + " 成绩：");
                students[i].scores[j] = scanner.nextFloat();
            }
            students[i].average = 0;
            for (int k = 0; k < subjectNames.length; k++) {
                students[i].average += students[i].scores[k];
            }
            students[i].average /= subjectNames.length;
            System.out.println("平均分：" + students[i].average);

            System.out.print("======>>    是否保存数据 ？(y/n)");
            char c = scanner.next().charAt(0);
            if (c!= 'n' && c!= 'N') {
                write(n);
            }
        }
    }

    // 删除学生成绩信息的方法
    public void delete() {
        int n = read();
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n======>>    删除学生成绩    <<======");
        System.out.print("请输入要删除的学生的学号：");
        int s = scanner.nextInt();
        int i = 0;
        while (i < n && students[i].num!= s) {
            i++;
        }
        if (i == n) {
            System.out.println("======>>    对不起，无法找到该学生......    <<======");
        } else {
            for (int j = i; j < n - 1; j++) {
                students[j].class_0 = students[j + 1].class_0;
                students[j].num = students[j + 1].num;
                students[j].name = students[j + 1].name;
                students[j].scores = students[j + 1].scores;
                students[j].average = students[j + 1].average;
            }
            System.out.println("======>>    提示：已成功删除！");
        }
        write(n - 1);
    }

    // 插入学生成绩信息的方法
    public void insert() {
        Scanner scanner = new Scanner(System.in);
        int n = read();
        char s = '0';
        System.out.println("\n=======>>    增加学生成绩    <<========");
        while (s!= 'n' && s!= 'N') {
            System.out.print("班级：");
            class_0 = scanner.nextLine();
            System.out.print("学号：");
            num = scanner.nextInt();
            scanner.nextLine(); // 处理换行符
            System.out.print("姓名：");
            name = scanner.nextLine();
            scores = new float[subjectNames.length];
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print("请输入 " + subjectNames[j] + " 成绩：");
                scores[j] = scanner.nextFloat();
            }
            average = 0;
            for (int k = 0; k < subjectNames.length; k++) {
                average += scores[k];
            }
            average /= subjectNames.length;
            System.out.println("平均分：" + average);
            n++;
            System.out.print("======>>    是否继续插入(y/n)");
            s = scanner.next().charAt(0);
            scanner.nextLine(); // 处理换行符
        }
        write(n);
    }

    // 对学生成绩按照平均分进行排序的方法
    public void sort() {
        int n = read();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (students[j].average < students[j + 1].average) {
                    // 交换班级信息
                    String tempClass = students[j + 1].class_0;
                    students[j + 1].class_0 = students[j].class_0;
                    students[j].class_0 = tempClass;
                    // 交换学号
                    int tempNum = students[j + 1].num;
                    students[j + 1].num = students[j].num;
                    students[j].num = tempNum;
                    // 交换姓名
                    String tempName = students[j + 1].name;
                    students[j + 1].name = students[j].name;
                    students[j].name = tempName;
                    // 交换成绩数组
                    float[] tempScores = students[j + 1].scores;
                    students[j + 1].scores = students[j].scores;
                    students[j].scores = tempScores;
                    // 交换平均分
                    float tempAverage = students[j + 1].average;
                    students[j + 1].average = students[j].average;
                    students[j].average = tempAverage;
                }
            }
        }
        System.out.println("------------------------------------------------------------------------------------");
        System.out.println("班级\t学号\t姓名\t");
        for (int j = 0; j < subjectNames.length; j++) {
            System.out.print(subjectNames[j] + "\t");
        }
        System.out.println("平均分");
        System.out.println("------------------------------------------------------------------------------------");
        for (int i = 0; i < n; i++) {
            System.out.println(students[i].class_0 + "\t" + students[i].num + "\t" + students[i].name + "\t");
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print(students[i].scores[j] + "\t");
            }
            System.out.println(students[i].average);
        }
        write(n);
    }

    // 输出全部学生成绩信息的方法
    public void output() {
        int n = read();
        System.out.println("\n======>>    显示全部学生成绩    <<======");
        if (students == null) {
            System.out.println("没有记录");
        } else {
            System.out.println("------------------------------------------------------------------------------------");
            System.out.println("班级\t学号\t姓名\t");
            for (int j = 0; j < subjectNames.length; j++) {
                System.out.print(subjectNames[j] + "\t");
            }
            System.out.println("平均分");
            System.out.println("------------------------------------------------------------------------------------");
            for (int i = 0; i < n; i++) {
                System.out.println(students[i].class_0 + "\t" + students[i].num + "\t" + students[i].name + "\t");
                for (int j = 0; j < subjectNames.length; j++) {
                    System.out.print(students[i].scores[j] + "\t");
                }
                System.out.println(students[i].average);
            }
            System.out.println("------------------------------------------------------------------------------------");
        }
    }

    // 将学生成绩信息写入文件的方法（这里简单打印示例，实际可改为写入文件操作）
    private void write(int count) {
        System.out.println("将 " + count + " 条学生信息写入文件（此处为模拟，实际需实现文件写入逻辑）");
    }

    // 从文件中读取学生成绩信息的方法（这里简单返回固定值示例，实际需实现文件读取逻辑）
    private int read() {
        System.out.println("从文件中读取学生成绩信息（此处为模拟，实际需实现文件读取逻辑）");
        return 0;
    }
}

public class Student_Manager {
    private static Student[] students = new Student[100];
    private static String[] subjectNames;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入课程的数量：");
        int numSubjects = scanner.nextInt();
        scanner.nextLine(); // 处理换行符

        subjectNames = new String[numSubjects];
        for (int i = 0; i < numSubjects; i++) {
            System.out.print("请输入第 " + (i + 1) + " 门课程名称：");
            subjectNames[i] = scanner.nextLine();
        }

        Student student = new Student();
        student.subjectNames = subjectNames;

        for (;;) {
            int choice = menu(numSubjects);
            switch (choice) {
                case 1:
                    student.input(numSubjects);
                    break;
                case 2:
                    student.statistic();
                    break;
                case 3:
                    student.lookup();
                    break;
                case 4:
                    student.modify();
                    break;
                case 5:
                    student.delete();
                    break;
                case 6:
                    student.insert();
                    break;
                case 7:
                    student.sort();
                    break;
                case 8:
                    student.output();
                    break;
                case 0:
                    System.out.println("\n================感谢您使用学生成绩管理系统==============\n");
                    System.exit(0);
            }
        }
    }

    // 显示菜单并获取用户选择的方法
    private static int menu(int numSubjects) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("******************************************************");
        System.out.println("----------------欢迎使用学生成绩管理系统---------------");
        System.out.println("    *          【1】输入学生成绩                  *    ");
        System.out.println("    *          【2】显示统计数据                  *    ");
        System.out.println("    *          【3】查找学生成绩                  *    ");
        System.out.println("    *          【4】修改学生成绩                  *    ");
        System.out.println("    *          【5】删除学生成绩                  *    ");
        System.out.println("    *          【6】插入学生成绩                  *    ");
        System.out.println("    *          【7】按平均分排列                  *    ");
        System.out.println("    *          【8】显示学生成绩                  *    ");
        System.out.println("    *          【0】退出管理系统                  *    ");
        System.out.println("******************************************************");
        System.out.print("请选择您的操作 (0-8):");
        int choice = scanner.nextInt();
        scanner.nextLine(); // 处理换行符
        return choice;
    }
}