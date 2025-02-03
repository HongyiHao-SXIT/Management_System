#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6


struct student{
    int num;
    char name[20];
    int class;
    char addr[50];
    char tel[20];
    char QQ[50];
};

struct Node{
    struct student data;
    struct Node *next;
};

struct Node *createList(){
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

struct Node *createNode(struct student data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void menu();

void keyDown();
void keydown1();
void keydown2();
void keydown3();
void keydown4();
void keydown5();
void insertNodeByHead(struct Node* headNode,struct student data);
void printList(struct Node* headNode);
void searchInfoByNum(struct Node* headNode,int num);
void searchInfoByName(struct Node* headNode,char *name);
void searchInfoByClass(struct Node* headNode,int class);
void deleteNumNode(struct Node* headNode,int num);
void deleteNameNode(struct Node* headNode,char *name);
void alterNumNode(struct Node* headNode,int num);
void alterNameNode(struct Node* headNode,char* name);
void sortUp(struct Node* headNode);
void sortDrop(struct Node* headNode);
void countClass(struct Node* headNode);
void countProvince(struct Node* headNode);
void readInFromFile(struct Node* headNode,char* filename);
void writeInFromFile(struct Node* headNode,char* filename);

struct Node* list = NULL;

int main()
{
    system("chcp 65001");
    list = createList();
    readInFromFile(list,"student.txt");
    while (1)
    {
        menu();
        keyDown();
        system("pause");
        system("cls");
    }
}

void menu(){
    printf("****************【学生通讯录管理系统】**************\n");
    printf("*\t\t1.学生通讯信息录入                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t2.学生通讯信息浏览                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t3.查询功能                         *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t4.学生通讯信息删除                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t5.学生通讯信息修改                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t6.学生通讯信息排序                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t7.学生通讯信息统计                 *\n");
    printf("*--------------------------------------------------*\n");
    printf("*\t\t0.退出系统                         *\n");
    printf("****************************************************\n");
}

void keyDown(){
    struct student data;
    int choice = 0;
    scanf("%d",&choice);
    switch(choice){
        case 0:
            printf("正常退出。");
            system("pause");
            exit(0);
            break;
        case 1:
            printf("----------------【学生通讯信息录入】----------------\n");
            printf("请输入学生的学号，姓名，班级，地址，电话，QQ:\n");
            fflush(stdin);
            scanf("%d %s %d %s %s %s",&data.num,data.name,&data.class,data.addr,data.tel,data.QQ);
            insertNodeByHead(list,data);
            printf("录入成功！");
            break;
        case 2:
            printf("----------------【学生通讯信息浏览】----------------\n");
            printList(list);
            break;
        case 3:
            printf("----------------【查询功能】----------------\n");
            printf("\t\t1.按学号查询\n");
            printf("\t\t2.按姓名查询\n");
            printf("\t\t3.按班级查询\n");
            keydown1();
            break;
        case 4:
            printf("----------------【学生通讯信息删除】----------------\n");
            printf("\t\t1.按学号删除\n");
            printf("\t\t2.按姓名删除\n");
            keydown2();
            break;
        case 5:
            printf("----------------【学生通讯信息修改】----------------\n");
            printf("\t\t1.按学号查找并修改\n");
            printf("\t\t2.按姓名查找并修改\n");
            keydown3();
            break;
        case 6:
            printf("----------------【学生通讯信息排序】----------------\n");
            printf("\t\t1.按学号升序排序\n");
            printf("\t\t2.按学号降序排序\n");
            keydown4();
            break;
        case 7:
            printf("----------------【学生通讯信息统计】----------------\n");
            printf("\t\t1.统计各班人数\n");
            printf("\t\t2.统计各省份人数\n");
            keydown5();
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
    }
    writeInFromFile(list,"student.txt");
}
void keydown1(){
    int choice = 0;
    scanf("%d",&choice);
    struct student data;
    switch(choice){
        case 1:
            printf("----------------【按学号查询】----------------\n");
            printf("请输入学号：");
            scanf("%d",&data.num);
            searchInfoByNum(list,data.num);
            break;
        case 2:
            printf("----------------【按姓名查询】----------------\n");
            printf("请输入姓名：");
            scanf("%s",data.name);
            searchInfoByName(list,data.name);
            break;
        case 3:
            printf("----------------【按班级查询】----------------\n");
            printf("请输入班级：");
            scanf("%d",&data.class);
            searchInfoByClass(list,data.class);
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
            break;
    }
}
void keydown2(){
    struct student data;
    int choice = 0;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("----------------【按学号删除】----------------\n");
            printf("请输入删除学生的学号：\n");
            scanf("%d",&data.num);
            deleteNumNode(list,data.num);
            break;
        case 2:
            printf("----------------【按姓名删除】----------------\n");
            printf("请输入删除学生的姓名：\n");
            scanf("%s",data.name);
            deleteNameNode(list,data.name);
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
            break;
    }
}
void keydown3() {
    struct student data;
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("----------------【按学号查找并修改】----------------\n");
            printf("请输入需要修改学生的学号：\n");
            scanf("%d", &data.num);
            alterNumNode(list, data.num);
            break;
        case 2:
            printf("----------------【按姓名查找并修改】----------------\n");
            printf("请输入需要修改学生的姓名：\n");
            scanf("%s", data.name);
            alterNameNode(list,data.name);
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
            break;
    }
}
void keydown4(){
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("----------------【按学号升序排序】----------------\n");
            sortUp(list);
            break;
        case 2:
            printf("----------------【按学号降序排序】----------------\n");
            sortDrop(list);
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
            break;
    }
}
void keydown5(){

    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("----------------【统计各班人数】----------------\n");
            countClass(list);
            break;
        case 2:
            printf("----------------【统计各省份人数】----------------\n");
            countProvince(list);
            break;
        default:
            printf("选择错误，请重新输入......\n");
            system("pause");
            break;
    }
}

