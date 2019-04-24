#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define DEBUG 1
struct Student
{
    char name[10];
    int num;
    int cScore;
    int eScore;
    int mScore;
    struct Student *nextNode;
};

char *p1="teacher.txt";//存储教师账号
char *p2="student.txt";//存储学生账号
char *p3="s.txt";//存储学生信息
char mangers[10]="zhangbin";
char mangerPassword[10]="123456";//管理员账号
void newMenu();
void launchBoundar();//启动界面
void menuAll(struct Student *head);//功能菜单
void menus();//功能界面
void Menu2();//登录注册界面
void mangerMenu();//管理员菜单
void stuFunctionMenu();//学生功能菜单
void loginMenu();//登录菜单
void mainMenu();//主菜单
void mangerMenus();//管理员菜单

void anyKeyGoOn();//按任意键继续
void change(char *p);//修改密码
void identityView(struct Student*head);//以何身份访问
void manger(struct Student*head);//管理员功能
void teachFunction(struct Student*head);//教师功能
void stuFunction(struct Student*head);//学生功能
void regist(char *p);//注册
void login(struct Student *head);//登录
void stuLogin(struct Student*head);//学生登录
void teachLogin(struct Student*head);//教师登录
void passWords(char *p);//账号输入
void creatLinkedList(struct Student *head);//创建链表由管理员输入学生数目和信息
void clearInformation();//清除所有账号信息和学生信息
struct Student*load(struct Student *head);//从文件中读取学生信息
void saveFile(struct Student *head);//保存修改后学生信息到文件
void changeScore(struct Student*head);//修改成绩
void sort(struct Student *head);//学生成绩排序
void deleteNode(struct Student *head);//删除学生信息
void print(struct Student *head);//打印学生信息
void freeNode(struct Student *head);//释放链表
int findNode(struct Student *head);//查找学生信息
void insertNode(struct Student *head);//插入学生信息
int main()
{
    struct Student *head=(struct Student *)malloc(sizeof(struct Student));
    load(head);//从文件中读取学生信息
    system("cls");




    system("color 0a");
    launchBoundar();//启动界面
    identityView(head);//身份访问
    freeNode(head); //释放链表
    return 0;
}


void creatLinkedList(struct Student *head)
{
    struct Student *curNode,*newNode;
    int index=0;
    int studentNum;
    printf("请输入学生数目:");
    scanf("%d",&studentNum);
    printf("请输入学生信息(姓名，学号，数学，英语，c语言)：\n");
    curNode=head;
    while(index<studentNum)
    {

        newNode=(struct Student *)malloc(sizeof(struct Student));
        newNode->nextNode=NULL;
        curNode->nextNode=newNode;
        curNode=newNode;
        scanf("%s %d %d %d %d",newNode->name,&newNode->num,&newNode->mScore,&newNode->eScore,&newNode->cScore);
        index++;
    }
    saveFile(head);
}
void print(struct Student *head)
{
    struct Student *curNode=head;

    printf("姓名    学号    数学    英语    c语言 ：\n ");
    while(curNode->nextNode!=NULL)
    {
        curNode=curNode->nextNode;
        printf("%-8s %-8d %-8d %-8d %-8d\n",curNode->name,curNode->num,curNode->mScore,curNode->eScore,curNode->cScore);
    }

}

//释放链表节点
void freeNode(struct Student *head)
{
    struct Student *curNode;
    curNode=head;


    while(curNode)
    {
        struct Student *temp;
        temp=curNode;
        curNode=curNode->nextNode;
        free(temp);
    }
}

//删除学生信息
void deleteNode(struct Student *head)
{
    int numDelete,i=0;
    printf("请输入删除学生学号:");
    scanf("%d",&numDelete);
    struct Student *deleteNode;
    struct Student *curNode;
    deleteNode=(struct Student*)malloc(sizeof(struct Student));
    curNode=head;
    while(curNode->nextNode!=NULL)
    {
        if(curNode->nextNode->num==numDelete)
        {
            deleteNode=curNode->nextNode;
            curNode->nextNode=deleteNode->nextNode;
            free(deleteNode);
            i++;

            break;
        }
        curNode=curNode->nextNode;
    }
    if(i==0)
    {
        printf("该学号不存在    \n");
    }
    else
    {
        printf("成功删除该学生信息\n");
    }
    saveFile(head);



}


