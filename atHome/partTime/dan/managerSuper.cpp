#include<stdio.h>//ͷ�ļ������ñ�׼����������� 
#include<stdlib.h>//����system���� 
#include<string.h>//�����ַ����Լ��ļ������� 
#include<math.h>//������ѧ���� 
#define MAX_THINGS 100
void choose();//��һ���˵���ѡ���� 
void first();//ע���˺ź��� 
void second();//�û���¼���� 
void third();//����Ա��¼���� 
void fourth();//�һ����� 
void fifth();//�˳�ϵͳ���� 
void mistake();//δ֪���� 
void welcome();//���˵� 
void p2();//�û��˵� 
void yhxx();//�û���Ϣ����
void cxsp();//��ѯ��Ʒ 
void q1();//�ж��Ƿ�Ҫ�������� 
void chongzhi();//��ֵҳ�� 
void xiugaimm();//�޸��û����� 
void r2();//����Ա�˵� 
void luru();//¼����Ʒ 
void xiugai();//�޸Ĺ���Ա���� 
void shanchu();//ɾ����Ʒ 
void yuelan();//������Ʒ 
void xiugaisp();//�޸���Ʒ 
void bh();//�޸���Ʒ��� 
void mc();//�޸���Ʒ���� 
void scrq();//�޸���Ʒ�������� 
void bzrq();//�޸���Ʒ�������� 
void jg();//�޸���Ʒ�۸� 
void zl();//�޸���Ʒ���� 
void fzwz();//�޸���Ʒ����λ�� 
void sl();//�޸���Ʒ���� 
void q2();//�жϹ���Ա�Ƿ���Ҫ������������ 
typedef struct users//�����˺ŵĽṹ��  
{
    char id[10]; //�˺� 
    char password[20]; //���� 
     
}users;
struct things//������Ʒ��Ϣ�Ľṹ�� 
{
	char number[64];//��� 
	char name[64];//��Ʒ���� 
	char time[64];//�������� 
	char endtime[64];//�������� 
	char money[64];//�۸� 
	char sort[64];//���� 
	char place[64];//����λ�� 
	char amount[64];//���� 
};
struct Book
{
	struct things count[MAX_THINGS];//�洢��Ʒ��Ϣ 
	int size;//��Ʒ��ǰ������ 
};
struct Book book;//����������Ʒ��Ϣ�ı���
int main()
{
	system("color E5");
	welcome();
}
void welcome()
{
	system("cls");
	//���˵�ҳ�� 
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t        |   ��ӭʹ�ó�����Ʒ��Ϣ����ϵͳ   |\n");
	printf("\t\t\t\t\t|          ��ѡ�����²���          |\n");
	printf("\t\t\t\t\t|          1.ע���˺�              |\n");
	printf("\t\t\t\t\t|          2.�û���¼              |\n");
	printf("\t\t\t\t\t|          3.����Ա��¼            |\n");
	printf("\t\t\t\t\t|          4.�һ�����              |\n");
	printf("\t\t\t\t\t|          5.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	choose();//����ѡ���� 
} 
void choose()//��һ���˵���ѡ����
{
	int choose;
	scanf("%d", &choose);//�������� 
	switch (choose)//��ת����Ӧ����
	{
	    case 1:first();//ע���˺� 
		    break;
	    case 2:second();//�û���¼ 
		    break;
	    case 3:third();//����Ա��¼ 
		    break;
		case 4:fourth();//�һ�����
		    break; 
	    case 5:fifth();//�˳���¼ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void first()
{
    users a,b;
    FILE *fp;
    char password_two[20];
    system("cls");
    printf("\t\t\t\t\t��ӭ����ע����棡\n");
    b:
    fp = fopen("userdata.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� ��b
    printf("\t\t\t\t\t����������˺�:");
    scanf("%s",&a.id);
    while(1)
    {    
        if (strcmp(a.id, b.id)) /*������������*/
        {
            if(!feof(fp))
            {     
                fread(&b, sizeof(struct users), 1, fp);
            }   
            else
            {
                break;
            }        
        }
        else
        {   
            printf("\t\t\t\t\t���û����Ѵ��ڣ�������ע�ᣡ\n"); 
            fclose(fp);
            fp=NULL;
            goto b;      
        }
    }        
    printf("\t\t\t\t\t����������:");
    scanf("%s",&a.password);
    system("cls");
    printf("\t\t\t\t\t���������룬ȷ������:");
    scanf(" %s",&password_two);
    do{
        if(!strcmp(a.password,password_two))
		{
            fp = fopen("userdata.txt","a");
            fwrite(&a, sizeof(struct users), 1, fp);           
            fclose(fp);
            goto a;
        }
		else
		{
            printf("\t\t\t\t\t�������벻ƥ�䣡���������룡\n");
            printf("\t\t\t\t\t����������:");
            scanf("%s",&a.password);
            printf("\t\t\t\t\t��ȷ������:");
            scanf("%s",&password_two);
        }
    }while(1);
    a:
	printf("\t\t\t\t\t����ע��ɹ�\n");
	system("pause");
	printf("\t\t\t\t\t���ڷ��ز˵�......\n");
	system("pause");
	welcome();
}
void second()
{
	users a,b;
    FILE *fp;
    system("cls");
    printf("\t\t\t\t\t��ӭ�����û���¼���棡\n");
    fp = fopen("userdata.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t�������˺�:");
    scanf("%s",&a.id);   
    while (1)
    {   
        if (!strcmp(a.id, b.id))         //����д��û���
        {
            break;       
        }            
        else 
        {                                   
            if(!feof(fp))
            {                    
                fread(&b, sizeof(struct users), 1, fp);
            }   
            else
            {
                printf("\t\t\t\t\t���û���������\n");       
                fclose(fp); 
                system("pause");
				q1(); 
            }
        }
    }
       printf("\t\t\t\t\t����������:");       
       do{   
           scanf("%s",&a.password); 
           if (strcmp(a.password, b.password)==0)            /*�������ƥ��*/            
            {  
                fclose(fp);
                printf("\t\t\t\t\t��¼�ɹ�,��ӭʹ��!");             
            }
           else  
           {    
                q1();
           }
        }while(strcmp(a.password, b.password));
	system("pause");
	printf("\t\t\t\t\t������ת......");
	system("pause");
	p2();
}
void q1()
{
	int w; 
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          �������              |\n");
	printf("\t\t\t\t\t|          ��ѡ�����²���          |\n");
	printf("\t\t\t\t\t|          1.���������˺�����      |\n");
	printf("\t\t\t\t\t|          2.������һ��            |\n");
	printf("\t\t\t\t\t|          3.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &w);//��������
	switch (w)//��ת����Ӧ����
	{
	    case 1:second();//���������˺����� 
		    break;
	    case 2:welcome();//���ز˵� 
		    break;
	    case 3:fifth();//�˳�ϵͳ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void p2()
{
	int y;
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          ��ѡ�����²���          |\n");
	printf("\t\t\t\t\t|          1.�û���Ϣ����          |\n");
	printf("\t\t\t\t\t|          2.��ѯ��Ʒ��Ϣ          |\n");
	printf("\t\t\t\t\t|          3.������һ��            |\n");
	printf("\t\t\t\t\t|          4.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &y);//��������
	switch (y)//��ת����Ӧ����
	{
	    case 1:yhxx();//�û���Ϣ���� 
		    break;
	    case 2:cxsp();//��ѯ��Ʒ��Ϣ 
		    break;
	    case 3:welcome();//������һ�� 
		    break;
	    case 4:fifth();//�˳���¼ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void yhxx()
{
	int j; 
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          ���Ļ�Ա�ȼ�Ϊ����ͭ    |\n");
	printf("\t\t\t\t\t|          �����˻����Ϊ��0       |\n");
	printf("\t\t\t\t\t|          1.�Ƿ���г�ֵ          |\n");
	printf("\t\t\t\t\t|          2.�޸�����              |\n");
	printf("\t\t\t\t\t|          3.������һ��            |\n");
	printf("\t\t\t\t\t|          4.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &j);
	switch (j)//��ת����Ӧ����
	{
	    case 1:chongzhi();//�û���ֵ 
		    break;
	    case 2:xiugaimm();//�޸����� 
		    break;
	    case 3:p2();//������һ�� 
		    break;
	    case 4:fifth();//�˳���¼ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void chongzhi()
{
}
void xiugaimm()
{
	users a,b;
    FILE *fp;
    int t;
    char temp[10];
    char now_a[10];
    char now_b[10];
    system("cls");
    printf("\t\t\t\t\t��ӭ�����޸��������\n");
    f:
    fp = fopen("userdata.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t������ԭ���˺ţ�");
    scanf("%s",&a.id);
    do
    {   
        if (!strcmp(a.id, b.id))         //����д��û���
        {
            break;       
        }
        else 
        {
            if(!feof(fp))
            {                   
                fread(&b, sizeof(struct users), 1, fp);
            }
            else
            {           
                printf("\t\t\t\t\t���û��������ڣ����������룡\n");
                goto f;           
            }
        }
    }while(strcmp(a.id, b.id));
    d:
    fp = fopen("userdata.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t������ԭ������:");
    scanf("%s",&a.password);
    do
    {   
        if (!strcmp(a.password, b.password))      //�д����� 
        {
            break;       
        }
        else 
        {
            if(!feof(fp))
            {     
                fread(&b, sizeof(struct users), 1, fp);
            }
            else
            { 
                printf("\t\t\t\t\t�����벻��ȷ�����������룡\n");
                goto d;    
            }
        }
    }while(strcmp(a.password, b.password));
    printf("\t\t\t\t\t���������޸�֮������룺");
    scanf("%s",&now_a); 
    if(!strcmp(now_a,a.password))
    {
    	e:
        printf("\t\t\t\t\t������֮ǰ��ͬ\n");
        printf("\t\t\t\t\t1.��������\n");
		printf("\t\t\t\t\t2.��������\n"); 
        scanf("%d",&t);
        switch(t)
        {
            case 1:
                printf("\t\t\t\t\t����֮ǰ����ɹ�\n");
                fclose(fp);
                system("pause");
                printf("\t\t\t\t\t���ڷ���......");
                p2();  
            case 2:
                printf("\t\t\t\t\t��������Ҫ���ĺ������:");
                scanf("%s",&now_b);
                if(!strcmp(now_b,a.password))
                {
                    goto e;
                }
                else
                {
                    strcpy(a.password,now_b);
                    fp = fopen("userdata.txt","r+");
                    fwrite(&a, sizeof(struct users), 1, fp);
                    printf("\t\t\t\t\t������ĳɹ�");
                    fclose(fp);
                    system("pause");
                    printf("\t\t\t\t\t���ڷ���......");
                    p2();
                }
            default:mistake();       
        }   
    }
    else
    {
        strcpy(a.password,now_a);
        fp = fopen("userdata.txt","r+");
        fwrite(&a, sizeof(struct users), 1, fp);
        printf("\t\t\t\t\t������ĳɹ�\n");
        fclose(fp);
        system("pause");
        printf("\t\t\t\t\t���ڷ���......");
        p2();
    }
}
void cxsp()
{
	printf("2");
}
void third()
{
	users a,b;
    FILE *fp;
    system("cls");
    printf("\t\t\t\t\t��ӭ��������Ա��¼���棡\n");
    fp = fopen("manage.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t�������˺�:");
    scanf("%s",&a.id);   
    while (1)
    {   
        if (!strcmp(a.id, b.id))         //����д��û���
        {
            break;       
        }            
        else 
        {                                   
            if(!feof(fp))
            {                    
                fread(&b, sizeof(struct users), 1, fp);
            }   
            else
            {
                printf("\t\t\t\t\t���û���������\n");       
                fclose(fp); 
                system("pause");
				q2();
            }
        }
    }
       
       printf("\t\t\t\t\t����������:");       
       do{   
           scanf("%s",&a.password); 
           if (strcmp(a.password, b.password)==0)            /*�������ƥ��*/            
            {  
                fclose(fp);
                printf("\t\t\t\t\t��¼�ɹ�,��ӭʹ��!");             
            }
           else  
           {    
                printf("\t\t\t\t\t���벻��ȷ!��������������\n");   
           }
        }while(strcmp(a.password, b.password));
	system("pause");
	printf("\t\t\t\t\t������ת......");
	system("pause");
	r2();
}
void q2()
{
	int w; 
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          �������              |\n");
	printf("\t\t\t\t\t|          ��ѡ�����²���          |\n");
	printf("\t\t\t\t\t|          1.���������˺�����      |\n");
	printf("\t\t\t\t\t|          2.������һ��            |\n");
	printf("\t\t\t\t\t|          3.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &w);//��������
	switch (w)//��ת����Ӧ����
	{
	    case 1:third();//���������˺����� 
		    break;
	    case 2:welcome();//���ز˵� 
		    break;
	    case 3:fifth();//�˳�ϵͳ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void r2()
{
	int j;  
    memset(&book,0,sizeof(struct Book));//������book.size=0;
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          ��ѡ�����²���          |\n");
	printf("\t\t\t\t\t|          1.��ѯ��Ʒ��Ϣ          |\n");
	printf("\t\t\t\t\t|          2.¼����Ʒ��Ϣ          |\n");
	printf("\t\t\t\t\t|          3.�޸���Ʒ��Ϣ          |\n");
	printf("\t\t\t\t\t|          4.ɾ����Ʒ��Ϣ          |\n");
	printf("\t\t\t\t\t|          5.����������Ʒ          |\n");
	printf("\t\t\t\t\t|          6.�޸�����              |\n");
	printf("\t\t\t\t\t|          7.������һ��            |\n");
	printf("\t\t\t\t\t|          8.�˳�ϵͳ              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &j);
	switch (j)//��ת����Ӧ����
	{
	    case 1:cxsp();//��ѯ��Ʒ 
		    break;
	    case 2:luru();//¼����Ʒ 
		    break;
	    case 3:xiugaisp();//�޸���Ʒ 
		    break;
	    case 4:shanchu();//ɾ����Ʒ 
		    break;
		case 5:yuelan();//������Ʒ 
		    break;
		case 6:xiugai();//�޸����� 
		    break;
		case 7:welcome();// ������һ�� 
		    break;
		case 8:fifth();//�˳�ϵͳ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void luru()
{
	FILE*fp;
	fp=fopen("things.txt","a");
	system("cls");
    printf("\t\t\t\t\t��ӭ����¼����Ʒ����\n");
    printf("\t\t\t\t\t��������Ʒ�ı�ţ�");
    char number[64] = {0};
    scanf("%s", number);
    printf("\t\t\t\t\t��������Ʒ�����ƣ�");
    char name[64] = {0};
    scanf("%s", name);
	printf("\t\t\t\t\t��������Ʒ���������ڣ�");
	char time[64] = {0};
    scanf("%s", time);
	printf("\t\t\t\t\t��������Ʒ�ı������ڣ�");
	char endtime[64] = {0};
    scanf("%s", endtime);
	printf("\t\t\t\t\t��������Ʒ�ļ۸�");
	char money[64] = {0};
    scanf("%s", money);
	printf("\t\t\t\t\t��������Ʒ�����ࣺ");
	char sort[64] = {0};
    scanf("%s", sort);
	printf("\t\t\t\t\t��������Ʒ�ķ���λ�ã�");
	char place[64] = {0};
    scanf("%s", place);
	printf("\t\t\t\t\t��������Ʒ��������");
	char amount[64] = {0};
    scanf("%s", amount);
    strcpy(book.count[book.size].number, number);
    strcpy(book.count[book.size].name, name);
    strcpy(book.count[book.size].time, time);
    strcpy(book.count[book.size].endtime, endtime);
    strcpy(book.count[book.size].money, money);
    strcpy(book.count[book.size].sort, sort);
    strcpy(book.count[book.size].place, place);
    strcpy(book.count[book.size].amount, amount);
    book.size++;
    fwrite(&book,sizeof(struct Book),1,fp);
    printf("\t\t\t\t\t��Ʒ��ӳɹ�\n"); 
    fclose(fp);
    fp=NULL;
    system("pause");
    printf("\t\t\t\t\t������ת");
    system("pause");
    r2();
}
void xiugaisp()
{
	int p; 
	system("cls");
	printf("\t\t\t\t\t��ӭ�����޸���Ʒ����\n");
	printf("\t\t\t\t\t��Ҫ�޸ĵ���Ʒ��ϢΪ��\n");
	printf("\t\t\t\t\t1.��Ʒ���\n");
	printf("\t\t\t\t\t2.��Ʒ����\n");
	printf("\t\t\t\t\t3.��Ʒ��������\n");
	printf("\t\t\t\t\t4.��Ʒ��������\n");
	printf("\t\t\t\t\t5.��Ʒ�۸�\n");
	printf("\t\t\t\t\t6.��Ʒ����\n");
	printf("\t\t\t\t\t7.��Ʒ����λ��\n");
	printf("\t\t\t\t\t8.��Ʒ����\n");
	printf("\t\t\t\t\t9.������һ��\n"); 
	scanf("%d",&p);
	switch (p)//��ת����Ӧ����
	{
	    case 1:bh();//��� 
		    break;
	    case 2:mc();//���� 
		    break;
	    case 3:scrq();//�������� 
		    break;
	    case 4:bzrq();//�������� 
		    break;
		case 5:jg();//�۸� 
		    break;
		case 6:zl();//���� 
		    break;
		case 7:fzwz();//����λ�� 
		    break;
		case 8:sl();//���� 
		    break;
		case 9:r2();//������һ�� 
		    break;
		default:mistake();//δ֪���� 
	}
}
void bh()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ�����[%s],��Ҫ�޸�Ϊ��",book.count[i].number);
			char new_number[64]={0};
			scanf("%s",new_number);
		    strcpy(book.count[i].number,new_number);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�ı���޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void mc()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ������[%s],��Ҫ�޸�Ϊ��",book.count[i].name);
			char new_name[64]={0};
			scanf("%s",new_name);
		    strcpy(book.count[i].name,new_name);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�������޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void scrq()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ����������[%s],��Ҫ�޸�Ϊ��",book.count[i].time);
			char new_time[64]={0};
			scanf("%s",new_time);
		    strcpy(book.count[i].time,new_time);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�����������޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void bzrq()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ����������[%s],��Ҫ�޸�Ϊ��",book.count[i].endtime);
			char new_endtime[64]={0};
			scanf("%s",new_endtime);
		    strcpy(book.count[i].endtime,new_endtime);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�ı��������޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void jg()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ�۸���[%s],��Ҫ�޸�Ϊ��",book.count[i].money);
			char new_money[64]={0};
			scanf("%s",new_money);
		    strcpy(book.count[i].money,new_money);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�ļ۸��޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void zl()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ������[%s],��Ҫ�޸�Ϊ��",book.count[i].sort);
			char new_sort[64]={0};
			scanf("%s",new_sort);
		    strcpy(book.count[i].sort,new_sort);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�������޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void fzwz()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ����λ����[%s],��Ҫ�޸�Ϊ��",book.count[i].place);
			char new_place[64]={0};
			scanf("%s",new_place);
		    strcpy(book.count[i].place,new_place);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�ķ���λ���޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void sl()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t��������Ҫ�޸ĵ���Ʒ����:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t��ԭ������Ʒ������[%s],��Ҫ�޸�Ϊ��",book.count[i].amount);
			char new_amount[64]={0};
			scanf("%s",new_amount);
		    strcpy(book.count[i].amount,new_amount);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t��Ʒ�������޸ĳɹ���\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	xiugaisp();
}
void shanchu()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	int del_idx=-1;
	printf("\t\t\t\t\t��ӭ����ɾ����Ʒҳ��\n");
	g:
	printf("\t\t\t\t\t��������Ҫɾ������Ʒ���ƣ�"); 
	char del_name[64]={0};
	scanf("%s",del_name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,del_name) == 0)
		{
			del_idx=i;
			break;
		}
	}
	if(del_idx=-1)
	{
		int h;
		printf("\t\t\t\t\t��Ҫɾ������Ʒ[%s]������\n",del_name);
		printf("\t\t\t\t\t��ѡ�����²���\n");
		printf("\t\t\t\t\t1.����������Ʒ����\n");
		printf("\t\t\t\t\t2.������һ��\n"); 
		scanf("%d",&h);
		switch (h)//��ת����Ӧ����
	    {
	        case 1:goto g;//������������ 
		        break;
	        case 2:r2();//������һ�� 
		        break;
		    default:mistake();//δ֪���� 
	    }
	}
	else
	{
		for(int i=del_idx;i<book.size-1;i++)
		{
			book.count[i]=book.count[i+1];
		}
	}
	book.size--;
	fwrite(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\tɾ���ɹ���");
	fclose(fp);
	printf("\t\t\t\t\t���ڷ���......\n");
	system("pause");
	r2();
} 
void yuelan()
{
	FILE*fp;
	fp=fopen("things.txt","r");
	int k;
	system("cls");
	fread(&book,sizeof(struct Book),1,fp);
	printf("���\t����\t��������\t��������\t�۸�\t����\t����λ��\t����\n");
	for(int i=0;i<book.size;i++)
	{
		printf("%s\t%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\n",book.count[i].number,book.count[i].name,book.count[i].time,book.count[i].endtime,book.count[i].money,book.count[i].sort,book.count[i].place,book.count[i].amount);
	}
	fclose(fp);
	printf("\t\t\t\t\t��ѡ�����²���\n");
	printf("\t\t\t\t\t1.������һ��\n");
	printf("\t\t\t\t\t2.�˳�ϵͳ\n");
	scanf("%d", &k);
	switch (k)//��ת����Ӧ����
	{
	    case 1:r2();//������һ�� 
		    break;
	    case 2:fifth();//�˳�ϵͳ 
		    break;
		default:mistake();//δ֪���� 
	}
}
void xiugai()
{
	users a,b;
    FILE *fp;
    int t;
    char temp[10];
    char now_a[10];
    char now_b[10];
    system("cls");
    printf("\t\t\t\t\t��ӭ�����޸��������\n");
    f:
    fp = fopen("manage.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t������ԭ���˺ţ�");
    scanf("%s",&a.id);
    do
    {   
        if (!strcmp(a.id, b.id))         //����д��û���
        {
            break;       
        }
        else 
        {
            if(!feof(fp))
            {                   
                fread(&b, sizeof(struct users), 1, fp);
            }
            else
            {           
                printf("\t\t\t\t\t���û��������ڣ����������룡\n");
                goto f;           
            }
        }
    }while(strcmp(a.id, b.id));
    d:
    fp = fopen("manage.txt","r");
    fread(&b, sizeof(struct users), 1, fp); //����һ���ṹ���ַ��� д��b
    printf("\t\t\t\t\t������ԭ������:");
    scanf("%s",&a.password);
    do
    {   
        if (!strcmp(a.password, b.password))      //�д����� 
        {
            break;       
        }
        else 
        {
            if(!feof(fp))
            {     
                fread(&b, sizeof(struct users), 1, fp);
            }
            else
            { 
                printf("\t\t\t\t\t�����벻��ȷ�����������룡\n");
                goto d;    
            }
        }
    }while(strcmp(a.password, b.password));
    printf("\t\t\t\t\t���������޸�֮������룺");
    scanf("%s",&now_a); 
    if(!strcmp(now_a,a.password))
    {
    	e:
        printf("\t\t\t\t\t������֮ǰ��ͬ\n");
        printf("\t\t\t\t\t1.��������\n");
		printf("\t\t\t\t\t2.��������\n"); 
        scanf("%d",&t);
        switch(t)
        {
            case 1:
                printf("\t\t\t\t\t����֮ǰ����ɹ�\n");
                fclose(fp);
                system("pause");
                printf("\t\t\t\t\t���ڷ���......");
                p2();  
            case 2:
                printf("\t\t\t\t\t��������Ҫ���ĺ������:");
                scanf("%s",&now_b);
                if(!strcmp(now_b,a.password))
                {
                    goto e;
                }
                else
                {
                    strcpy(a.password,now_b);
                    fp = fopen("userdata.txt","r+");
                    fwrite(&a, sizeof(struct users), 1, fp);
                    printf("\t\t\t\t\t������ĳɹ�");
                    fclose(fp);
                    system("pause");
                    printf("\t\t\t\t\t���ڷ���......");
                    p2();
                }
            default:mistake();       
        }   
    }
    else
    {
        strcpy(a.password,now_a);
        fp = fopen("manage.txt","r+");
        fwrite(&a, sizeof(struct users), 1, fp);
        printf("\t\t\t\t\t������ĳɹ�\n");
        fclose(fp);
        system("pause");
        printf("\t\t\t\t\t���ڷ���......");
        r2();
    }
} 
void fourth()
{    
    users a,b;
    FILE *fp;
    char temp[20];
    int count = 0;
    system("cls");
    printf("\t\t\t\t\t��ӭ�����һ�������棡\n");    
    fp = fopen("userdata.txt","r");   
    fread(&b, sizeof(struct users), 1, fp); 
    c:
    printf("\t\t\t\t\t�������˺�:");
    scanf("%s",&a.id);      
    while (1)//���ļ����ҵ����û�������ͬ��id
    { 
        if (!strcmp(a.id, b.id))
        {
            break;
        }
        else
        {
            if (!feof(fp))//û�����ļ�β��������
            {
                fread(&b, sizeof(users), 1, fp);
            }
            else
            {
                printf("\t\t\t\t\t��������˺Ų�����!����������!\n");                
                fclose(fp);            
                goto c;
            }
        }
    }
    printf("\t\t\t\t\t����������%s\n",b.password);
	system("pause");
	printf("\t\t\t\t\t���ڷ�����ҳ��\n");
	system("pause");
	welcome();        
}
void fifth()
{
	system("cls");
	printf("\t\t\t\t\t��лʹ�ñ�ϵͳ����ӭ�´�ʹ�ã�");
	system("pause");
	exit(0);
}
void mistake()
{
	int n; 
	system("cls");
	printf("\t\t\t\t\t������Ĳ����ݲ�֧�֣����ڴ���һ���汾");
	system("pause");
	system("cls");
	printf("\t\t\t\t\t���Ƿ�Ҫ������һ��\n");
	printf("\t\t\t\t\t1.��\n");
	printf("\t\t\t\t\t2.��\n");
	scanf("%d", &n);
	switch (n)
	{
	    case 1:welcome();//�ص����˵� 
		    break;
	    case 2:fifth();//�˳�ϵͳ 
		    break;
	}
}
