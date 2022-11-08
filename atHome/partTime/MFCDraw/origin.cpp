#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>//可以调用system函数库 
#include<string.h>	

//图元信息结构体
struct chart1
{

	char name[30];//名称 
	char num[30];//序号 
	char type[20];//类型（point代表点，line代表线，polygon代表多边形） 
	char linetype[20];//线形 

	int color;             //颜色
	int thickness;  //粗细程度


	double longitude;		//经度坐标
	double latitude;        //纬度坐标


};
struct chart
{
	struct chart1 chart1;//图元信息结构体 
	struct chart* next;
};

void menu();//主菜单
void menu1();//管理者菜单 
void menu2();//用户菜单 
void backmenu1();//实现返回管理者功能菜单函数
void backmenu2();//用户功能菜单函数 
void add();	//增加 
void display();//显示 
void display1();
void change();//修改 
void enter();//数据录入 
void find();//查找 
void chdelete();//删除 
void browser();//浏览 
void insert();//插入 
void sort();//排序

struct chart* read();//文件数据传入链表 
void write(struct chart* head);//链表数据写入文件 

int main()
{

	char c;
	menu();
	printf("管理员请输入m,用户请输入n,退出请按0\n");
	scanf("%c", &c);
	while (c != '0')//当输出不是退出键时 
	{
		if (c == 'm')
		{
			backmenu1();//进入管理者功能 
			break;
		}
		else
			if (c == 'n')
			{
				backmenu2();//进入用户功能 
				break;
			}
			else
			{
				printf("输入错误请重新输入!\n");
				scanf("%c", &c);
			}
		scanf("%c", &c);
	}
	if (c == '0')
		printf("您已成功退出图元管理系统！\n");
	return 0;
}
//登录界面 
void menu()
{
	system("cls");
	printf("*---------------------------------图元信息管理系统---------—-----------------------*\n");
	printf("*-----------------------------------------------------------------------------------*\n");
	printf("*                                   登录选项                                        *\n");
	printf("*                1.管理员                                 2.用户                    *\n");
	printf("*-----------------------------------------------------------------------------------*\n");
	printf("\n");
}
// 管理员界面 
void menu1()
{
	system("cls");
	printf("*---------------------------------图元信息管理系统---------------------------------*\n");
	printf("*                                                                                  *\n");
	printf("*---------------------------------管理员功能列表-----------------------------------*\n");
	printf("*                                                                                  *\n");
	printf("*1.录入图元                         2.增加图元                         3.显示图元  *\n");
	printf("*4.修改图元信息                     5.查找图元                         6.删除图元  *\n");
	printf("*7.浏览图元                         8.图元排序                         9.插入图元  *\n");
	printf("*----------------------------------------------------------------------------------*\n");
	printf("\n");
}
//用户界面 
void menu2()
{
	system("cls");
	printf("*********************************图元信息管理系统***********************************\n");
	printf("*                                                                                  *\n");
	printf("*----------------------------------用户功能列表------------------------------------*\n");
	printf("*                                                                              	   *\n");
	printf("*               1.查询图元                                 2.浏览图元              *\n");
	printf("*----------------------------------------------------------------------------------*\n");
	printf("\n");
}
//实现返回管理者功能菜单函数
void backmenu1()
{
	FILE* fp;
	int n = 1;
	while (n != 0)
	{
		system("cls");
		menu1();//在这个循环中，每执行一次功能后会继续显示菜单 
		printf("请选择以上功能，退出系统请按0\n");
		printf("\n");
		scanf("%d", &n);
		fp = fopen("libraries.txt", "r");
		if ((n >= 3 && n <= 9) && (fp == NULL || fgetc(fp) == EOF))//当无文件或者文件内容空白时且选择非（录入添加显示）功能 
		{
			printf("没有图元，建议管理员先录入图元信息\n");
			system("pause");
		}
		else
		{
			switch (n)
			{
			case 1:enter(); break;
			case 2:add(); break;
			case 3:display1(); break;
			case 4:change(); break;
			case 5:find(); break;
			case 6:chdelete(); break;
			case 7:browser(); break;
			case 8:sort(); break;
			case 9:insert(); break;
			}
		}
		fclose(fp);
	}
	printf("\n");
	if (n == 0)
		printf("您已成功退出图元信息管理系统！\n");
}