//查找学生信息
int findNode(struct Student *head)
{
    int findNum;
    printf("请输入所查询学生学号:\n");
    scanf("%d",&findNum);
    struct Student *curNode;
    curNode=head->nextNode;
    while(curNode!=NULL)
    {
        if(curNode->num==findNum)
        {
            printf("%s %d %d %d %d\n",curNode->name,curNode->num,curNode->mScore,curNode->eScore,curNode->cScore);

            break;
        }
        curNode=curNode->nextNode;

    }
    if(curNode!=NULL)
    {

        return 1;
    }
    else

    {
        printf("该学生学号不存在\n");
        return 0;
    }

}

//在某学生后面增加学生信息
void insertNode(struct Student *head)
{
    struct Student *pNew;
    struct Student *curNode;
    while(1)
    {
        int numInsert,j=0;
        printf("请输入插入位置的学生学号:");
        scanf("%d",&numInsert);
        printf("请输入插入学生信息(姓名 学号 数学 英语 c语言)：\n");
        pNew=(struct Student*)malloc(sizeof(struct Student));
        scanf("%s %d %d %d %d",pNew->name,&pNew->num,&pNew->mScore,&pNew->eScore,&pNew->cScore);
        curNode=head->nextNode;
        while(curNode!=NULL)
        {
            if(curNode->num==pNew->num)
            {

                j++;
            }
            curNode=curNode->nextNode;
        }
        if(j==1)
        {
            printf("所插入的学生学号已存在\n");
            break;
        }
        curNode=head->nextNode;
        while(curNode!=NULL)
        {
            if(curNode->num==numInsert)
            {
                pNew->nextNode=curNode->nextNode;
                curNode->nextNode=pNew;
                printf("成功插入");

                break;
            }
            curNode=curNode->nextNode;
        }
        if(curNode!=NULL)
        {

            break;
        }
        else
        {
            printf("您所插入位置的学生学号不存在\n");
            break;
        }
    }
    saveFile(head);
}


void changeScore(struct Student*head)
{
    int id,score,i=0;
    struct Student*curNode;
    int choice;
    printf("1.修改数学成绩\n");
    printf("2.修改英语成绩\n");
    printf("3.修改c语言成绩\n");
    scanf("%d",&choice);
    printf("请输入要修改的学生学号\n");
    scanf("%d",&id);//输入要修改的学生学号
    curNode=head->nextNode;
    while(curNode)
    {
        if(curNode->num==id)
        {
            printf("请输入要修改的成绩\n");
            scanf("%d",&score);
            switch(choice)
            {
            case 1:
                curNode->mScore=score;
                break;
            case 2:
                curNode->eScore=score;
                break;
            case 3:
                curNode->cScore=score;
                break;
            }
            i++;
            saveFile(head);
            printf("成功修改成绩\n");
            break;
        }
        curNode=curNode->nextNode;
    }
    if(i==0)
    {
        printf("该学生学号不存在 \n");
        Sleep(2000);
    }

}


void saveFile(struct Student*head);
void sort(struct Student *head)//总成绩排序
{
    int i=0,a[4]= {0},b[4]= {0},j;
    char s[10];
    struct Student*sortNode=(struct Student*)malloc(sizeof(struct Student));
    int len=0,m,n;
    int choice;
    printf("1.总成绩排序\n");
    printf("2.数学成绩排序\n");
    printf("3.英语成绩排序\n");
    printf("4.c语言成绩排序\n");
    printf("5.按学号排序\n");
    printf("否则不排序\n");
    printf("请输入您的选择:");
    scanf("%d",&choice);
    struct Student *p,*q,*h,*curNode;
    curNode=head->nextNode;
    while(curNode)
    {
        len++;
        curNode=curNode->nextNode;
    }
    while(len--)
    {
        p=head->nextNode;
        q=p->nextNode;
        h=head;
        for(i=0; i<len&&q!=NULL; ++i)
        {
            if(choice==1)
            {
                m=p->mScore+p->cScore+p->eScore;
                n=q->mScore+q->cScore+q->eScore;
            }
            else if(choice==2)
            {
                m=p->mScore;
                n=q->mScore;
            }
            else  if(choice==3)
            {
                m=p->eScore;
                n=q->eScore;
            }
            else if(choice==4)
            {
                m=p->cScore;
                n=q->cScore;
            }
            else if(choice==5)
            {
                m=q->num;
                n=p->num;
            }
            else
            {
                break;
            }
            if(m<n)
            {
                h->nextNode=q;
                p->nextNode=q->nextNode;
                q->nextNode=p;
                h=q;
                q=p->nextNode;
            }
            else
            {
                h=h->nextNode;
                p=p->nextNode;
                q=q->nextNode;
            }
        }
    }
    curNode=head->nextNode;
    i=1;
    while(curNode!=NULL)
    {
        printf("%d:%s %d %d %d %d\n",i,curNode->name,curNode->num,curNode->mScore,curNode->eScore,curNode->cScore);
        curNode=curNode->nextNode;
        i++;
    }
}

