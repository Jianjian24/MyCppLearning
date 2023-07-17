#include<stdio.h>
#include<conio.h>   //控制输出头文件
#include<string.h>  //函数定义头文件
#include<stdlib.h>  //standard library标准库头文件
#include<math.h>    //包含math库头文件
#include<iostream>  //输入输出流头文件
#include<fstream>  //C++常用文件操作
#define MAXSIZE 40
#define NULL 0
static int num;//定义静态变量num
using namespace std;//定义标识符

typedef struct Infomation{
    char name[20];		  //姓名
	char gender[10];      //性别
	char degree[20];      //学历
	char career[20];      //职业
    char birth[20];		  //出生日期
    char add[20];		  //地址
    int health;			  //是否健在
    char death_date[20];  //死亡日期
}Info;

typedef struct bnode{   //左右孩子和BiTree的定义
    Info person;
    struct bnode *lchild,*rchild;
}BNode,*BiTree;
 
typedef struct{   //循环队列的定义
    BiTree queue[MAXSIZE];
    int front,rear;
}Queue;

void InitQ();				//初始化
void EnQueue();				//入队
void DeQueue();				//出队
int QEmpty();				//判队空
int QFull();				//判队满
void new_left();			//添加左孩子
void new_right();			//添加右孩子
int CreateBiTree();			//创建族谱
void output();				//输出某结点的信息
void level();				//层次遍历家谱图
void show_level();	        //层次遍历家谱的第n层
BiTree Parent();			//找到结点p的双亲并返回
BiTree search_name();		//通过名字找到结点并返回
void search_child();		//找到结点p的孩子存到指针数组child[]中
void search_3generations();	//显示三代的信息
BiTree search_birth();		//通过生日找到结点并返回
void search_birthday();		//输出生日信息
int same_father();	        //判断结点p和q是否是同一个爸爸
void ralationship();		//判断两个人的关系
void add();					//让一个结点拥有孩子
void delete_name();			//删除一个结点和他的孩子们孙子们
void show_family();			//显示家谱
void update();				//修改节点数据
void transport();			//把家谱中所有人的生日传参给二维数组bir[][]
void sort_birth();			//将二维数组升序排序并输出
int NodeCount();			//计算节点的个数
void read();				//文件读取
int read1();				//配合read()函数读取文件
void write();				//保存家谱
void write1();				//配合write()函数保存家谱


void menu();				//显示可选菜单
void home();				//主页


void InitQ(Queue &Q)  //初始化
{
    Q.front=Q.rear=0;
}
 
void EnQueue(Queue &Q,BiTree e)  //入队
{
    Q.rear=(Q.rear+1)%MAXSIZE;
    Q.queue[Q.rear]=e;
}
 
void DeQueue(Queue &Q,BiTree &e)  //出队
{
    Q.front=(Q.front+1)%MAXSIZE;
    e=Q.queue[Q.front];
}
 
int QEmpty(Queue Q)  //判队空
{
    return Q.front==Q.rear;
}
 
int QFull(Queue Q)  //判队满
{
    if((Q.rear+1)%MAXSIZE==Q.front)
	{
		return 1;
	}
    return 0;
}

void new_left(BiTree p,Info info)  //添加左孩子
{
    BiTree q=(BiTree)malloc(sizeof(BNode));
    q->person=info;
    q->lchild=q->rchild=NULL;
    p->lchild=q;
}

void new_right(BiTree p,Info info)  //添加右孩子
{
    BiTree q=(BiTree)malloc(sizeof(BNode));
    q->person=info;
    q->lchild=q->rchild=NULL;
    p->rchild=q;
}

