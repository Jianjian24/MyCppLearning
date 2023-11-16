#include<stdio.h>
#include<conio.h>   //�������ͷ�ļ�
#include<string.h>  //��������ͷ�ļ�
#include<stdlib.h>  //standard library��׼��ͷ�ļ�
#include<math.h>    //����math��ͷ�ļ�
#include<iostream>  //���������ͷ�ļ�
#include<fstream>  //C++�����ļ�����
#define MAXSIZE 40
#define NULL 0
static int num;//���徲̬����num
using namespace std;//�����ʶ��

typedef struct Infomation{
    char name[20];		  //����
	char gender[10];      //�Ա�
	char degree[20];      //ѧ��
	char career[20];      //ְҵ
    char birth[20];		  //��������
    char add[20];		  //��ַ
    int health;			  //�Ƿ���
    char death_date[20];  //��������
}Info;

typedef struct bnode{   //���Һ��Ӻ�BiTree�Ķ���
    Info person;
    struct bnode *lchild,*rchild;
}BNode,*BiTree;
 
typedef struct{   //ѭ�����еĶ���
    BiTree queue[MAXSIZE];
    int front,rear;
}Queue;

void InitQ();				//��ʼ��
void EnQueue();				//���
void DeQueue();				//����
int QEmpty();				//�жӿ�
int QFull();				//�ж���
void new_left();			//�������
void new_right();			//����Һ���
int CreateBiTree();			//��������
void output();				//���ĳ������Ϣ
void level();				//��α�������ͼ
void show_level();	        //��α������׵ĵ�n��
BiTree Parent();			//�ҵ����p��˫�ײ�����
BiTree search_name();		//ͨ�������ҵ���㲢����
void search_child();		//�ҵ����p�ĺ��Ӵ浽ָ������child[]��
void search_3generations();	//��ʾ��������Ϣ
BiTree search_birth();		//ͨ�������ҵ���㲢����
void search_birthday();		//���������Ϣ
int same_father();	        //�жϽ��p��q�Ƿ���ͬһ���ְ�
void ralationship();		//�ж������˵Ĺ�ϵ
void add();					//��һ�����ӵ�к���
void delete_name();			//ɾ��һ���������ĺ�����������
void show_family();			//��ʾ����
void update();				//�޸Ľڵ�����
void transport();			//�Ѽ����������˵����մ��θ���ά����bir[][]
void sort_birth();			//����ά���������������
int NodeCount();			//����ڵ�ĸ���
void read();				//�ļ���ȡ
int read1();				//���read()������ȡ�ļ�
void write();				//�������
void write1();				//���write()�����������


void menu();				//��ʾ��ѡ�˵�
void home();				//��ҳ


void InitQ(Queue &Q)  //��ʼ��
{
    Q.front=Q.rear=0;
}
 
void EnQueue(Queue &Q,BiTree e)  //���
{
    Q.rear=(Q.rear+1)%MAXSIZE;
    Q.queue[Q.rear]=e;
}
 
void DeQueue(Queue &Q,BiTree &e)  //����
{
    Q.front=(Q.front+1)%MAXSIZE;
    e=Q.queue[Q.front];
}
 
int QEmpty(Queue Q)  //�жӿ�
{
    return Q.front==Q.rear;
}
 
int QFull(Queue Q)  //�ж���
{
    if((Q.rear+1)%MAXSIZE==Q.front)
	{
		return 1;
	}
    return 0;
}

void new_left(BiTree p,Info info)  //�������
{
    BiTree q=(BiTree)malloc(sizeof(BNode));
    q->person=info;
    q->lchild=q->rchild=NULL;
    p->lchild=q;
}

void new_right(BiTree p,Info info)  //����Һ���
{
    BiTree q=(BiTree)malloc(sizeof(BNode));
    q->person=info;
    q->lchild=q->rchild=NULL;
    p->rchild=q;
}