void saveFile(struct Student *head)//把修改后学生信息保存到文件中
{
    FILE *fp;
    struct Student *curNode;
    if((fp=fopen(p3,"w"))==NULL)
    {
        printf("打开文件失败");
        getchar();
        exit(1);
    }
    rewind(fp);
    curNode=head->nextNode;
    while(curNode!=NULL)
    {
        fprintf(fp,"%s %d %d %d %d\n",curNode->name,curNode->num,curNode->mScore,curNode->eScore,curNode->cScore);
        curNode=curNode->nextNode;
    }
    //printf("修改后学生信息已经成功保存文件s.txt中！\n");
    fclose(fp);
}
struct Student*load(struct Student *head)//从文件中读取学生信息
{
    struct Student *curNode;
    int i=0;
    FILE *fp;
    if((fp=fopen(p3,"r"))==NULL)
    {
        printf("打开文件失败");
        getchar();
    }
    head->nextNode=NULL;
    curNode=head;
    struct Student *newNode;
    int a;
    while(1)
    {

        newNode=(struct Student*)malloc(sizeof(struct Student));
        newNode->nextNode=NULL;
        curNode->nextNode=newNode;
        curNode=newNode;

        a=fscanf(fp,"%s%d%d%d%d\n",newNode->name,&newNode->num,&newNode->mScore,&newNode->eScore,&newNode->cScore);
        i++;
        printf("已经读入数据%d条\n",i);
        if(feof(fp))
        {
            curNode=NULL;
            break;
        }
    }
    fclose(fp);
    return head;
}


void passWords(char *p)//登录账户密码的输入（隐藏密码）
{
    char  s1[17],s2[17];
    FILE *fp;
    char  user_name[17];
    int i=0;
    char  password[17];
    if((fp=fopen(p,"r+"))==NULL)
    {
        printf("打开文件失败\n");
        exit(1);
    }
    fscanf(fp,"%s %s",s1,s2);
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",s1,s2);

    }
    fclose(fp);
    while(1)
    {
        if((fp=fopen(p,"r+"))==NULL)
        {
            printf("打开文件失败\n");
            exit(1);
        }

        fscanf(fp,"%s %s",s1,s2);
        printf("请输入您的用户名：\n");
        scanf("%s",user_name);

        printf("请输入您的密码：\n");


        char c;
        int j=0;
        while((c=getch())!='\r')//用getch无回显输入字符
        {
            if(c=='\b')//当输入退格键时
            {
                putch('\b');//putch无回显输出\b，这时光标移到了上一位

                putch(' ');//用空格覆盖
                putch('\b');//再退一位
                if(j>0)
                    j=j-2;//退两位，因为循环要再加1

                continue;
            }
            password[j++]=c;
            putchar('*');
        }
        password[j]='\0';
        printf("\n");
        int k;
        printf("正在登录，请稍后...\n");
        for(k=0; k<6; k++)
        {
            printf("★");
            Sleep(200);
        }
        system("cls");
        printf("\n");
        if((strcmp(s1,user_name)==0&&strcmp(s2,password)==0))
        {

            printf("登录成功");
            i++;
            break;
        }

        while(!feof(fp))
        {
            fscanf(fp,"%s %s",s1,s2);
            if((strcmp(s1,user_name)==0&&strcmp(s2,password)==0))
            {
                printf("登录成功");
                i++;
                break;
            }

        }
        if(i==0)
        {
            fclose(fp);
            printf("用户名或密码错误，请重新输入\n");
            continue;
        }
        if(i==1)
        {
            fclose(fp);
            break;
        }
    }
}


