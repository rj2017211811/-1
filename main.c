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

char *p1="teacher.txt";//�洢��ʦ�˺�
char *p2="student.txt";//�洢ѧ���˺�
char *p3="s.txt";//�洢ѧ����Ϣ
char mangers[10]="zhangbin";
char mangerPassword[10]="123456";//����Ա�˺�
void newMenu();
void launchBoundar();//��������
void menuAll(struct Student *head);//���ܲ˵�
void menus();//���ܽ���
void Menu2();//��¼ע�����
void mangerMenu();//����Ա�˵�
void stuFunctionMenu();//ѧ�����ܲ˵�
void loginMenu();//��¼�˵�
void mainMenu();//���˵�
void mangerMenus();//����Ա�˵�

void anyKeyGoOn();//�����������
void change(char *p);//�޸�����
void identityView(struct Student*head);//�Ժ���ݷ���
void manger(struct Student*head);//����Ա����
void teachFunction(struct Student*head);//��ʦ����
void stuFunction(struct Student*head);//ѧ������
void regist(char *p);//ע��
void login(struct Student *head);//��¼
void stuLogin(struct Student*head);//ѧ����¼
void teachLogin(struct Student*head);//��ʦ��¼
void passWords(char *p);//�˺�����
void creatLinkedList(struct Student *head);//���������ɹ���Ա����ѧ����Ŀ����Ϣ
void clearInformation();//��������˺���Ϣ��ѧ����Ϣ
struct Student*load(struct Student *head);//���ļ��ж�ȡѧ����Ϣ
void saveFile(struct Student *head);//�����޸ĺ�ѧ����Ϣ���ļ�
void changeScore(struct Student*head);//�޸ĳɼ�
void sort(struct Student *head);//ѧ���ɼ�����
void deleteNode(struct Student *head);//ɾ��ѧ����Ϣ
void print(struct Student *head);//��ӡѧ����Ϣ
void freeNode(struct Student *head);//�ͷ�����
int findNode(struct Student *head);//����ѧ����Ϣ
void insertNode(struct Student *head);//����ѧ����Ϣ
int main()
{
    struct Student *head=(struct Student *)malloc(sizeof(struct Student));
    load(head);//���ļ��ж�ȡѧ����Ϣ
    system("cls");




    system("color 0a");
    launchBoundar();//��������
    identityView(head);//��ݷ���
    freeNode(head); //�ͷ�����
    return 0;
}


void creatLinkedList(struct Student *head)
{
    struct Student *curNode,*newNode;
    int index=0;
    int studentNum;
    printf("������ѧ����Ŀ:");
    scanf("%d",&studentNum);
    printf("������ѧ����Ϣ(������ѧ�ţ���ѧ��Ӣ�c����)��\n");
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

    printf("����    ѧ��    ��ѧ    Ӣ��    c���� ��\n ");
    while(curNode->nextNode!=NULL)
    {
        curNode=curNode->nextNode;
        printf("%-8s %-8d %-8d %-8d %-8d\n",curNode->name,curNode->num,curNode->mScore,curNode->eScore,curNode->cScore);
    }

}

//�ͷ�����ڵ�
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

//ɾ��ѧ����Ϣ
void deleteNode(struct Student *head)
{
    int numDelete,i=0;
    printf("������ɾ��ѧ��ѧ��:");
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
        printf("��ѧ�Ų�����    \n");
    }
    else
    {
        printf("�ɹ�ɾ����ѧ����Ϣ\n");
    }
    saveFile(head);



}


//����ѧ����Ϣ
int findNode(struct Student *head)
{
    int findNum;
    printf("����������ѯѧ��ѧ��:\n");
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
        printf("��ѧ��ѧ�Ų�����\n");
        return 0;
    }

}

