#define _CRT_SECURE_NO_WARNINGS//���԰�ȫ��⣬��Ȼʹ��scanf�ᱨ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int N1, N2;
int n = 0;
struct book
{
	int num1;        //�̲ı��
	char name1[20];  //�̲���
	char major[20];
	int credit;
	int period;
	char teacher[20];
	int people;                   //ѡ���Ž̲ĵ�����
	struct book* next;
};

struct student
{
	int num2;
	char name2[20];
	int booknum[50];              //��ѡ�̲ı��
	int credit;                    //��ѡ�̲�ѧ��
	struct student* next;
};
struct book* head1;
struct student* head2;





void input()                 //�Ӽ���¼��̲���Ϣ
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
			printf("������̲ı��:");
			scanf("%d", &p1->num1);
			printf("������̲�����:");
			sscanf_s("%s", p1->name1, 20);
			printf("��������/����:");
			sscanf_s("%s", p1->major, 20);
			printf("������γ�ѧ��:");
			scanf("%d", &p1->credit);
			printf("�������ʱ:");
			scanf("%d", &p1->period);
			printf("�������ʦ����:");
			sscanf_s("%s", p1->teacher, 20);
			n++;
			p1++;
			printf("\n1.��������.\n0.�������.\n");
			printf("��ѡ��");
			scanf("%d", &y);
		} while (y == 1);
		printf("��ʾ���������!��һ������%d��\n", n);
}