void regist(char *p)//账号注册
{
    char users[17];
    FILE *fp;
    int i=0;
    char s1[17],s2[17];
    char password1[17];
    char password2[17];
    while(1)
    {
        i=0;
        printf("用户名:");
        scanf("%s",users);
        printf("密码:");
        scanf("%s",password1);
        printf("确认密码:");
        scanf("%s",password2);
        if((fp=fopen(p,"r"))==NULL)
        {
            printf("打开文件失败\n");
            exit(1);
        }
        fscanf(fp,"%s %s",s1,s2);
        if(strcmp(s1,users)==0)
        {
            printf("该用户已存在\n");
            i++;
            break;
        }
        while(!feof(fp))
        {
            fscanf(fp,"%s %s",s1,s2);
            if(strcmp(s1,users)==0)
            {
                printf("该用户已存在\n");
                i++;
                fclose(fp);
                break;
            }
        }
        if(i==1)
            break;
        if(strcmp(password1,password2)==0)
        {
            if((fp=fopen(p,"a+"))==NULL)
            {
                printf("打开文件失败\n");
                exit(1);
            }
            fprintf(fp,"%s %s\n",users,password1);
            printf("注册成功！\n");
            Sleep(2000);
            system("cls");
            fclose(fp);
            break;
        }
        else
        {
            printf("两次密码不一致,请重新输入\n");
            //Sleep(2000);
            continue;
        }
    }
}


void clearInformation()
{
    FILE *fp1,*fp2,*fp;
    if((fp2=fopen(p2,"w"))==NULL)
    {
        printf("打开文件失败\n");
        exit(1);
    }
    if((fp1=fopen(p1,"w"))==NULL)
    {
        printf("打开文件失败\n");
        exit(1);
    }
    if((fp=fopen(p3,"w"))==NULL)
    {
        printf("打开文件失败\n");
        exit(1);
    }
}


void teachFunctionMenu();
void teachLogin(struct Student*head)
{
    passWords(p1);
    Sleep(1000);
    system("cls");
    int choice;
    while(1)
    {
        teachFunctionMenu();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertNode(head);//增加学生信息
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            deleteNode(head);//删除学生信息
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            sort(head);//对学生成绩排序
            anyKeyGoOn();
            system("cls");
            continue;
        case 4:
            print(head);//打印学生成绩
            anyKeyGoOn();
            system("cls");
            continue;
        case 5:
            changeScore(head);//修改学生成绩
            anyKeyGoOn();
            system("cls");
            continue;
        case 6:
            break;
        default:
            printf("\t\t\t\t输入错误,请重新输入\n");
            Sleep(2000);
            continue;
        }
        system("cls");
        break;
    }
}