//��ĳѧ����������ѧ����Ϣ
void insertNode(struct Student *head)
{
    struct Student *pNew;
    struct Student *curNode;
    while(1)
    {
        int numInsert,j=0;
        printf("���������λ�õ�ѧ��ѧ��:");
        scanf("%d",&numInsert);
        printf("���������ѧ����Ϣ(���� ѧ�� ��ѧ Ӣ�� c����)��\n");
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
            printf("�������ѧ��ѧ���Ѵ���\n");
            break;
        }
        curNode=head->nextNode;
        while(curNode!=NULL)
        {
            if(curNode->num==numInsert)
            {
                pNew->nextNode=curNode->nextNode;
                curNode->nextNode=pNew;
                printf("�ɹ�����");

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
            printf("��������λ�õ�ѧ��ѧ�Ų�����\n");
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
    printf("1.�޸���ѧ�ɼ�\n");
    printf("2.�޸�Ӣ��ɼ�\n");
    printf("3.�޸�c���Գɼ�\n");
    scanf("%d",&choice);
    printf("������Ҫ�޸ĵ�ѧ��ѧ��\n");
    scanf("%d",&id);//����Ҫ�޸ĵ�ѧ��ѧ��
    curNode=head->nextNode;
    while(curNode)
    {
        if(curNode->num==id)
        {
            printf("������Ҫ�޸ĵĳɼ�\n");
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
            printf("�ɹ��޸ĳɼ�\n");
            break;
        }
        curNode=curNode->nextNode;
    }
    if(i==0)
    {
        printf("��ѧ��ѧ�Ų����� \n");
        Sleep(2000);
    }

}


void saveFile(struct Student*head);
void sort(struct Student *head)//�ܳɼ�����
{
    int i=0,a[4]= {0},b[4]= {0},j;
    char s[10];
    struct Student*sortNode=(struct Student*)malloc(sizeof(struct Student));
    int len=0,m,n;
    int choice;
    printf("1.�ܳɼ�����\n");
    printf("2.��ѧ�ɼ�����\n");
    printf("3.Ӣ��ɼ�����\n");
    printf("4.c���Գɼ�����\n");
    printf("5.��ѧ������\n");
    printf("��������\n");
    printf("����������ѡ��:");
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

void saveFile(struct Student *head)//���޸ĺ�ѧ����Ϣ���浽�ļ���
{
    FILE *fp;
    struct Student *curNode;
    if((fp=fopen(p3,"w"))==NULL)
    {
        printf("���ļ�ʧ��");
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
    //printf("�޸ĺ�ѧ����Ϣ�Ѿ��ɹ������ļ�s.txt�У�\n");
    fclose(fp);
}
struct Student*load(struct Student *head)//���ļ��ж�ȡѧ����Ϣ
{
    struct Student *curNode;
    int i=0;
    FILE *fp;
    if((fp=fopen(p3,"r"))==NULL)
    {
        printf("���ļ�ʧ��");
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
        printf("�Ѿ���������%d��\n",i);
        if(feof(fp))
        {
            curNode=NULL;
            break;
        }
    }
    fclose(fp);
    return head;
}


void passWords(char *p)//��¼�˻���������루�������룩
{
    char  s1[17],s2[17];
    FILE *fp;
    char  user_name[17];
    int i=0;
    char  password[17];
    if((fp=fopen(p,"r+"))==NULL)
    {
        printf("���ļ�ʧ��\n");
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
            printf("���ļ�ʧ��\n");
            exit(1);
        }

        fscanf(fp,"%s %s",s1,s2);
        printf("�����������û�����\n");
        scanf("%s",user_name);

        printf("�������������룺\n");


        char c;
        int j=0;
        while((c=getch())!='\r')//��getch�޻��������ַ�
        {
            if(c=='\b')//�������˸��ʱ
            {
                putch('\b');//putch�޻������\b����ʱ����Ƶ�����һλ

                putch(' ');//�ÿո񸲸�
                putch('\b');//����һλ
                if(j>0)
                    j=j-2;//����λ����Ϊѭ��Ҫ�ټ�1

                continue;
            }
            password[j++]=c;
            putchar('*');
        }
        password[j]='\0';
        printf("\n");
        int k;
        printf("���ڵ�¼�����Ժ�...\n");
        for(k=0; k<6; k++)
        {
            printf("��");
            Sleep(200);
        }
        system("cls");
        printf("\n");
        if((strcmp(s1,user_name)==0&&strcmp(s2,password)==0))
        {

            printf("��¼�ɹ�");
            i++;
            break;
        }

        while(!feof(fp))
        {
            fscanf(fp,"%s %s",s1,s2);
            if((strcmp(s1,user_name)==0&&strcmp(s2,password)==0))
            {
                printf("��¼�ɹ�");
                i++;
                break;
            }

        }
        if(i==0)
        {
            fclose(fp);
            printf("�û����������������������\n");
            continue;
        }
        if(i==1)
        {
            fclose(fp);
            break;
        }
    }
}


void regist(char *p)//�˺�ע��
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
        printf("�û���:");
        scanf("%s",users);
        printf("����:");
        scanf("%s",password1);
        printf("ȷ������:");
        scanf("%s",password2);
        if((fp=fopen(p,"r"))==NULL)
        {
            printf("���ļ�ʧ��\n");
            exit(1);
        }
        fscanf(fp,"%s %s",s1,s2);
        if(strcmp(s1,users)==0)
        {
            printf("���û��Ѵ���\n");
            i++;
            break;
        }
        while(!feof(fp))
        {
            fscanf(fp,"%s %s",s1,s2);
            if(strcmp(s1,users)==0)
            {
                printf("���û��Ѵ���\n");
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
                printf("���ļ�ʧ��\n");
                exit(1);
            }
            fprintf(fp,"%s %s\n",users,password1);
            printf("ע��ɹ���\n");
            Sleep(2000);
            system("cls");
            fclose(fp);
            break;
        }
        else
        {
            printf("�������벻һ��,����������\n");
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
        printf("���ļ�ʧ��\n");
        exit(1);
    }
    if((fp1=fopen(p1,"w"))==NULL)
    {
        printf("���ļ�ʧ��\n");
        exit(1);
    }
    if((fp=fopen(p3,"w"))==NULL)
    {
        printf("���ļ�ʧ��\n");
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
            insertNode(head);//����ѧ����Ϣ
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            deleteNode(head);//ɾ��ѧ����Ϣ
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            sort(head);//��ѧ���ɼ�����
            anyKeyGoOn();
            system("cls");
            continue;
        case 4:
            print(head);//��ӡѧ���ɼ�
            anyKeyGoOn();
            system("cls");
            continue;
        case 5:
            changeScore(head);//�޸�ѧ���ɼ�
            anyKeyGoOn();
            system("cls");
            continue;
        case 6:
            break;
        default:
            printf("\t\t\t\t�������,����������\n");
            Sleep(2000);
            continue;
        }
        system("cls");
        break;
    }
}


void teachFunctionMenu()
{

    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳ��ʦ��  ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.����ѧ����Ϣ           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    2.ɾ��ѧ����Ϣ           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    3.ѧ���ɼ�����           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    4.��ӡѧ���ɼ�           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    5.�޸�ѧ���ɼ�           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    6.����                   ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��������������������������������������������������������������\n");
}


void stuFunctionMenu()
{
    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳѧ����  ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.��ѯ���˳ɼ�           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    2.�鿴�༶����           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    3.����                   ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��������������������������������������������������������������\n");
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
            findNode(head);//����ѧ����Ϣ
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            sort(head);//ɾ��ѧ����Ϣ
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("�������,����������\n");
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
    printf("�밴���������");
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
        printf("\t\t\t\t\tѧ����\n");
        Menu2();
        scanf("%d",&function);
        switch(function)
        {
        case 1:

            printf("ѧ���ʺ�ע��\n");
            regist(p2);
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");

            printf("ѧ���ʺŵ�¼\n");
            stuLogin(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            system("cls");
            printf("ѧ���޸�����\n");
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
        printf("\t\t\t\t\t��ʦ��\n");
        Menu2();
        scanf("%d",&function);
        switch(function)
        {
        case 1:
            printf("��ʦ�ʺ�ע��\n");
            regist(p1);
            system("cls");
            continue;
        case 2:
            system("cls");
            printf("��ʦ�ʺŵ�¼\n");
            teachLogin(head);
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            printf("��ʦ�޸�����\n");
            change(p1);
            anyKeyGoOn();
            system("cls");
            continue;
        case 4:
            continue;
        default:
            printf("�������������������\n");
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
    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳ        ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.��ʦ��                 ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    2.ѧ����                 ��\n");

    printf("\t\t\t\t��                             ��\n");


    printf("\t\t\t\t��    3.����                   ��\n");
    printf("\t\t\t\t��                             ��\n");


    printf("\t\t\t\t��������������������������������������������������������������\n");
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
            printf("�����������������\n");
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
    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳ        ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.ע��                   ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    2.��¼                   ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    3.�޸�����               ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    4.����                   ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��������������������������������������������������������������\n");
}


void launchBoundar()
{
    printf("\t\t\t\t***********************************\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t*   ��ӭʹ��ѧ���ɼ�����ϵͳ      *\n");
    printf("\t\t\t\t*                                 *\n");
    printf("\t\t\t\t*   ϵͳ�������������Ժ�          *\n");
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
            printf("�������\n");
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
        printf("�����û���������\n");
        scanf("%s  %s",s1,s2);
        if(strcmp(s1,mangers)==0&&strcmp(s2,mangerPassword)==0)
        {
            printf("��¼�ɹ�\n");
            break;
        }
        else
        {
            printf("�û������������\n");
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
            clearInformation();//���ϵͳ
            anyKeyGoOn();
            system("cls");
            continue;
        case 2:
            system("cls");
            creatLinkedList(head);//����ѧ����Ϣ
            anyKeyGoOn();
            system("cls");
            continue;
        case 3:
            break;
        default:
            printf("�������\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        break;
    }
}


void mainMenu()
{
    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳ        ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.����Ա����             ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    2.�û�����               ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    3.�˳�ϵͳ               ��\n");
    printf("\t\t\t\t��                             ��\n");


    printf("\t\t\t\t��������������������������������������������������������������\n");
}


void mangerMenus()
{

    printf("\t\t\t\t��������������������������������������������������������������\n");
    printf("\t\t\t\t��     ѧ���ɼ�����ϵͳ        ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    1.���ϵͳ               ��\n");
    printf("\t\t\t\t��                             ��\n");

    printf("\t\t\t\t��    2.����ѧ����Ϣ           ��\n");
    printf("\t\t\t\t��                             ��\n");
    printf("\t\t\t\t��    3.����                   ��\n");
    printf("\t\t\t\t��                             ��\n");


    printf("\t\t\t\t��������������������������������������������������������������\n");
}


void change(char *p)//�޸�����
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
            printf("���ļ�ʧ��\n");
            exit(1);
        }
        if((fp0=fopen("zxc.txt","w+"))==NULL)
        {
            printf("���ļ�ʧ��\n");
            exit(1);
        }
        printf("�û���:");
        scanf("%s",user);
        printf("����:");
        scanf("%s",password);
        printf("������:");
        scanf("%s",changeWord);
        if(strcmp(password,changeWord)==0)
        {
            printf("�����벻�����������ͬ\n");
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
            printf("�޸ĳɹ�\n");
            fclose(fp);
            fclose(fp0);
            break;
        }
        else
        {
            printf("�û������������\n");
            Sleep(2000);
            fclose(fp);
            fclose(fp0);
            system("cls");
            break;
        }
    }
}