int CreateBiTree(BiTree &T)  //��������
{							//���򴴽��ö��������ʾ�Ķ�������#��ʾ����
	BiTree q=(BiTree)malloc(sizeof(BNode));
	Info human;
	printf("\n");
	cout<<"������������";
	cin>>human.name;
	if (strcmp(human.name,"#")==0)
	{
		T=NULL;   //��#��ʾ������Ϊ�գ�
	}
	else
	{
		cout<<"�������������(���ո�ʽΪ####**@@)��";
		cin>>human.birth;
		cout<<"�������Ա�(�л�Ů)��";
		cin>>human.gender;
		cout<<"������ѧ����";
		cin>>human.degree;
        cout<<"������ְҵ��";
		cin>>human.career;
		cout<<"�������ַ(ʡ��+��������:�㶫����)��";
		cin>>human.add;
		cout<<"�Ƿ���(��������1����������0)��";
		cin>>human.health;
		if(human.health==0)
		{
			cout<<"��������(�������ڸ�ʽΪ####**@@)��";
			cin>>human.death_date;
		}
		else strcpy(human.death_date,"��������!");
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

void output(BiTree p)//���ĳ������Ϣ
{
    printf("%-8.10s%-7.8s%7s%11s %9s%14s%7d%17s\n",p->person.name,p->person.birth,p->person.gender,p->person.degree,p->person.career,p->person.add,p->person.health,p->person.death_date);
}

void level(BiTree t) //��α�������ͼ
{
    BiTree q[40],p;		//BiTreeΪָ����
    int front,rear; 
    front=rear=0;
	system("cls");
	if(t==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();  //�����ַ�������������������������ִ��������䡣
		return;
	}
    printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
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

void show_level(BiTree p,int n) //��α������׵ĵ�n��
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

BiTree Parent(BiTree bt,BiTree p)  //�ҵ����p��˫�ײ�����
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

BiTree search_name(BiTree bt,char na[])  //ͨ�������ҵ���㲢���أ�ͨ�����ֲ�ѯ���׳�Ա��Ϣ��
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

void search_child(BiTree p,BiTree child[])  //�ҵ����p�ĺ��Ӵ浽ָ������child[]��
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

void search_3generations(BiTree bt)  //��ʾ��������Ϣ
{
    char na[20];
    BiTree parent,node,child[2];
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("������������ҵ��Ǹ��˵�������");
    scanf("%s",na);
    node=search_name(bt,na);
	if(node==NULL)
	{
		printf("δ�ҵ��ó�Ա��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    parent=Parent(bt,node);
	if(parent==NULL)
	{
		printf("δ�ҵ��ó�Ա���ף�");
	}	
    search_child(node,child);
    printf("\n����ҵ�����˵���ϢΪ:\n\n");
    printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
    output(node);
	if(parent!=NULL)
	{
		printf("���ĸ��׽�����ϢΪ��\n");
		output(parent);
	}
    if(child[0]!=NULL)
    {
        printf("�������ӵ���ϢΪ��\n");
        output(child[0]);
    }
     if(child[1]!=NULL)
    {
        printf("�����Һ��ӵ���ϢΪ��\n");
        output(child[1]);
    }
	printf("��ʾ���!\n");
	printf("�밴�����������");
	getch();
}

BiTree search_birth(BiTree bt,char bir[])  //ͨ�������ҵ���㲢���أ�ͨ�����ղ�ѯ���׳�Ա��Ϣ��
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

void search_birthday(BiTree bt)  //���������Ϣ
{
    BiTree p;
    char bir[20];
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("������������ҵ��Ǹ��˵����գ�\n");
    scanf("%s",bir);
    p=search_birth(bt,bir);
	if(p==NULL)
	{
		printf("δ�ҵ��ó�Ա��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("������ҵ��Ǹ��˵���ϢΪ��\n");
    printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
    output(p);
	printf("��ʾ��ɣ�\n");
	printf("�밴�����������");
	getch();
}
 
int same_father(BiTree bt,BiTree p,BiTree q)  //�жϽ��p��q�Ƿ�Ϊͬ��������Ƿ���1�����򷵻�0
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

void ralationship(BiTree bt)   //ͨ��������������Ϣ���ж������˵Ĺ�ϵ
{
    char name1[20],name2[20];
    BiTree s1,s2,f1,f2;
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("�������һ���˵�������\n");
    scanf("%s",name1);
    printf("������ڶ����˵�������\n");
    scanf("%s",name2);
    s1=search_name(bt,name1);
	if(s1==NULL)
	{
		printf("δ�ҵ���һ���ˣ�\n");
		printf("�밴�����������");
		getch();
		return;
	}
    s2=search_name(bt,name2);
	if(s2==NULL)
	{
		printf("δ�ҵ��ڶ����ˣ�\n");
		printf("�밴�����������");
		getch();
		return;
	}
	if(strcmp(s1->person.name,s1->person.name)==1)
	{
		printf("�������ͬһ����\n");
		printf("�밴�����������");
		getch();
		return;
	}
    f1=Parent(bt,s1);
    f2=Parent(bt,s2);
    if(same_father(bt,s1,s2)==1)
	{
        printf("���������ֵܹ�ϵ��\n");
	}
    else if(same_father(bt,f1,f2)==1)
	{
		printf("���������ֵܹ�ϵ��\n");
	}
    else if(s1->lchild==s2)
	{
		printf("%s��%s������\n",s2->person.name,s1->person.name);
	}
    else if(s1->rchild==s2)
	{
		printf("%s��%s�Һ���\n",s2->person.name,s1->person.name);
	}
    else if(s2->lchild==s1)
	{
		printf("%s��%s������\n",s1->person.name,s2->person.name);
	}
    else if(s2->rchild==s1)
	{
        printf("%s��%s���Һ���\n",s1->person.name,s2->person.name);
	}
    else
	{
        printf("���˹�ϵ��΢������û�����ݹ�ϵ��\n");
	}
	printf("��ʾ���,�밴�����������");
	getch();
}

void add(BiTree &bt)   //��һ�����ӵ�к��ӣ���Ӻ��ӣ�
{
    char na[20];
    int i;
    BiTree p;
    Info new_child;
	system("cls");  //�Զ���������
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("��������������ӵ�к��ӵĳ�Ա���֣�\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("δ�ҵ��ó�Ա��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("������ó�Աӵ�����ӻ������Һ��ӣ�����������1,�Һ���������2\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            if(p->lchild!=NULL)
            {
                printf("���ʧ�ܣ��ó�Ա�������ӣ�\n");
                break;
            }
            else
            {	
                printf("�������º��ӵ�������\n");
                scanf("%s",new_child.name);
                printf("�������º��ӵĳ�������(���ո�ʽΪ####**@@)��\n");
                scanf("%s",new_child.birth);
				printf("�������º��ӵ��Ա�(�л�Ů)��\n");
                scanf("%s",new_child.gender);
                printf("�������º��ӵĵ�ַ��(ʡ��+��������:�㶫����)\n");
                scanf("%s",new_child.add);
                printf("�º��ӽ����𣿽���������1��ȥ��������0��\n");
                scanf("%d",&new_child.health);
                printf("����º����Ѿ�ȥ������������������(�������ڸ�ʽΪ####**@@)������������-1��\n");
                scanf("%s",new_child.death_date);
                if(strcmp(new_child.death_date,"-1")==0)
				{
                    strcpy(new_child.death_date,"��������!");
				}
                new_left(p,new_child);
            }
            break;
        case 2:
            if(p->rchild!=NULL)
            {
                printf("���ʧ�ܣ��ó�Ա�����Һ��ӣ�\n");
                break;
            }
            else
            {
                printf("�������º��ӵ�������\n");
                scanf("%s",new_child.name);
                printf("�������º��ӵĳ�������(���ո�ʽΪ####**@@)��\n");
                scanf("%s",new_child.birth);
				printf("�������º��ӵ��Ա�(�л�Ů)��\n");
                scanf("%s",new_child.gender);
                printf("�������º��ӵĵ�ַ��(ʡ��+��������:�㶫����)\n");
                scanf("%s",new_child.add);
                printf("�º��ӽ����𣿽���������1��ȥ��������0��\n");
                scanf("%d",&new_child.health);
                printf("����º����Ѿ�ȥ������������������(�������ڸ�ʽΪ####**@@)������������-1��\n");
                printf("%s",new_child.death_date);
                if(strcmp(new_child.death_date,"-1")==0)
				{
                    strcpy(new_child.death_date,"��������!");
				}
                new_right(p,new_child);
            }
            break;
        default:
            printf("��������\n");
            break;
    }
	printf("�����ɣ�\n");
	printf("�밴�����������");
	getch();
}

void delete_name(BiTree &bt) //ɾ��һ����㲢һ��ɾ��������
{
    char na[20];
    BiTree p,f;
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("����������ɾ���ĳ�Ա������ɾ����Ա֮�󣬸ó�Ա������Ҳ��һ��ɾ����\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("δ�ҵ��ó�Ա��\n");
		printf("�밴�����������");
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
	printf("ɾ����ɣ�\n");
	printf("�밴�����������");
	getch();
}
 
void show_family(BiTree bt) //��ʾ����
{
    Queue Q1,Q2;
    int i=0;
    BiTree e;
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    InitQ(Q1);		//��Q1��ʼ��
    InitQ(Q2);		//��Q2��ʼ��
    if(bt!=NULL)
    {
        EnQueue(Q1,bt);			//���
        while(!QEmpty(Q1))		//�ж϶ӿ�
        {
            while(!QEmpty(Q1))		//�ж϶ӿ�
            { 
                DeQueue(Q1,e);		//����
                EnQueue(Q2,e);		//���
            }
            i++;
            if(i==1)
			{
                printf("��%d����                                ",i);  //��ʾ������
			}
            if(i==2)
			{
                printf("��%d����                           ",i);
			}
            if(i==3)   
			{
                printf("��%d����                     ",i);
			}
            if(i==4)
			{
                printf("��%d����               ",i);
			}
            if(i==5)
			{
                printf("��%d����          ",i);
			}
			if(i==6)
			{
                printf("��%d����     ",i);
			}
			if(i==7)
			{
                printf("��%d���� ",i);
			}
            while(!QEmpty(Q2))
            {
                DeQueue(Q2,e);		//����
                printf("%s ",e->person.name);
                if(!QFull(Q1)&&e->lchild!=NULL)
				{
                    EnQueue(Q1,e->lchild);		//���
				}
                if(!QFull(Q1)&&e->rchild!=NULL)
				{
                    EnQueue(Q1,e->rchild);		//���
				}
            }
            puts("");
        }
    }
	printf("��ʾ��ɣ�\n");
	printf("�밴�����������");
	getch();
}
 
void update(BiTree bt)		//�޸ĳ�Ա
{
    char na[20];
    BiTree p;
	system("cls");
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("�����������޸ĳ�Ա��������\n");
    scanf("%s",na);
    p=search_name(bt,na);
	if(p==NULL)
	{
		printf("δ�ҵ��ó�Ա:\n");
		printf("�밴�����������");
		getch();
		return;
	}
    printf("�������޸Ĺ����������\n");
    scanf("%s",p->person.name);
    printf("�������޸ĺ�ĳ�������(���ո�ʽΪ####**@@)��\n");
    scanf("%s",p->person.birth);
    printf("�������޸ĺ���Ա�(�л�Ů)��\n");
    scanf("%s",p->person.gender);
    printf("�������޸Ĺ����סַ��(ʡ��+��������:�㶫����)\n");
    scanf("%s",p->person.add);
    printf("�޸ĺ�ó�Ա�Ƿ��ڣ�����������1���Ѿ�ȥ��������0��\n");
    scanf("%d",&p->person.health);
    printf("����޸ĺ�ó�Ա�Ѿ���������������������(�������ڸ�ʽΪ####**@@)������������-1��\n");
    scanf("%s",p->person.death_date);
    if(strcmp(p->person.death_date,"-1")==0)
	{
        strcpy(p->person.death_date,"��������!");
	}
	printf("�޸���ɣ�\n");
	printf("�밴�����������");
	getch();
}
 
void transport(BiTree bt,char bir[][20],int &x)  //�Ѽ����������˵�������ֵ������ά����bir[][]
{
    if(bt)
    {
        strcpy(bir[x++],bt->person.birth);
        transport(bt->lchild,bir,x);
        transport(bt->rchild,bir,x);
    }
}
 
void sort_birth(BiTree bt,char bir[][20],int n)//����ά����bir[][]�����������
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
	printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
    for(i=0;i<n;i++)
    {
        p=search_birth(bt,bir[i]);
        output(p);
    }
    printf("�������!\n");
	printf("�밴�����������");
	getch();
}
 

int NodeCount(BiTree bt)  //����ڵ�ĸ���
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

int read1(BiTree &bt,FILE *fp)  //���read()�����ļ���ȡ
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

void read(BiTree &bt)  //�ļ���ȡ
{
	system("cls");
	FILE *fp;
	fp=fopen("���׳�Ա�ļ�.txt","r");  //���ļ�
    printf("���ļ������������Ϣ�ǣ�\n");
    printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
    read1(bt,fp);
    fclose(fp);
	printf("��ȡ�ɹ���\n");
	printf("�밴�����������");
	getch();
}

void write1(BiTree &bt,FILE *fp)		//���write()���м��ױ���
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

void write(BiTree &bt)		//��������
{
	int i;
	FILE *fp;
	if(bt==NULL)
	{
		printf("δ�����Ա��Ϣ��\n");
		printf("�밴�����������");
		getch();
		return;
	}
	system("cls");
	num=NodeCount(bt);
	fp=fopen("���׳�Ա�ļ�.txt","wb");
    write1(bt,fp);
    fclose(fp);
    printf("����ɹ���\n");
	printf("�밴�����������");
	getch();
}

void menu()
{	
	printf("��**�ƿ�3�� ������ 202110089205****************************��\n");
	printf("��******************��ӭʹ�ü��׹���ϵͳ��*****************��\n");
	printf("��*                   1.��ȡ����                          *��\n");
    printf("��*                   2.��ʾ����                          *��\n");
    printf("��*                   3.��α�������                      *��\n");
    printf("��*                   4.��ʾ��n���˵���Ϣ                 *��\n");
    printf("��*                   5.�����������Ա������Ϣ            *��\n");
    printf("��*                   6.���������ڲ�ѯ��Ա����            *��\n");
    printf("��*                   7.ȷ�����˹�ϵ                      *��\n");
    printf("��*                   8.����Ա��Ӻ���                    *��\n");
    printf("��*                   9.ɾ��ĳ��Ա                        *��\n");
    printf("��*                   10.�޸�ĳ��Ա��Ϣ                   *��\n");
    printf("��*                   11.��������                         *��\n");
	printf("��*                   12.��������                         *��\n");
	printf("��*                   13.�������                         *��\n");
    printf("��*                   14.�˳�ϵͳ                         *��\n");
	printf("��*******************����������ѡ��:***********************��\n");
}
void home(BiTree &bt)
{
	int i,j,n,x=0;
    char bir[60][20];
	do
	{
	    system("cls");
	    fflush(stdin);
	    menu(); //����˵�ҳ��
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
			    printf("��ʾ���,�밴���������!");
		    	getch();
                break;
            case 4:
			    system("cls");
			    if(bt==NULL)
				{
			    	printf("δ�����Ա��Ϣ��\n");
			    	printf("�밴�����������");
			    	getch();
				}
			    else
				{
			    	printf("������ҵڼ�������Ϣ��\n");
			    	scanf("%d",&n);
			    	printf("����    ��������     �Ա�     ѧ��      ְҵ      ��ַ       ���ڷ�      ��������\n");
			    	show_level(bt,n);
			    	printf("����ʾ��%d������Ϣ,�밴���������!",n);
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
		    		printf("δ�����Ա��Ϣ��\n");
		    		printf("�밴�����������");
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
		    	printf("�����˳�����������#��ֱ����ʾ�����ɹ�Ϊֹ!\n");
                CreateBiTree(bt);
		    	printf("�����ɹ�,�밴���������!\n");
		    	printf("�ǵñ���!!!!!");
		    	getch();
                break;
	    	case 13:
				{
		    		write(bt);
                    break;
				}
            case 14:
                printf("��л���ʹ�ã��´��ټ���\n");
                exit(0);
                default:
                printf("�����������������룡\n");
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
	printf("\t��**�ƿ�3�� ������ 202110089205***********************************��\n");
	printf("\t��****************************************************************��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��**                    ��ӭʹ�ü��׹���ϵͳ                    **��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��**                                                            **��\n");
	printf("\t��****************************************************************��\n");
	printf("\t��***********************************�ƿ�3�� ������ 202110089205**��\n");
	getch();
    home(bt);  //����home()����;
	return 1;
}