//用户功能菜单函数 
void  backmenu2()
{
	FILE* fp;
	int n = 1;
	while (n != 0)
	{
		system("cls");
		menu2();
		printf("选择功能，退出请按0\n");
		scanf("%d", &n);
		fp = fopen("libraries.txt", "r");
		if ((fp == NULL || fgetc(fp) == EOF))//当无文件或者文件内容空白时
		{
			printf("图元信息管理系统内暂无图元，请耐心等待\n");
			system("pause");

		}
		else
		{
			switch (n)
			{

			case 1:find(); break;

			case 2:browser(); break;
			}
		}
		fclose(fp);
	}
	if (n == 0)
	{
		printf("您已成功退出图元信息管理系统\n");
		system("pause");
	}



}

//文件数据传入链表 
struct chart* read()
{
	FILE* fp;
	struct chart1 chart1;
	struct chart* p, * tail = NULL, * head = NULL;
	fp = fopen("libraries.txt", "r");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	while (fscanf(fp, "%s%s%s%s%d%d%lf%lf", chart1.num, chart1.name, chart1.type, chart1.linetype, &chart1.color, &chart1.thickness, &chart1.longitude, &chart1.latitude) != EOF)//在文件未遇到结束标志时读取数据 
	{
		p = (struct chart*)malloc(sizeof(struct chart));//开辟空间创建链表 
		p->chart1 = chart1;
		if (head == NULL)
			head = p;
		if (tail != NULL)
			tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	fclose(fp);
	return head;
}
//链表写入文件 
void write(struct chart* head)
{
	FILE* fp;
	struct chart* p = NULL;
	fp = fopen("libraries.txt", "w");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	p = head;
	while (p)
	{
		//将数据写入文件
		fprintf(fp, "%-15s%-15s%-19s%-19s%-14d%-14d%-15.9lf%-15.9lf\n", p->chart1.num, p->chart1.name, p->chart1.type, p->chart1.linetype, p->chart1.color, p->chart1.thickness, p->chart1.longitude, p->chart1.latitude);
		p = p->next;
	}
	fclose(fp);
}

//数据录入 
void enter()
{
	FILE* fp;
	int i, n;
	struct chart1 chart1;
	system("cls");
	printf("输入录入的图元数量\n");
	scanf("%d", &n);
	printf("按以下格式输入\n");
	printf("序号	名称	类型	线形	颜色	粗细程度		经度坐标		纬度坐标\n");
	fp = fopen("libraries.txt", "w");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		//将数据写入文件
		scanf("%s%s%s%s%d%d%lf%lf", chart1.num, chart1.name, chart1.type, chart1.linetype, &chart1.color, &chart1.thickness, &chart1.longitude, &chart1.latitude);
		fprintf(fp, "%-15s%-15s%-19s%-19s%-14d%-14d%-15.9lf%-15.9lf\n", chart1.num, chart1.name, chart1.type, chart1.linetype, chart1.color, chart1.thickness, chart1.longitude, chart1.latitude);
	}
	fclose(fp);
}

//增加图元 					
void add()
{
	struct chart* p = NULL, * p1 = NULL, * head = NULL, * p2;
	char n = 1;
	system("cls");
	printf("按以下格式输入\n");
	printf("序号	名称	类型	线形	颜色	粗细程度		经度坐标		纬度坐标\n");
	p = head = read();//从文件读取数据 
	p2 = (struct chart*)malloc(sizeof(struct chart));
	scanf("%s%s%s%s%d%d%lf%lf", p2->chart1.num, p2->chart1.name, p2->chart1.type, p2->chart1.linetype, &p2->chart1.color, &p2->chart1.thickness, &p2->chart1.longitude, &p2->chart1.latitude);
	while (p)
	{
		if (strcmp(p->chart1.name, p2->chart1.name) == 0)//与已有图元重名 

		{
			break;
		}
		else
			p = p->next;
	}

	if (head == NULL)         					//确定新书链接位置
		head = p2;
	else
	{										//尾部添加数据 
		p1 = head;
		while (p1->next != NULL)
			p1 = p1->next;
		p1->next = p2;
		p2->next = NULL;
	}
	write(head);						 //将数据写入文件
	n = getchar();
	printf("图元添加成功\n");
	display();
	system("pause");
}