void insertNodeByHead(struct Node* headNode,struct student data)
{
    struct Node* newNode = createNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

void printList(struct Node* headNode){
    struct Node* pMove = headNode->next;
    printf("学号\t姓名\t班级\t地址\t电话\t\tQQ\n");
    while (pMove){
        printf("%d\t%s\t%d\t%s\t%s\t%s\n",pMove->data.num,pMove->data.name,pMove->data.class,pMove->data.addr,pMove->data.tel,pMove->data.QQ);
        pMove = pMove->next;
    }
    printf("\n");
}

void searchInfoByNum(struct Node* headNode,int num){
    struct Node* pMove = headNode;
    while (pMove){
        if(pMove -> data.num == num){
            printf("学号\t姓名\t班级\t地址\t电话\t\tQQ\n");
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", pMove->data.num, pMove->data.name, pMove->data.class, pMove->data.addr,
                   pMove->data.tel, pMove->data.QQ);
            break;
        }
        pMove = pMove -> next;
    }
    if(pMove == NULL){
        printf("学号不存在，无法查找！\n ");
        return ;
    }

}

void searchInfoByName(struct Node* headNode,char *name){
    struct Node* pMove = headNode;
    while (pMove){
        if(strcmp(pMove -> data.name,name) == 0){
            printf("学号\t姓名\t班级\t地址\t电话\t\tQQ\n");
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", pMove->data.num, pMove->data.name, pMove->data.class, pMove->data.addr,
                   pMove->data.tel, pMove->data.QQ);
            break;
        }
        pMove = pMove -> next;
    }
    if(pMove == NULL){
        printf("名字不存在，无法查找！\n ");
        return ;
    }
}

void searchInfoByClass(struct Node* headNode,int class){
    struct Node* pMove = headNode;
    printf("学号\t姓名\t班级\t地址\t电话\t\tQQ\n");
    while (pMove){
        if(pMove -> data.class == class){
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", pMove->data.num, pMove->data.name, pMove->data.class, pMove->data.addr,
                   pMove->data.tel, pMove->data.QQ);
        }
        pMove = pMove -> next;
    }

    if(pMove == NULL){
        printf("班级不存在，无法查找！\n ");
        return ;
    }
}

void deleteNumNode(struct Node* headNode,int num){
    struct Node* posNode = headNode -> next;
    struct Node* posFrontNode = headNode;
    while(posNode -> data.num != num)
    {
        posFrontNode = posNode;
        posNode = posNode -> next;
    }
    if(posNode == NULL){
        printf("未找学号位置，无法删除！");
        return;
    }
    else{
        posFrontNode -> next = posNode -> next;
        free(posNode);
        printf("删除成功！");
    }

}

void deleteNameNode(struct Node* headNode,char *name){
    struct Node* posNode = headNode -> next;
    struct Node* posFrontNode = headNode;
    if(posNode == NULL){
        printf("名字不存在，无法删除！\n ");
        return;
    }
    while(strcmp(posNode -> data.name,name))
    {
        posFrontNode = posNode;
        posNode = posNode -> next;
    }
    if(posNode == NULL){
        printf("未找名字位置，无法删除！");
        return;
    }
    else{
        posFrontNode -> next = posNode -> next;
        free(posNode);
        printf("删除成功!");
    }

}

