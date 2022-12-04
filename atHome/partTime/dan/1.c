#define _CRT_SECURE_NO_WARNINGS//忽略安全检测，不然使用scanf会报错
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int N1, N2;
int n = 0;
struct book
{
	int num1;        //教材编号
	char name1[20];  //教材名
	char major[20];
	int credit;
	int period;
	char teacher[20];
	int people;                   //选此门教材的人数
	struct book* next;
};

struct student
{
	int num2;
	char name2[20];
	int booknum[50];              //所选教材编号
	int credit;                    //所选教材学分
	struct student* next;
};
struct book* head1;
struct student* head2;





void input()                 //从键盘录入教材信息
{
	struct book* p1, * p2;
	N1 = 0;
	int n = 0;
	p1 = p2 = (struct book*)malloc(sizeof(struct book));
	assert(p1);
	int y;
	if (n == 0)
		do
		{
			printf("--------------------\n");
			printf("请输入教材编号:");
			scanf("%d", &p1->num1);
			printf("请输入教材名称:");
			sscanf_s("%s", p1->name1, 20);
			printf("请输入主/辅修:");
			sscanf_s("%s", p1->major, 20);
			printf("请输入课程学分:");
			scanf("%d", &p1->credit);
			printf("请输入课时:");
			scanf("%d", &p1->period);
			printf("请输入教师名称:");
			sscanf_s("%s", p1->teacher, 20);
			n++;
			p1++;
			printf("\n1.继续输入.\n0.输入完毕.\n");
			printf("请选择：");
			scanf("%d", &y);
		} while (y == 1);
		printf("提示：输入完毕!你一共输入%d个\n", n);
}

void input1()                      //从文件录入教材信息
{
	FILE* fp;
	//char filepath[20];
	//struct book* p1, * p2;
	char buffer[1024] = { 0 };
	/*printf("请输入您要读取的路径:");
	int b=getchar();
	gets_s(filepath,20);
	 if ((fp = fopen(filepath, "r")) == NULL)*/
	fp = fopen("D:\\test.txt", "rb");


	if (fp == NULL)
	{
		printf("找不到 %s 文件!\n", fp);
		exit(0);
	}
	fwrite(buffer, sizeof(char), 1, fp);
	//p1 = p2 = (struct book*)malloc(sizeof(struct book));

	fread(buffer, sizeof(char), 1, fp);
	printf(buffer);
	fclose(fp);
	//fread(fp, "%d%s%s%c%d%d%s%d", &p1->num1, &p1->name1, &p1->major, &p1->credit, &p1->period, &p1->teacher, &p1->people, 20, 20, 20, 20, 20, 20, 20, 20, 20_)
	//fscanf_s(fp, "%d%s%s%c%d%d%s%d", &p1->num1, &p1->name1, &p1->major, &p1->credit, &p1->period, &p1->teacher, &p1->people,20,20,20,20,20,20,20,20,20);
		/*while (!feof(fp))//feo（）函数判断文件结束
	{
		N1 = N1 + 1;
		if (N1 == 1)
			head1 = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct book*)malloc(sizeof(struct book));
		fscanf_s(fp, "%d%s%s%s%d%d%s%d", &p1->num1, p1->name1, p1->major,&p1->credit, &p1->period, p1->teacher, &p1->people,20,20,20,20,20,20,20,20,20);
	}*/
	//p2->next = NULL;
}
void load()             //录入教材信息函数
{
	int i;
	printf("\t\t\t录入教材信息\n");
	printf("\n1.从键盘录入");
	printf("\n2.从文件录入");
	printf("\n3.返回主菜单\n");
	printf("请选择1-3:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:input(); break;
	case 2:input1(); break;
	case 3:break;
	}
}