//显示所有图元 
/*为了节省空间，可以直接用一个结构体，边读取，边输出*/
void display()
{
	struct chart1 chart1;
	FILE* fp;
	//system("cls");//实现清屏，刷新屏幕 
	printf("图元库存\n");
	printf("\n");
	fp = fopen("libraries.txt", "r");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	else
	{
		printf("序号	名称	类型	线形	颜色	粗细程度		经度坐标		纬度坐标\n");
		while (fscanf(fp, "%s%s%s%s%d%d%lf%lf", chart1.num, chart1.name, chart1.type, chart1.linetype, &chart1.color, &chart1.thickness, &chart1.longitude, &chart1.latitude) != EOF)
		{
			printf("%-15s%-15s%-19s%-19s%-14d%-14d%-15.9lf%-15.9lf\n", chart1.num, chart1.name, chart1.type, chart1.linetype, chart1.color, chart1.thickness, chart1.longitude, chart1.latitude);
		}
	}
	fclose(fp);
	printf("\n");
}

void display1() {
	system("cls");
	display();
	system("pause");
}

//修改图元信息 
void change()
{
	struct chart* p, * head, * q = NULL;
	system("cls");
	int n = 1, color, thickness;
	char  name[30] = { '\0' }, num[30] = { '\0' }, type[20] = { '\0' }, linetype[20] = { '\0' }, name1[30] = { '\0' };
	double longitude, latitude;
	p = head = read();
	display();
	printf("输入要修改的图元名称\n");
	scanf("%s", name);
	while (p)
	{
		if (strcmp(p->chart1.name, name) == 0)//查找要修改的图元,找到后跳出循环 
		{
			q = p;
			break;
		}
		else
			p = p->next;
	}
	while (n != 0)
	{
		printf("请选择您要修改的信息,退出修改请按0\n");
		printf("*-------------------------------------------------------------*\n");
		printf("*1.修改序号           2.修改名称        3.修改类型            *\n");
		printf("*4.修改线形           5.修改颜色        6.修改粗细程度        *\n");
		printf("*7.修改经度坐标       8.修改纬度坐标                          *\n");
		printf("*-------------------------------------------------------------*\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: printf("输入新序号：");  scanf("%s", num);      strcpy(q->chart1.num, num); break;
		case 2:	printf("输入新名称：");  scanf("%s", name1);    strcpy(q->chart1.name, name1); break;
		case 3:	printf("输入新类型；"); scanf("%s", type);   strcpy(q->chart1.type, type); break;
		case 4: printf("输入新线形；");      scanf("%s", linetype);     strcpy(q->chart1.linetype, linetype); break;
		case 5:	printf("输入新颜色；");      scanf("%d", &color);    q->chart1.color = color; break;
		case 6:	printf("输入新粗细程度：");      scanf("%d", &thickness);     q->chart1.thickness = thickness; break;
		case 7: printf("输入新经度坐标：");    scanf("%lf", &longitude);	    q->chart1.longitude = longitude; break;
		case 8: printf("输入新纬度坐标：");    scanf("%lf", &latitude);	    q->chart1.latitude = latitude; break;

			/*default :printf("输入错误，请重新输入!\n");break;*/
		}
	}
	write(head);			//将修改后的信息存入文件
	printf("修改成功!\n");
	display();
	system("pause");
}
//查找图元
void find()
{
	struct chart* head = NULL, * p;
	char name[30] = { '\0' };
	int flag = 0;
	char n = 1;
	system("cls");
	head = read();//让head指向传入文件数据的链表 
	p = head;
	printf("输入查找图元相关信息(序号/名称):\n");
	scanf("%s", name);
	while (p)
	{
		if (strcmp(p->chart1.name, name) == 0 || strcmp(p->chart1.num, name) == 0)
		{
			printf("序号	名称	类型	线形	颜色	粗细程度		经度坐标		纬度坐标\n");
			printf("%-15s%-15s%-19s%-19s%-14d%-14d%-15.9lf%-15.9lf\n", p->chart1.num, p->chart1.name, p->chart1.type, p->chart1.linetype, p->chart1.color, p->chart1.thickness, p->chart1.longitude, p->chart1.latitude);
			printf("\n");
			flag = 1;
			break;
		}
		else
			p = p->next;
	}
	if (flag == 0)
		printf("没有此图元,请确认名称是否正确!\n\n");
	system("pause");

}
//浏览图元的数量 
void browser()
{
	struct chart* p = NULL, * head;
	system("cls");
	head = read();
	p = head;
	if (p == NULL)
		printf("没有图元\n");
	else
	{
		printf("已有图元如下\n");
		printf("名称		序号\n");
		while (p)
		{
			printf("%-15s%-15s%\n", p->chart1.name, p->chart1.num);
			p = p->next;
		}
	}
	system("pause");
}
//删除书籍
void chdelete()
{
	struct chart* p1 = NULL, * p2 = NULL, * head = NULL;
	char name[30] = { '\0' };
	char ch;
	p1 = p2 = head = read();
	system("cls");
	display();
	printf("\n");
	printf("输入要删除的图元名称：\n");
	scanf("%s", name);
	while (strcmp(p1->chart1.name, name) != 0 && p1 != NULL)//第一个图元和要删除的图元名称不同则一直寻找 
		p1 = p1->next;
	if (head == p1)//如果第一个图元和要删图元名称相同则换头结点 
		head = head->next;
	else
	{
		while (p2)
		{
			if (p2->next == p1)//p2指向p1的所指向结点的前一个 
			{
				p2->next = p1->next;
				free(p1);
				break;
			}
			p2 = p2->next;
		}
	}
	printf("删除成功！\n");
	write(head);
	display();
	printf("\n");
	system("pause");
}
//插入图元
void insert()
{
	struct chart* p1, * head, * p2, * p;
	system("cls");
	head = read();
	p1 = head;
	p2 = head->next;
	printf("请按以下格式输入要插入的图元信息\n");
	printf("序号	名称	类型	线形	颜色	粗细程度		经度坐标		纬度坐标\n");
	p = (struct chart*)malloc(sizeof(struct chart));
	scanf("%s%s%s%s%d%d%lf%lf", p->chart1.num, p->chart1.name, p->chart1.type, p->chart1.linetype, &p->chart1.color, &p->chart1.thickness, &p->chart1.longitude, &p->chart1.latitude);
	p->next = NULL;
	/*在第一个结点插入*/
	if (strcmp(head->chart1.num, p->chart1.num) > 0)
	{
		head = p;
		p->next = p1;
	}
	else
	{
		while (p2 && strcmp(p2->chart1.num, p->chart1.num) <= 0)//p2为空退出循环则插入在尾部 
		{
			p1 = p2;
			p2 = p2->next;
		}
		p->next = p2;
		p1->next = p;
	}
	printf("成功插入图元!\n");
	write(head);
	display();
	system("pause");
}
int count()//统计图元文本个数
{
	FILE* fp;
	int n = 0;
	struct chart1 chart1;
	fp = fopen("libraries.txt", "r");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	while (fscanf(fp, "%s%s%s%s%d%d%lf%lf", chart1.num, chart1.name, chart1.type, chart1.linetype, &chart1.color, &chart1.thickness, &chart1.longitude, &chart1.latitude) != EOF)
		n++;
	fclose(fp);//关闭文件
	return n;	//返回个数
}
//图元排序功能  
void sort()
{
	FILE* fp;
	struct chart1 a[100];
	struct chart1 t;	//用于排序的结构体变量 
	int n, i, j;
	system("cls");
	n = count();//调用统计图书文本函数
	fp = fopen("libraries.txt", "r");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < n; i++)//将数据复制到数组中 					
		fscanf(fp, "%s%s%s%s%d%d%lf%lf", a[i].num, a[i].name, a[i].type, a[i].linetype, &a[i].color, &a[i].thickness, &a[i].longitude, &a[i].latitude);
	/*根据isbn进行冒泡排序（升序）*/
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(a[j].num, a[j + 1].num) > 0)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	fclose(fp);	//注意关闭文件 
	fp = fopen("libraries.txt", "w");
	if (!fp)
	{
		printf("cannot open file\n");
		exit(0);
	}
	for (i = 0; i < n; i++)
		fprintf(fp, "%-15s%-15s%-19s%-19s%-14d%-14d%-15.9lf%-15.9lf\n", a[i].num, a[i].name, a[i].type, a[i].linetype, a[i].color, a[i].thickness, a[i].longitude, a[i].latitude);
	fclose(fp);
	printf("排序成功\n");
	display();//显示排序后的图元
	system("pause");
}