void alterNumNode(struct Node* headNode,int num){
    struct Node* posNode = headNode -> next;
    struct Node* posFrontNode = headNode;
    while(posNode -> data.num != num)
    {
        posFrontNode = posNode;
        posNode = posNode -> next;
    }
    if(posNode == NULL){
        printf("未找该学生，无法修改！");
        return;
    }
    else{
        struct student data;
        posFrontNode -> next = posNode -> next;
        free(posNode);
        printf("请重新输入学生的学号，姓名，班级，地址，电话，QQ:\n");
        fflush(stdin);
        scanf("%d %s %d %s %s %s",&data.num,data.name,&data.class,data.addr,data.tel,data.QQ);
        insertNodeByHead(list,data);
        printf("修改成功！");
    }
}

void alterNameNode(struct Node* headNode,char* name){
    struct Node* posNode = headNode -> next;
    struct Node* posFrontNode = headNode;
    while(strcmp(posNode -> data.name,name))
    {
        posFrontNode = posNode;
        posNode = posNode -> next;
    }
    if(posNode == NULL){
        printf("未找该学生，无法修改！");
        return;
    }
    else{
        struct student data;
        posFrontNode -> next = posNode -> next;
        free(posNode);
        printf("请重新输入学生的学号，姓名，班级，地址，电话，QQ:\n");
        fflush(stdin);
        scanf("%d %s %d %s %s %s",&data.num,data.name,&data.class,data.addr,data.tel,data.QQ);
        insertNodeByHead(list,data);
        printf("修改成功！");
    }
}

void sortUp(struct Node* headNode){
    struct Node* turn;
    struct Node* move;
    struct student temp;
    for(turn = headNode -> next;turn -> next != NULL;turn = turn -> next){
        for(move = headNode -> next;move -> next != NULL;move = move -> next){
            if(move -> data.num > move -> next -> data.num){
                temp = move -> data;
                move -> data = move -> next -> data;
                move -> next -> data = temp;
            }
        }
    }
    printList(list);
}

void sortDrop(struct Node* headNode){
    struct Node* turn;
    struct Node* move;
    struct student temp;
    for(turn = headNode -> next;turn -> next != NULL;turn = turn -> next){
        for(move = headNode -> next;move -> next != NULL;move = move -> next){
            if(move -> data.num < move -> next -> data.num){
                temp = move -> data;
                move -> data = move -> next -> data;
                move -> next -> data = temp;
            }
        }
    }
    printList(list);
}

void countClass(struct Node* headNode){
    int i;
    int count[N + 1] = {0};
    struct Node* pMove = headNode;
    while (pMove){
        for( i = 1;i <= N; i++){
            if (pMove->data.class == i ) count[i]++;
        }
        pMove = pMove -> next;
    }
    for (int i = 1;i <= N; i++) {
        printf("%d班的人数为：%d\n",i,count[i]);
    }
}

void countProvince(struct Node* headNode){
    char province[34][100] = {"Hebei","Shanxi","Liaoning","Jilin","Heilongjiang","Jiangsu","Zhejiang","Anhui","Fujian","Jiangxi","Shandong","Henan","Hubei","Hunan","Guangdong","Hannan","Sichuan","Guizhou","Yunnan","Shanxi","Gansu","Qinghai","Taiwan","Neimenggu","Guangxi","Xizang","Ningxia","Xinjiang","Beijiang","Tianjing","Shanghai","Chongqing","Xianggang","Aomen"};
    int i;
    int count[34] ={0};
    struct Node* pMove = headNode;
    while (pMove){
        for( i = 0;i < 34; i++){
            if (strcmp(pMove->data.addr,province[i]) == 0 ) count[i]++;
        }
        pMove = pMove -> next;
    }
    for (int i = 0;i < 34; i++) {
        if(count[i] != 0)
            printf("地址为%s的人数为%d\n",province[i],count[i]);
    }
}

void readInFromFile(struct Node* headNode,char* filename){
    struct student data;
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("文件打开失败！");
    }
    while (fscanf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",&data.num,data.name,&data.class,data.addr,data.tel,data.QQ) != EOF){
        insertNodeByHead(headNode,data);
    }

    fclose(fp);
}

void writeInFromFile(struct Node* headNode,char* filename){
    FILE *fp = fopen(filename,"w");
    struct Node* pMove = headNode -> next;
    while(pMove){
        fprintf(fp,"%d\t%s\t%d\t%s\t%s\t%s\n",pMove->data.num,pMove->data.name,pMove->data.class,pMove->data.addr,pMove->data.tel,pMove->data.QQ);
        pMove = pMove -> next;
    }
    fclose(fp);
}