void insert(struct book* inbook)             //插入教材信息
{
	struct book* p0, * p1, * p2;
	p1 = head1;
	p0 = inbook;
	p2 = 0;
	if (head1 == NULL)
	{
		head1 = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num1 > p1->num1) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num1 <= p1->num1)
		{
			if (head1 == p1)
				head1 = p0;
			else
				p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	N1 = N1 + 1;
}
void delect(int num1)             //删除教材信息
{
	struct book* p1, * p2;
	p2 = 0;
	if (head1 == NULL)
	{
		printf("\n无法删除!\n");
		goto end;
	}
	p1 = head1;
	while (num1 != p1->num1 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num1 == p1->num1)
	{
		if (p1 == head1)
			head1 = p1->next;
		else
			p2->next = p1->next;
		printf("已删除\n");
		N1 = N1 - 1;
	}
	else
		printf("没有此教材\n");
end:;
}
void management()             //教材信息管理函数
{
	struct book* p1;
	int i, num1;
	printf("\t\t\t教材信息管理\n");
	printf("1.添加教材\n");
	printf("2.删除教材\n");
	printf("3.返回\n");
	printf("请输入1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		struct book* p1, * p2;
		N1 = 0;
		p1 = p2 = (struct book*)malloc(sizeof(struct book));
		int y;
		int n = 0;
		if (n == 0)
			do
			{
				printf("--------------------\n");
				printf("请输入教材编号:");
				scanf("%d", &p1->num1);
				printf("请输入教材名称:");
				scanf("%s", p1->name1);
				printf("请输入主/辅修:");
				scanf("%s", p1->major);
				printf("请输入学分:");
				scanf("%d", &p1->credit);
				printf("请输入课时:");
				scanf("%d", &p1->period);
				printf("请输入教师名称:");
				scanf("%s", p1->teacher);
				n++;
				p1++;
				printf("\n1.继续输入.\n0.输入完毕.\n");
				printf("请选择：");
				scanf("%d", &y);
			} while (y == 1);
			printf("提示：输入完毕!你一共输入%d个\n", n);

	}  break;
	case 2:printf("请输入您要删除的教材编号:\n");
		scanf("%d", &num1);
		delect(num1); break;
	case 3:break;
	}
}
void putinstu(void)           //从键盘录入学生信息
{
	int i;
	int y;
	int n = 0;
	struct student* p1, * p2;
	N2 = 0;
	p1 = p2 = (struct student*)malloc(sizeof(struct student));
	do
	{
		printf("学号:\t");
		scanf("%d", &p1->num2);
		printf("密码:\t");
		scanf("%s", p1->name2);
		p1->credit = 0;
		for (i = 0; i < 20; i++) p1->booknum[i] = 0;
		head2 = NULL;
		n++;
		p1++;
		printf("\n1.继续输入.\n0.输入完毕.\n");
		printf("请选择：");
		scanf("%d", &y);
	} while (y == 1);
	printf("提示：输入完毕!你一共输入%d个\n", n);
}
void putinstu2()              //从文件录入学生信息
{
	int i = 0;
	FILE* fp;
	char filepath[20];
	struct student* p1, * p2;
	N2 = 0;
	printf("请输入您要读取的路径:");
	int b = getchar();
	gets_s(filepath, 20);
	if ((fp = fopen(filepath, "r")) == NULL)
	{
		printf("找不到 %s 文件!\n", filepath);
		exit(0);
	}
	p1 = p2 = (struct student*)malloc(sizeof(struct student));
	fread(p1, sizeof(struct student), 1, fp);//fread()如果运行成功读取元素个数，不成功exit(0)
	head2 = NULL;
	while (!feof(fp))
	{
		i = 0;
		N2 = N2 + 1;
		if (N2 == 1)
			head2 = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(sizeof(struct student));
		fread(p1, sizeof(struct student), 1, fp);
	}
	p2->next = NULL;
}
void stu()               //录入学生信息函数
{
	int i;
	printf("\t\t\t录入学生信息\n");
	printf("\n1.从键盘录入\n");
	printf("2.从文件录入\n");
	printf("3.返回主菜单\n");
	printf("请输入1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:putinstu(); break;
	case 2:putinstu2(); break;
	case 3:break;
	}
}