void input1()                      //���ļ�¼��̲���Ϣ
{
	FILE* fp;
	//char filepath[20];
	//struct book* p1, * p2;
	char buffer[1024] = { 0 };
	/*printf("��������Ҫ��ȡ��·��:");
	int b=getchar();
	gets_s(filepath,20);
	 if ((fp = fopen(filepath, "r")) == NULL)*/
	fp = fopen("D:\\test.txt", "rb");


	if (fp == NULL)
	{
		printf("�Ҳ��� %s �ļ�!\n", fp);
		exit(0);
	}
	fwrite(buffer, sizeof(char), 1, fp);
	//p1 = p2 = (struct book*)malloc(sizeof(struct book));

	fread(buffer, sizeof(char), 1, fp);
	printf(buffer);
	fclose(fp);
	//fread(fp, "%d%s%s%c%d%d%s%d", &p1->num1, &p1->name1, &p1->major, &p1->credit, &p1->period, &p1->teacher, &p1->people, 20, 20, 20, 20, 20, 20, 20, 20, 20_)
	//fscanf_s(fp, "%d%s%s%c%d%d%s%d", &p1->num1, &p1->name1, &p1->major, &p1->credit, &p1->period, &p1->teacher, &p1->people,20,20,20,20,20,20,20,20,20);
		/*while (!feof(fp))//feo���������ж��ļ�����
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
void load()             //¼��̲���Ϣ����
{
	int i;
	printf("\t\t\t¼��̲���Ϣ\n");
	printf("\n1.�Ӽ���¼��");
	printf("\n2.���ļ�¼��");
	printf("\n3.�������˵�\n");
	printf("��ѡ��1-3:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:input(); break;
	case 2:input1(); break;
	case 3:break;
	}
}



void insert(struct book* inbook)             //����̲���Ϣ
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
void delect(int num1)             //ɾ���̲���Ϣ
{
	struct book* p1, * p2;
	p2 = 0;
	if (head1 == NULL)
	{
		printf("\n�޷�ɾ��!\n");
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
		printf("��ɾ��\n");
		N1 = N1 - 1;
	}
	else
		printf("û�д˽̲�\n");
end:;
}
void management()             //�̲���Ϣ������
{
	struct book* p1;
	int i, num1;
	printf("\t\t\t�̲���Ϣ����\n");
	printf("1.��ӽ̲�\n");
	printf("2.ɾ���̲�\n");
	printf("3.����\n");
	printf("������1-3:\n");
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
				printf("������̲ı��:");
				scanf("%d", &p1->num1);
				printf("������̲�����:");
				scanf("%s", p1->name1);
				printf("��������/����:");
				scanf("%s", p1->major);
				printf("������ѧ��:");
				scanf("%d", &p1->credit);
				printf("�������ʱ:");
				scanf("%d", &p1->period);
				printf("�������ʦ����:");
				scanf("%s", p1->teacher);
				n++;
				p1++;
				printf("\n1.��������.\n0.�������.\n");
				printf("��ѡ��");
				scanf("%d", &y);
			} while (y == 1);
			printf("��ʾ���������!��һ������%d��\n", n);

	}  break;
	case 2:printf("��������Ҫɾ���Ľ̲ı��:\n");
		scanf("%d", &num1);
		delect(num1); break;
	case 3:break;
	}
}
void putinstu(void)           //�Ӽ���¼��ѧ����Ϣ
{
	int i;
	int y;
	int n = 0;
	struct student* p1, * p2;
	N2 = 0;
	p1 = p2 = (struct student*)malloc(sizeof(struct student));
	do
	{
		printf("ѧ��:\t");
		scanf("%d", &p1->num2);
		printf("����:\t");
		scanf("%s", p1->name2);
		p1->credit = 0;
		for (i = 0; i < 20; i++) p1->booknum[i] = 0;
		head2 = NULL;
		n++;
		p1++;
		printf("\n1.��������.\n0.�������.\n");
		printf("��ѡ��");
		scanf("%d", &y);
	} while (y == 1);
	printf("��ʾ���������!��һ������%d��\n", n);
}
void putinstu2()              //���ļ�¼��ѧ����Ϣ
{
	int i = 0;
	FILE* fp;
	char filepath[20];
	struct student* p1, * p2;
	N2 = 0;
	printf("��������Ҫ��ȡ��·��:");
	int b = getchar();
	gets_s(filepath, 20);
	if ((fp = fopen(filepath, "r")) == NULL)
	{
		printf("�Ҳ��� %s �ļ�!\n", filepath);
		exit(0);
	}
	p1 = p2 = (struct student*)malloc(sizeof(struct student));
	fread(p1, sizeof(struct student), 1, fp);//fread()������гɹ���ȡԪ�ظ��������ɹ�exit(0)
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
void stu()               //¼��ѧ����Ϣ����
{
	int i;
	printf("\t\t\t¼��ѧ����Ϣ\n");
	printf("\n1.�Ӽ���¼��\n");
	printf("2.���ļ�¼��\n");
	printf("3.�������˵�\n");
	printf("������1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:putinstu(); break;
	case 2:putinstu2(); break;
	case 3:break;
	}
}


void inserts(struct student* incouse)             //����ѧ����Ϣ
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
void delectstu(int num2)                   //ɾ��ѧ����Ϣ
{
	struct student* p1, * p2;
	p2 = 0;
	if (head2 == NULL)
	{
		printf("\n�޷�ɾ��\n");
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
		printf("��ɾ��\n");
		N2 = N2 - 1;
	}
	else
		printf("û�д�ѧ�����\n");
end:;
}
void managements()          //ѧ����Ϣ������
{
	struct student* p1;
	int i, num2;
	printf("\t\t\tѧ����Ϣ����\n");
	printf("1.���ѧ����Ϣ\n");
	printf("2.ɾ��ѧ����Ϣ\n");
	printf("3.�������˵�\n");
	printf("��ѡ��1-3:\n");
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



	case 2: {printf("��������Ҫɾ����ѧ�����:\n");
		scanf("%d", &num2);
		delectstu(num2); } break;
	case 3:break;
	}
}
void elect()             //ѧ�����̲�
{
	struct student* s;
	struct book* p;
	int a, i, b;
	printf("����������ѧ��:\n");
	scanf("%d", &a);
	s = head2;
	while ((s->num2) != a && s->next != NULL) s = s->next;
	if (s->num2 != a)
	{
		printf("������Ϣ�����ڣ�����������:\n");
		goto end;
	}
	if ((s->credit) > 10)
	{
		printf("�����Ѿ�����");
		goto end;
	}
	printf("��������Ҫ����Ľ̲ı��\n");
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
void back()              //ѧ���˽̲�
{
	struct student* p;
	struct book* p1;
	int b, i, j, a;
	printf("����������ѧ��:\n");
	scanf("%d", &a);
	p = head2;
	while (p->num2 != a && p != NULL) p = p->next;
	if (p == NULL)
		printf("������Ϣ������:\n");
	else
	{
		printf("��������Ҫ�˵Ľ̲�:\n");
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
void elective()             //ѧ�����̲Ĺ���
{
	int i;
	printf("\t\t\tѧ�����̲���Ϣ����\n");
	printf("1.ѡ�̲�\n");
	printf("2.�˽̲�\n");
	printf("3.�������˵�\n");
	printf("������1-3:\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:elect(); break;
	case 2:back(); break;
	case 3:break;
	}
}
void listc()                 //����̲���Ϣ
{
	struct book* p;
	p = 0;
	int i, j;
	if (n != 0)
	{
		printf("ѧ������:%d\n", n);
		printf("�̲ı��    �̲�����    ����    �̲�����    ѧ��    ��ʱ    ��ʦ   ѡ������\n");
		printf("-----------------------------------------------------\n");
		for (i = 0; i < n; i++)
			printf("%6d%13s%13s%10s%7d%7d%12s%5d\n", &p->num1, p->name1, p->major, &p->credit, &p->period, p->teacher, &p->people);
	}
	else printf("��ʾ:�����ݣ����������ݣ�");
}
void lists()                     //���ѧ����Ϣ
{
	struct student* p;
	int a;
	p = head2;
	printf("ѧ�����     ѧ������       ��ѡ�̲ı��       ��ѡ�̲�\n");
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
void intoc()                       //�洢�̲���Ϣ
{
	FILE* fp;
	struct book* p;
	char filepath[30];
	// fp = "";
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf("\n�޷�����!");
		exit(0);
	}
	p = head1;
	while (p != NULL)
	{
		fprintf(fp, "%d%s%s%s%d%d%s%d\n", p->num1, p->name1, p->major, p->credit, p->period, p->teacher, p->people);
		p = p->next;
	}
	fclose(fp);
	printf("�Ѵ�����%s�ļ�!\n", fp);
}
void intostu()                            //�洢ѧ����Ϣ
{
	FILE* fp;
	struct student* p;
	char filepath[30];
	if ((fp = fopen(filepath, "wt")) == NULL)
	{
		printf("\n �޷�����!");
		exit(0);
	}
	p = head2;
	while (p != NULL)
	{
		fwrite(p, sizeof(struct student), 1, fp);
		p = p->next;
	}
	fclose(fp);
	printf("�Ѵ����� %s�ļ�!\n", fp);
}
void into()                      //��Ϣ�洢����
{
	int i;
	printf("\t\t\t��Ϣ�洢\n");
	printf("1.�̲���Ϣ�洢\n");
	printf("2.ѧ����Ϣ�洢\n");
	printf("3.�������˵�\n");
	printf("������1-3\n");
	scanf("%d", &i);
	switch (i)
	{
	case(1):intoc(); break;
	case(2):intostu(); break;
	case(3):break;
	}
}
void store()                             //��Ϣ�洢�������
{
	int i;
	printf("\t\t��Ϣ�洢�����\n");
	printf("1.�̲���Ϣ���\n");
	printf("2.ѧ����Ϣ���\n");
	printf("3.��Ϣ�洢\n");
	printf("4.�������˵�\n");
	printf("������1-4:\n");
	scanf("%d", &i);
	switch (i)
	{
	case(1):listc(); break;
	case(2):lists(); break;
	case(3):into(); break;
	case(4):break;
	}
}
void search1()                      //��ѧ����Ų���ѧ����Ϣ
{
	int a, b;
	struct student* p;
	printf("������ѧ�����");
	scanf("%d", &a);
	p = head2;
	printf("ѧ��       ѧ������    ��ѡ�̲ı��   ��ѡ�̲�\n");
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
void search2()                         //��ѧ����������ѧ����Ϣ
{
	int b;
	char name[20];
	struct student* p;
	printf("������Ҫ���ҵ�ѧ������:");
	scanf("%s", name);
	p = head2;
	printf("ѧ��       ѧ������     ��ѡ�̲ı��   ��ѡ�̲�\n");
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
void search()                      //ѧ����Ϣ����������
{
	int i;
	printf("\t\t\tѧ����Ϣ����");
	printf("\n1.��ѧ�Ų���");
	printf("\n2.����������");
	printf("\n3.�������˵�");
	printf("\n������1-3:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:search1(); break;
	case 2:search2(); break;
	case 3:break;
	}
}


int main()                     //������
{
	char m;
	int i;
start:
	printf("\t\t\t*******************************\n");
	printf("\n\t\t\t\tѧ������̲Ľ̲�ϵͳ!\n");
	printf("\n\t\t\t\t��ӭʹ�ô�ϵͳ!\n");
	printf("\t\t\t*******************************\n");
	printf("\n");
	printf("\t\t\t\t-----Ŀ¼-----\n");
	printf("\t\t\t|1.¼��̲���Ϣ\n");
	printf("\t\t\t|2.�̲���Ϣ����\n");
	printf("\t\t\t|3.¼��ѧ����Ϣ\n");
	printf("\t\t\t|4.ѧ����Ϣ����\n");
	printf("\t\t\t|5.ѧ������̲�\n");
	printf("\t\t\t|6.��Ϣ�洢�����\n");
	printf("\t\t\t|7.����ѧ����Ϣ\n");
	printf("\t\t\t|8.�˳�ϵͳ\n");
	printf("ѡ����ǰ������ֽ��빦��:\n");
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