int CreateBiTree(BiTree &T)  //创建家谱
{							//先序创建用二叉链表表示的二叉树，#表示空树
	BiTree q=(BiTree)malloc(sizeof(BNode));
	Info human;
	printf("\n");
	cout<<"请输入姓名：";
	cin>>human.name;
	if (strcmp(human.name,"#")==0)
	{
		T=NULL;   //用#表示二叉树为空！
	}
	else
	{
		cout<<"请输入出生日期(生日格式为####**@@)：";
		cin>>human.birth;
		cout<<"请输入性别(男或女)：";
		cin>>human.gender;
		cout<<"请输入学历：";
		cin>>human.degree;
        cout<<"请输入职业：";
		cin>>human.career;
		cout<<"请输入地址(省份+市区，例:广东广州)：";
		cin>>human.add;
		cout<<"是否健在(健在输入1，死亡输入0)：";
		cin>>human.health;
		if(human.health==0)
		{
			cout<<"死亡日期(死亡日期格式为####**@@)：";
			cin>>human.death_date;
		}
		else strcpy(human.death_date,"仍在世上!");
		if(!(T=new BNode)) 
		{
			return 0;
		}
		T->person=human;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
  return 1;
}

void output(BiTree p)//输出某结点的信息
{
    printf("%-8.10s%-7.8s%7s%11s %9s%14s%7d%17s\n",p->person.name,p->person.birth,p->person.gender,p->person.degree,p->person.career,p->person.add,p->person.health,p->person.death_date);
}

void level(BiTree t) //层次遍历家谱图
{
    BiTree q[40],p;		//BiTree为指针型
    int front,rear; 
    front=rear=0;
	system("cls");
	if(t==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();  //输入字符看不见，按下任意键，会继续执行下面语句。
		return;
	}
    printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
    if(t)
    {
        rear++;
        q[rear]=t;
        while(front!=rear)
        {
            front=(front+1)%40;
            p=q[front];
            output(p);
            if((rear+1)%40!=front && p->lchild!=NULL)
            {
                rear=(rear+1)%40;
                q[rear]=p->lchild;
            }
            if((rear+1)%40!=front && p->rchild!=NULL)
            {
                rear=(rear+1)%40;
                q[rear]=p->rchild;
            }
        }
    }
}

void show_level(BiTree p,int n) //层次遍历家谱的第n层
{
    static int depth=0;
    depth++;
    if(p)
    {
        if(depth==n)
        {
            output(p);
        }
        show_level(p->lchild,n);
        show_level(p->rchild,n);
    }
    depth--;
}

BiTree Parent(BiTree bt,BiTree p)  //找到结点p的双亲并返回
{
    BiTree l_result,r_result;
    if (!bt||bt==p)
	{
		return NULL;
	}
    if (bt->lchild==p||bt->rchild==p)
	{
		return bt;
	}
    else
    {
        l_result=Parent(bt->lchild,p);
        r_result=Parent(bt->rchild,p);
        return l_result?l_result:(r_result?r_result:NULL);
    }
}

BiTree search_name(BiTree bt,char na[])  //通过名字找到结点并返回（通过名字查询家谱成员信息）
{
    BiTree l_result,r_result;
    if(bt==NULL)
	{
		return NULL;
	}
    if(strcmp(bt->person.name,na)==0)
	{
		return bt;
	}
    else
    {
        l_result=search_name(bt->lchild,na);
        r_result=search_name(bt->rchild,na);
        return l_result?l_result:(r_result?r_result:NULL);
    }
	
}

void search_child(BiTree p,BiTree child[])  //找到结点p的孩子存到指针数组child[]中
{
    child[0]=child[1]=NULL;
    if(p->lchild!=NULL)
	{
		child[0]=p->lchild;
	}
    if(p->rchild!=NULL)
	{
		child[1]=p->rchild;
	}  
}

void search_3generations(BiTree bt)  //显示三代的信息
{
    char na[20];
    BiTree parent,node,child[2];
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入你想查找的那个人的姓名：");
    scanf("%s",na);
    node=search_name(bt,na);
	if(node==NULL)
	{
		printf("未找到该成员！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    parent=Parent(bt,node);
	if(parent==NULL)
	{
		printf("未找到该成员父亲！");
	}	
    search_child(node,child);
    printf("\n你查找的这个人的信息为:\n\n");
    printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
    output(node);
	if(parent!=NULL)
	{
		printf("他的父亲结点的信息为：\n");
		output(parent);
	}
    if(child[0]!=NULL)
    {
        printf("他的左孩子的信息为：\n");
        output(child[0]);
    }
     if(child[1]!=NULL)
    {
        printf("他的右孩子的信息为：\n");
        output(child[1]);
    }
	printf("显示完成!\n");
	printf("请按任意键继续！");
	getch();
}

BiTree search_birth(BiTree bt,char bir[])  //通过生日找到结点并返回（通过生日查询家谱成员信息）
{
    BiTree l_result,r_result;
    if(bt==NULL)
	{
		return NULL;
	}
    if(strcmp(bt->person.birth,bir)==0)
	{
		return bt;
	}
    else
    {
        l_result=search_birth(bt->lchild,bir);
        r_result=search_birth(bt->rchild,bir);
        return l_result?l_result:(r_result?r_result:NULL);
    }
}

void search_birthday(BiTree bt)  //输出生日信息
{
    BiTree p;
    char bir[20];
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入你想查找的那个人的生日：\n");
    scanf("%s",bir);
    p=search_birth(bt,bir);
	if(p==NULL)
	{
		printf("未找到该成员：\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("你想查找的那个人的信息为：\n");
    printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
    output(p);
	printf("显示完成！\n");
	printf("请按任意键继续！");
	getch();
}
 
int same_father(BiTree bt,BiTree p,BiTree q)  //判断结点p和q是否为同父，如果是返回1，否则返回0
{
    BiTree f1,f2;
    f1=Parent(bt,p);
    f2=Parent(bt,q);
    if(f1==f2)
	{
		return 1;
	}
    else
	{
		return 0;
	}
}

void ralationship(BiTree bt)   //通过输入两个人信息，判断两个人的关系
{
    char name1[20],name2[20];
    BiTree s1,s2,f1,f2;
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入第一个人的姓名：\n");
    scanf("%s",name1);
    printf("请输入第二个人的姓名：\n");
    scanf("%s",name2);
    s1=search_name(bt,name1);
	if(s1==NULL)
	{
		printf("未找到第一个人！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    s2=search_name(bt,name2);
	if(s2==NULL)
	{
		printf("未找到第二个人！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
	if(strcmp(s1->person.name,s1->person.name)==1)
	{
		printf("输入的是同一个人\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    f1=Parent(bt,s1);
    f2=Parent(bt,s2);
    if(same_father(bt,s1,s2)==1)
	{
        printf("他们是亲兄弟关系！\n");
	}
    else if(same_father(bt,f1,f2)==1)
	{
		printf("他们是堂兄弟关系！\n");
	}
    else if(s1->lchild==s2)
	{
		printf("%s是%s的左孩子\n",s2->person.name,s1->person.name);
	}
    else if(s1->rchild==s2)
	{
		printf("%s是%s右孩子\n",s2->person.name,s1->person.name);
	}
    else if(s2->lchild==s1)
	{
		printf("%s是%s的左孩子\n",s1->person.name,s2->person.name);
	}
    else if(s2->rchild==s1)
	{
        printf("%s是%s的右孩子\n",s1->person.name,s2->person.name);
	}
    else
	{
        printf("两人关系甚微，可能没有亲戚关系！\n");
	}
	printf("显示完成,请按任意键继续！");
	getch();
}

void add(BiTree &bt)   //让一个结点拥有孩子（添加孩子）
{
    char na[20];
    int i;
    BiTree p;
    Info new_child;
	system("cls");  //自动清屏操作
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入你想让其拥有孩子的成员名字：\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("未找到该成员：\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("你是想该成员拥有左孩子或者是右孩子？左孩子请输入1,右孩子请输入2\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            if(p->lchild!=NULL)
            {
                printf("添加失败！该成员已有左孩子！\n");
                break;
            }
            else
            {	
                printf("请输入新孩子的姓名：\n");
                scanf("%s",new_child.name);
                printf("请输入新孩子的出生日期(生日格式为####**@@)：\n");
                scanf("%s",new_child.birth);
				printf("请输入新孩子的性别(男或女)：\n");
                scanf("%s",new_child.gender);
                printf("请输入新孩子的地址：(省份+市区，例:广东广州)\n");
                scanf("%s",new_child.add);
                printf("新孩子健在吗？健在请输入1，去世请输入0：\n");
                scanf("%d",&new_child.health);
                printf("如果新孩子已经去世，请输入死亡日期(死亡日期格式为####**@@)，否则请输入-1：\n");
                scanf("%s",new_child.death_date);
                if(strcmp(new_child.death_date,"-1")==0)
				{
                    strcpy(new_child.death_date,"仍在世上!");
				}
                new_left(p,new_child);
            }
            break;
        case 2:
            if(p->rchild!=NULL)
            {
                printf("添加失败！该成员已有右孩子！\n");
                break;
            }
            else
            {
                printf("请输入新孩子的姓名：\n");
                scanf("%s",new_child.name);
                printf("请输入新孩子的出生日期(生日格式为####**@@)：\n");
                scanf("%s",new_child.birth);
				printf("请输入新孩子的性别(男或女)：\n");
                scanf("%s",new_child.gender);
                printf("请输入新孩子的地址：(省份+市区，例:广东广州)\n");
                scanf("%s",new_child.add);
                printf("新孩子健在吗？健在请输入1，去世请输入0：\n");
                scanf("%d",&new_child.health);
                printf("如果新孩子已经去世，请输入死亡日期(死亡日期格式为####**@@)，否则请输入-1：\n");
                printf("%s",new_child.death_date);
                if(strcmp(new_child.death_date,"-1")==0)
				{
                    strcpy(new_child.death_date,"仍在世上!");
				}
                new_right(p,new_child);
            }
            break;
        default:
            printf("输入有误！\n");
            break;
    }
	printf("添加完成！\n");
	printf("请按任意键继续！");
	getch();
}

void delete_name(BiTree &bt) //删除一个结点并一并删除其子孙
{
    char na[20];
    BiTree p,f;
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入你想删除的成员姓名，删除成员之后，该成员的子孙也将一并删除！\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("未找到该成员：\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    f=Parent(bt,p);
    if(f!=NULL)
    {
        if(f->lchild==p)
        {
            f->lchild=NULL;
            free(p);
        }
        if(f->rchild==p)
        {
            f->rchild=NULL;
            free(p);
        }
    }
    else
    {
        bt=NULL;
    }
	printf("删除完成！\n");
	printf("请按任意键继续！");
	getch();
}
 
void show_family(BiTree bt) //显示家谱
{
    Queue Q1,Q2;
    int i=0;
    BiTree e;
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    InitQ(Q1);		//对Q1初始化
    InitQ(Q2);		//对Q2初始化
    if(bt!=NULL)
    {
        EnQueue(Q1,bt);			//入队
        while(!QEmpty(Q1))		//判断队空
        {
            while(!QEmpty(Q1))		//判断队空
            { 
                DeQueue(Q1,e);		//出队
                EnQueue(Q2,e);		//入队
            }
            i++;
            if(i==1)
			{
                printf("第%d代：                                ",i);  //显示家谱树
			}
            if(i==2)
			{
                printf("第%d代：                           ",i);
			}
            if(i==3)   
			{
                printf("第%d代：                     ",i);
			}
            if(i==4)
			{
                printf("第%d代：               ",i);
			}
            if(i==5)
			{
                printf("第%d代：          ",i);
			}
			if(i==6)
			{
                printf("第%d代：     ",i);
			}
			if(i==7)
			{
                printf("第%d代： ",i);
			}
            while(!QEmpty(Q2))
            {
                DeQueue(Q2,e);		//出队
                printf("%s ",e->person.name);
                if(!QFull(Q1)&&e->lchild!=NULL)
				{
                    EnQueue(Q1,e->lchild);		//入队
				}
                if(!QFull(Q1)&&e->rchild!=NULL)
				{
                    EnQueue(Q1,e->rchild);		//入队
				}
            }
            puts("");
        }
    }
	printf("显示完成！\n");
	printf("请按任意键继续！");
	getch();
}
 
void update(BiTree bt)		//修改成员
{
    char na[20];
    BiTree p;
	system("cls");
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入你想修改成员的姓名：\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("未找到该成员:\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
    printf("请输入修改过后的姓名：\n");
    scanf("%s",p->person.name);
    printf("请输入修改后的出生日期(生日格式为####**@@)：\n");
    scanf("%s",p->person.birth);
    printf("请输入修改后的性别(男或女)：\n");
    scanf("%s",p->person.gender);
    printf("请输入修改过后的住址：(省份+市区，例:广东广州)\n");
    scanf("%s",p->person.add);
    printf("修改后该成员是否健在，健在请输入1，已经去世请输入0：\n");
    scanf("%d",&p->person.health);
    printf("如果修改后该成员已经死亡，请输入死亡日期(死亡日期格式为####**@@)，否则请输入-1：\n");
    scanf("%s",p->person.death_date);
    if(strcmp(p->person.death_date,"-1")==0)
	{
        strcpy(p->person.death_date,"仍在世上!");
	}
	printf("修改完成！\n");
	printf("请按任意键继续！");
	getch();
}
 
void transport(BiTree bt,char bir[][20],int &x)  //把家谱中所有人的生日数值赋给二维数组bir[][]
{
    if(bt)
    {
        strcpy(bir[x++],bt->person.birth);
        transport(bt->lchild,bir,x);
        transport(bt->rchild,bir,x);
    }
}
 
void sort_birth(BiTree bt,char bir[][20],int n)//将二维数组bir[][]升序排序并输出
{
    char t[20];
    int i,j;
    BiTree p;
	system("cls");
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(bir[i],bir[j])>0)
            {
                strcpy(t,bir[i]);
                strcpy(bir[i],bir[j]);
                strcpy(bir[j],t);
            }
	printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
    for(i=0;i<n;i++)
    {
        p=search_birth(bt,bir[i]);
        output(p);
    }
    printf("排序完成!\n");
	printf("请按任意键继续！");
	getch();
}
 

int NodeCount(BiTree bt)  //计算节点的个数
{
	if(bt==NULL) 
	{
		return 0;
	}
	else 
	{
		return NodeCount(bt->lchild)+NodeCount(bt->rchild)+1;
	}
}

int read1(BiTree &bt,FILE *fp)  //配合read()进行文件读取
{
	bt=(BiTree)malloc(sizeof(BNode));
	fread(&bt->person,sizeof(Info),1,fp);
	if (strcmp(bt->person.name,"#")==0)
	{
		free(bt);
		bt=NULL; 
	}
	else{
			output(bt);
			read1(bt->lchild,fp);
			read1(bt->rchild,fp);
	}
	return 1;
}

void read(BiTree &bt)  //文件读取
{
	system("cls");
	FILE *fp;
	fp=fopen("家谱成员文件.txt","r");  //打开文件
    printf("从文件里读出来的信息是：\n");
    printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
    read1(bt,fp);
    fclose(fp);
	printf("读取成功！\n");
	printf("请按任意键继续！");
	getch();
}

void write1(BiTree &bt,FILE *fp)		//配合write()进行家谱保存
{
	Info p={"#"};
	if(bt&&num>0)
	{
		fwrite(&bt->person,sizeof(Info),1,fp);
		num--;
		write1(bt->lchild,fp);
		write1(bt->rchild,fp);
	}
	else fwrite(&p,sizeof(Info),1,fp);
}

void write(BiTree &bt)		//保存族谱
{
	int i;
	FILE *fp;
	if(bt==NULL)
	{
		printf("未输入成员信息！\n");
		printf("请按任意键继续！");
		getch();
		return;
	}
	system("cls");
	num=NodeCount(bt);
	fp=fopen("家谱成员文件.txt","wb");
    write1(bt,fp);
    fclose(fp);
    printf("保存成功！\n");
	printf("请按任意键继续！");
	getch();
}

void menu()
{	
	printf("┃**计科3班 梁宏轩 202110089205****************************┃\n");
	printf("┃******************欢迎使用家谱管理系统！*****************┃\n");
	printf("┃*                   1.读取家谱                          *┃\n");
    printf("┃*                   2.显示家谱                          *┃\n");
    printf("┃*                   3.层次遍历家谱                      *┃\n");
    printf("┃*                   4.显示第n代人的信息                 *┃\n");
    printf("┃*                   5.按姓名输出成员三代信息            *┃\n");
    printf("┃*                   6.按出生日期查询成员名单            *┃\n");
    printf("┃*                   7.确定两人关系                      *┃\n");
    printf("┃*                   8.给成员添加孩子                    *┃\n");
    printf("┃*                   9.删除某成员                        *┃\n");
    printf("┃*                   10.修改某成员信息                   *┃\n");
    printf("┃*                   11.家谱排序                         *┃\n");
	printf("┃*                   12.创建家谱                         *┃\n");
	printf("┃*                   13.保存家谱                         *┃\n");
    printf("┃*                   14.退出系统                         *┃\n");
	printf("┃*******************请输入数字选项:***********************┃\n");
}
void home(BiTree &bt)
{
	int i,j,n,x=0;
    char bir[60][20];
	do
	{
	    system("cls");
	    fflush(stdin);
	    menu(); //输出菜单页面
        scanf("%d",&i);
		switch(i)
		{
		    case 1:
				{
			        read(bt);
                    break;
				}
            case 2:
			    show_family(bt);
                break;
            case 3:
                level(bt);
			    printf("显示完成,请按任意键继续!");
		    	getch();
                break;
            case 4:
			    system("cls");
			    if(bt==NULL)
				{
			    	printf("未输入成员信息！\n");
			    	printf("请按任意键继续！");
			    	getch();
				}
			    else
				{
			    	printf("你想查找第几代的信息？\n");
			    	scanf("%d",&n);
			    	printf("姓名    出生日期     性别     学历      职业      地址       健在否      死亡日期\n");
			    	show_level(bt,n);
			    	printf("已显示第%d代的信息,请按任意键继续!",n);
			    	getch();
			    	break;
				}
            case 5:
                search_3generations(bt);
                break;
            case 6:
                search_birthday(bt);
                break;
            case 7:
                ralationship(bt);
                break;
            case 8:
                add(bt);
                break;
            case 9:
                delete_name(bt);
                break;
            case 10:
                update(bt);
                break;
            case 11:
		    	x=0;
		    	if(bt==NULL)
				{
		    		printf("未输入成员信息！\n");
		    		printf("请按任意键继续！");
		    		getch();
				}	
                else 
				{
		    		transport(bt,bir,x);
		    		sort_birth(bt,bir,x);
				}
                break;
		    case 12:
		    	system("cls");
		    	printf("欲想退出，请多次输入#，直到显示创建成功为止!\n");
                CreateBiTree(bt);
		    	printf("创建成功,请按任意键继续!\n");
		    	printf("记得保存!!!!!");
		    	getch();
                break;
	    	case 13:
				{
		    		write(bt);
                    break;
				}
            case 14:
                printf("感谢你的使用，下次再见！\n");
                exit(0);
                default:
                printf("输入有误，请重新输入！\n");
		    	getch();
                break;
		}
	}
	while(1);	
}

int main()
{
	getch();
    BiTree bt=NULL;
	printf("\n\n");
	printf("\t┃**计科3班 梁宏轩 202110089205***********************************┃\n");
	printf("\t┃****************************************************************┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃**                    欢迎使用家谱管理系统                    **┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃**                                                            **┃\n");
	printf("\t┃****************************************************************┃\n");
	printf("\t┃***********************************计科3班 梁宏轩 202110089205**┃\n");
	getch();
    home(bt);  //调用home()函数;
	return 1;
}