void inserts(struct student* incouse)             //增加学生信息
{
	struct student* p0, * p1, * p2;
	p1 = head2;
	p0 = incouse;
	p2 = 0;
	if (head2 == NULL)
	{
		head2 = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num2 > p1->num2) && (p1->next != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num2 <= p1->num2)
		{
			if (head2 == p1) head2 = p0;
			else p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	N2 = N2 + 1;
}
void delectstu(int num2)                   //删除学生信息
{
	struct student* p1, * p2;
	p2 = 0;
	if (head2 == NULL)
	{
		printf("\n无法删除\n");
		goto end;
	}
	p1 = head2;
	while (num2 != p1->num2 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num2 == p1->num2)
	{
		if (p1 == head2)
			head2 = p1->next;
		else
			p2->next = p1->next;
		printf("已删除\n");
		N2 = N2 - 1;
	}
	else
		printf("没有此学生编号\n");
end:;
}
void managements()          //学生信息管理函数
{
	struct student* p1;
	int i, num2;
	printf("\t\t\t学生信息管理\n");
	printf("1.添加学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.返回主菜单\n");
	printf("请选择1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1: {p1 = (struct student*)malloc(sizeof(struct student));
		assert(p1);
		p1->credit = 0;
		p1->booknum[0] = 0;
		printf("num\tname\n");
		scanf("%d%s", &(p1->num2), p1->name2);
		inserts(p1); }
		  break;



	case 2: {printf("请输入您要删除的学生编号:\n");
		scanf("%d", &num2);
		delectstu(num2); } break;
	case 3:break;
	}
}
void elect()             //学生购教材
{
	struct student* s;
	struct book* p;
	int a, i, b;
	printf("请输入您的学号:\n");
	scanf("%d", &a);
	s = head2;
	while ((s->num2) != a && s->next != NULL) s = s->next;
	if (s->num2 != a)
	{
		printf("您的信息不存在，请重新输入:\n");
		goto end;
	}
	if ((s->credit) > 10)
	{
		printf("您曾已经购买");
		goto end;
	}
	printf("请输入您要购买的教材编号\n");
	scanf("%d", &b);
	for (i = 0; (s->booknum[i]) == 0; i++);
	s->booknum[i] = b;
	p = head1;
	while ((p->num1) != b)
		p = p->next;
	for (i = 0; (s->booknum[i]) != 0; i++);
	s->booknum[i] = b;
	(p->people)++;
	(s->credit) = (s->credit) + (p->credit);
	(p->people)++;
end:;
}
void back()              //学生退教材
{
	struct student* p;
	struct book* p1;
	int b, i, j, a;
	printf("请输入您的学号:\n");
	scanf("%d", &a);
	p = head2;
	while (p->num2 != a && p != NULL) p = p->next;
	if (p == NULL)
		printf("您的信息不存在:\n");
	else
	{
		printf("请输入您要退的教材:\n");
		scanf("%d", &b);
		p1 = head1;
		while (p1->num1 != b) p1 = p1->next;
		for (i = 0; p->booknum[i] != b; i++);
		for (j = i; p->booknum[j] != 0; j++)
			p->booknum[j] = p->booknum[j + 1];
		p->booknum[--j] = 0;
		(p->credit) = (p->credit) - (p1->credit);
		(p1->people)--;
		printf("succeed!\n");
	}
}
void elective()             //学生购教材管理
{
	int i;
	printf("\t\t\t学生购教材信息管理\n");
	printf("1.选教材\n");
	printf("2.退教材\n");
	printf("3.返回主菜单\n");
	printf("请输入1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:elect(); break;
	case 2:back(); break;
	case 3:break;
	}
}
void listc()                 //浏览教材信息
{
	struct book* p;
	p = 0;
	int i, j;
	if (n != 0)
	{
		printf("学生总数:%d\n", n);
		printf("教材编号    教材名称    主修    教材性质    学分    课时    教师   选课人数\n");
		printf("-----------------------------------------------------\n");
		for (i = 0; i < n; i++)
			printf("%6d%13s%13s%10s%7d%7d%12s%5d\n", &p->num1, p->name1, p->major, &p->credit, &p->period, p->teacher, &p->people);
	}
	else printf("提示:无数据，请输入数据！");
}
void lists()                     //浏览学生信息
{
	struct student* p;
	int a;
	p = head2;
	printf("学生编号     学生姓名       所选教材编号       所选教材\n");
	while (p != NULL)
	{
		printf("%6d%13s", &p->num2, p->name2);
		printf("%6d", &p->credit);
		for (a = 0; p->booknum[a] != 0 && a < 14; a++)
			printf("%d", &p->booknum[a]);
		printf("\n");
		p = p->next;
	}
}
void intoc()                       //存储教材信息
{
	FILE* fp;
	struct book* p;
	char filepath[30];
	// fp = "";
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf("\n无法储存!");
		exit(0);
	}
	p = head1;
	while (p != NULL)
	{
		fprintf(fp, "%d%s%s%s%d%d%s%d\n", p->num1, p->name1, p->major, p->credit, p->period, p->teacher, p->people);
		p = p->next;
	}
	fclose(fp);
	printf("已储存入%s文件!\n", fp);
}
void intostu()                            //存储学生信息
{
	FILE* fp;
	struct student* p;
	char filepath[30];
	if ((fp = fopen(filepath, "wt")) == NULL)
	{
		printf("\n 无法储存!");
		exit(0);
	}
	p = head2;
	while (p != NULL)
	{
		fwrite(p, sizeof(struct student), 1, fp);
		p = p->next;
	}
	fclose(fp);
	printf("已储存入 %s文件!\n", fp);
}
void into()                      //信息存储函数
{
	int i;
	printf("\t\t\t信息存储\n");
	printf("1.教材信息存储\n");
	printf("2.学生信息存储\n");
	printf("3.返回主菜单\n");
	printf("请输入1-3\n");
	scanf("%d", &i);
	switch (i)
	{
	case(1):intoc(); break;
	case(2):intostu(); break;
	case(3):break;
	}
}
void store()                             //信息存储浏览函数
{
	int i;
	printf("\t\t信息存储和浏览\n");
	printf("1.教材信息浏览\n");
	printf("2.学生信息浏览\n");
	printf("3.信息存储\n");
	printf("4.返回主菜单\n");
	printf("请输入1-4:\n");
	scanf("%d", &i);
	switch (i)
	{
	case(1):listc(); break;
	case(2):lists(); break;
	case(3):into(); break;
	case(4):break;
	}
}
void search1()                      //按学生编号查找学生信息
{
	int a, b;
	struct student* p;
	printf("请输入学生编号");
	scanf("%d", &a);
	p = head2;
	printf("学号       学生姓名    所选教材编号   所选教材\n");
	while (p != NULL)
	{
		if (p->num2 == a)
		{
			printf("%6d%13s ", p->num2, p->name2);
			for (b = 0; p->booknum[b] != 0 && b < 14; b++)
				printf("%d", p->booknum[b]);
			printf("%10d\n", p->credit);
		}
		p = p->next;
	}
}
void search2()                         //按学生姓名查找学生信息
{
	int b;
	char name[20];
	struct student* p;
	printf("请输入要查找的学生姓名:");
	scanf("%s", name);
	p = head2;
	printf("学号       学生姓名     所选教材编号   所选教材\n");
	while (p != NULL)
	{
		if (strcmp(name, p->name2) == 0)
		{
			printf("%6d%13s ", p->num2, p->name2);
			for (b = 0; p->booknum[b] != 0 && b < 14; b++)
				printf("%d", p->booknum[b]);
			printf("%10d\n", p->credit);
		}
		p = p->next;
	}
}
void search()                      //学生信息查找主函数
{
	int i;
	printf("\t\t\t学生信息查找");
	printf("\n1.按学号查找");
	printf("\n2.按姓名查找");
	printf("\n3.返回主菜单");
	printf("\n请输入1-3:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:search1(); break;
	case 2:search2(); break;
	case 3:break;
	}
}