void teachFunctionMenu()
{

    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统教师端  ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.增加学生信息           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    2.删除学生信息           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    3.学生成绩排序           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    4.打印学生成绩           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    5.修改学生成绩           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    6.返回                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void stuFunctionMenu()
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统学生端  ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.查询个人成绩           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    2.查看班级排名           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    3.返回                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void stuLogin(struct Student*head)
{
    passWords(p2);
    Sleep(1000);
    system("cls");
    int choice;
    while(1)
    {
        stuFunctionMenu();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            findNode(head);//增加学生信息
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            sort(head);//删除学生信息
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("输入错误,请重新输入\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        system("cls");
        break;
    }
}

void anyKeyGoOn()
{
    char ch;
    printf("请按任意键继续");
    ch=getch();

}


void change(char *p);
void stuLogin(struct Student *head);
void regist(char *p);
void stuFunction(struct Student*head)
{
    int function;
    while(1)
    {
        printf("\t\t\t\t\t学生端\n");
        Menu2();
        scanf("%d",&function);
        switch(function)
        {
        case 1:

            printf("学生帐号注册\n");
            regist(p2);
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");

            printf("学生帐号登录\n");
            stuLogin(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            system("cls");
            printf("学生修改密码\n");
            stuLogin(head);
            change(p2);
            system("cls");
            continue;
        case 4:
            break;
        default:

            anyKeyGoOn();
            system("cls");
            continue;
        }
        system("cls");
        break;
    }
}


void change(char *p);
void teachLogin(struct Student*head);
void regist(char *p);
void teachFunction(struct Student*head)
{
    int function;
    while(1)
    {
        printf("\t\t\t\t\t教师端\n");
        Menu2();
        scanf("%d",&function);
        switch(function)
        {
        case 1:
            printf("教师帐号注册\n");
            regist(p1);
            system("cls");
            continue;
        case 2:
            system("cls");
            printf("教师帐号登录\n");
            teachLogin(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            printf("教师修改密码\n");
            change(p1);
            anyKeyGoOn();
            system("cls");
            continue;
        case 4:
            continue;
        default:
            printf("输入错误，请您重新输入\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        system("cls");
        break;
    }

}


void Menus()
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统        ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.教师端                 ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    2.学生端                 ┃\n");

    printf("\t\t\t\t┃                             ┃\n");


    printf("\t\t\t\t┃    3.返回                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");


    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void Menus();
void teachFunction(struct Student*head);
void stuFunction(struct Student*head);
void menuAll(struct Student *head)
{

    int function;
    while(1)
    {

        Menus();
        scanf("%d",&function);
        switch(function)
        {

        case 1:
            system("cls");
            teachFunction(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");
            stuFunction(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("输入错误，请重新输入\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        system("cls");
        break;
    }
}


void Menu2()
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统        ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.注册                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    2.登录                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    3.修改密码               ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    4.返回                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void launchBoundar()
{
    printf("\t\t\t\t***********************************\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t*   欢迎使用学生成绩管理系统      *\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t*   系统正在启动，请稍后          *\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t*   >>>>>>>>>>>>>>>>>>>>          *\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t***********************************\n");


    Sleep(2000);
    system("cls");
}


void identityView(struct Student*head)
{
    int identity;
    while(1)
    {
        mainMenu();
        scanf("%d",&identity);
        switch(identity)
        {
        case 1:
            system("cls");
            manger(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");
            menuAll(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("输入错误\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        system("cls");
        break;
    }
}


void manger(struct Student*head)
{
    char users[10],passWd[10];
    char s1[10],s2[10];
    int choice;
    while(1)
    {
        printf("输入用户名和密码\n");
        scanf("%s  %s",s1,s2);
        if(strcmp(s1,mangers)==0&&strcmp(s2,mangerPassword)==0)
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("用户名或密码错误\n");
            continue;
        }
    }
    while(1)
    {
        mangerMenus();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            clearInformation();//清空系统
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");
            creatLinkedList(head);//加入学生信息
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("输入错误\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
}


void mainMenu()
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统        ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.管理员访问             ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    2.用户访问               ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    3.退出系统               ┃\n");
    printf("\t\t\t\t┃                             ┃\n");


    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void mangerMenus()
{

    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃     学生成绩管理系统        ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    1.清空系统               ┃\n");
    printf("\t\t\t\t┃                             ┃\n");

    printf("\t\t\t\t┃    2.加入学生信息           ┃\n");
    printf("\t\t\t\t┃                             ┃\n");
    printf("\t\t\t\t┃    3.返回                   ┃\n");
    printf("\t\t\t\t┃                             ┃\n");


    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


void change(char *p)//修改密码
{

    char user[16],password[16],changeWord[16];
    char s1[16],s2[16];
    int i=0,j=0;
    FILE* fp,*fp0;
    int len;
    while(1)
    {
        i=j=0;
        if((fp=fopen(p,"r+"))==NULL)
        {
            printf("打开文件失败\n");
            exit(1);
        }
        if((fp0=fopen("zxc.txt","w+"))==NULL)
        {
            printf("打开文件失败\n");
            exit(1);
        }
        printf("用户名:");
        scanf("%s",user);
        printf("密码:");
        scanf("%s",password);
        printf("新密码:");
        scanf("%s",changeWord);
        if(strcmp(password,changeWord)==0)
        {
            printf("新密码不能与旧密码相同\n");
            break;
        }
        fscanf(fp,"%s %s",s1,s2);
        while(!feof(fp))
        {
            if(strcmp(s1,user)==0&&strcmp(s2,password)==0)
            {
                fprintf(fp0,"%s %s\n",s1,changeWord);
                i++;
            }
            else
            {
                fprintf(fp0,"%s %s\n",s1,s2);
            }
            fscanf(fp,"%s %s",s1,s2);
        }
        rewind(fp);
        rewind(fp0);
        fscanf(fp0,"%s %s",s1,s2);
        while(!feof(fp0))
        {
            fprintf(fp,"%s %s\n",s1,s2);
            fscanf(fp0,"%s %s",s1,s2);
        }
        if(i==1)
        {
            printf("修改成功\n");
            fclose(fp);
            fclose(fp0);
            break;
        }
        else
        {
            printf("用户名或密码错误\n");
            Sleep(2000);
            fclose(fp);
            fclose(fp0);
            system("cls");
            break;
        }
    }
}