int main()                     //主函数
{
	char m;
	int i;
start:
	printf("\t\t\t*******************************\n");
	printf("\n\t\t\t\t学生购买教材教材系统!\n");
	printf("\n\t\t\t\t欢迎使用此系统!\n");
	printf("\t\t\t*******************************\n");
	printf("\n");
	printf("\t\t\t\t-----目录-----\n");
	printf("\t\t\t|1.录入教材信息\n");
	printf("\t\t\t|2.教材信息管理\n");
	printf("\t\t\t|3.录入学生信息\n");
	printf("\t\t\t|4.学生信息管理\n");
	printf("\t\t\t|5.学生购买教材\n");
	printf("\t\t\t|6.信息存储与浏览\n");
	printf("\t\t\t|7.查找学生信息\n");
	printf("\t\t\t|8.退出系统\n");
	printf("选择功能前面的数字进入功能:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:system("cls"); load();  goto start; break;
	case 2:system("cls"); management(); goto start; break;
	case 3:system("cls"); stu(); goto start; break;
	case 4:system("cls"); managements(); goto start; break;
	case 5:system("cls"); elective(); goto start; break;
	case 6:system("cls"); store(); goto start; break;
	case 7:system("cls"); search(); goto start; break;
	case 8: {system("cls");
		printf("Thank you for using this program!\n\nBye-Bye!\n");
	}
	}
	exit(0);
	return 0;
}


