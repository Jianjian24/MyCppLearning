#include<stdio.h>//头文件，调用标准输入输出函数 
#include<stdlib.h>//调用system函数 
#include<string.h>//调用字符串以及文件处理函数 
#define MAX_THINGS 100
void r2();//管理员菜单 
void luru();//录入商品  
void shanchu();//删除商品 
void yuelan();//阅览商品 
void xiugaisp();//修改商品 
void bh();//修改商品编号 
void mc();//修改商品名称 
void scrq();//修改商品生产日期 
void bzrq();//修改商品保质日期 
void jg();//修改商品价格 
void zl();//修改商品种类 
void fzwz();//修改商品放置位置 
void sl();//修改商品数量 
void fifth();
void mistake();
void xiugai();
void welcome();
struct things//定义商品信息的结构体 
{
	char number[64];//编号 
	char name[64];//商品名称 
	char time[64];//生产日期 
	char endtime[64];//保质日期 
	char mone y[64];//价格 
	char sort[64];//种类 
	char place[64];//放置位置 
	char amount[64];//数量 
};
struct Book
{
	struct things count[MAX_THINGS];//存储商品信息 
	int size;//商品当前的数量 
};
struct Book book;//创建保存商品信息的变量
int main()
{
    memset(&book,0,sizeof(struct Book));//或者用book.size=0;

	system("color E5");
	r2();
}
void welcome()
{
	
}
void xiugai()
{
	
}
void cxsp()
{
	system("cls");
	FILE*fp;
	fp = fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	int h,k;
	printf("\t\t\t\t\t欢迎来到查询商品页面\n");
	j:
	printf("\t\t\t\t\t请输入要查找的商品名称：");
	char search_name[64]={0};
	scanf("%s",search_name);
	int search_flag=-1;
	for(int i=0;i<book.size;i++)
	{
	    if(strcmp(book.count[i].name,search_name) == 0)
		{
			printf("您查找的商品[%s]的信息为:\n编号：%s\t生产日期：%s\t保质日期：%s\t价格：%s\t种类：%s\t放置位置：%s\t数量:%s\n",search_name,book.count[i].number,book.count[i].time,book.count[i].endtime,book.count[i].money,book.count[i].sort,book.count[i].place,book.count[i].amount);
			search_flag=0;
			break;
		}	
	} 
	if(search_flag==-1)
	{
		printf("\t\t\t\t\t您要查找商品不存在\n");
		printf("\t\t\t\t\t请选择以下操作\n");
		printf("\t\t\t\t\t1.重新输入商品名称\n");
		printf("\t\t\t\t\t2.返回上一级\n"); 
		scanf("%d",&h);
		switch (h)//跳转到对应函数
	    {
	        case 1:goto j;//重新输入名称 
		        break;
	        case 2:r2();//返回上一级 
		        break;
		    default:mistake();//未知操作 
	    }
	}
	fclose(fp);
	printf("\t\t\t\t\t请选择以下操作\n");
	printf("\t\t\t\t\t1.返回上一级\n");
	printf("\t\t\t\t\t2.退出系统\n");
	scanf("%d", &k);
	switch (k)//跳转到对应函数
	{
	    case 1:r2();//返回上一级 
		    break;
	    case 2:fifth();//退出系统 
		    break;
		default:mistake();//未知操作 
	}
}
void r2()
{
	int j;  
	system("cls");
	printf("\t\t\t\t\t ----------------------------------\n");
	printf("\t\t\t\t\t|          请选择以下操作          |\n");
	printf("\t\t\t\t\t|          1.查询商品信息          |\n");
	printf("\t\t\t\t\t|          2.录入商品信息          |\n");
	printf("\t\t\t\t\t|          3.修改商品信息          |\n");
	printf("\t\t\t\t\t|          4.删除商品信息          |\n");
	printf("\t\t\t\t\t|          5.阅览所有商品          |\n");
	printf("\t\t\t\t\t|          6.修改密码              |\n");
	printf("\t\t\t\t\t|          7.返回上一级            |\n");
	printf("\t\t\t\t\t|          8.退出系统              |\n");
	printf("\t\t\t\t\t ----------------------------------\n");
	scanf("%d", &j);
	switch (j)//跳转到对应函数
	{
	    case 1:cxsp();//查询商品 
		    break;
	    case 2:luru();//录入商品 
		    break;
	    case 3:xiugaisp();//修改商品 
		    break;
	    case 4:shanchu();//删除商品 
		    break;
		case 5:yuelan();//阅览商品 
		    break;
		case 6:xiugai();//修改密码 
		    break;
		case 7:welcome();// 返回上一级 
		    break;
		case 8:fifth();//退出系统 
		    break;
		default:mistake();//未知操作 
	}
}
void luru()
{
	FILE*fp;
	fp=fopen("things.txt","a");
	system("cls");
    printf("\t\t\t\t\t欢迎来到录入商品界面\n");
    printf("\t\t\t\t\t请输入商品的编号：");
    char number[64] = {0};
    scanf("%s", number);
    printf("\t\t\t\t\t请输入商品的名称：");
    char name[64] = {0};
    scanf("%s", name);
	printf("\t\t\t\t\t请输入商品的生产日期：");
	char time[64] = {0};
    scanf("%s", time);
	printf("\t\t\t\t\t请输入商品的保质日期：");
	char endtime[64] = {0};
    scanf("%s", endtime);
	printf("\t\t\t\t\t请输入商品的价格：");
	char money[64] = {0};
    scanf("%s", money);
	printf("\t\t\t\t\t请输入商品的种类：");
	char sort[64] = {0};
    scanf("%s", sort);
	printf("\t\t\t\t\t请输入商品的放置位置：");
	char place[64] = {0};
    scanf("%s", place);
	printf("\t\t\t\t\t请输入商品的数量：");
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
    printf("\t\t\t\t\t商品添加成功\n"); 
    fclose(fp);
    fp=NULL;
    system("pause");
    printf("\t\t\t\t\t正在跳转");
    system("pause");
    r2();
}
void xiugaisp()
{
	int p; 
	system("cls");
	printf("\t\t\t\t\t欢迎来到修改商品界面\n");
	printf("\t\t\t\t\t您要修改的商品信息为：\n");
	printf("\t\t\t\t\t1.商品编号\n");
	printf("\t\t\t\t\t2.商品名称\n");
	printf("\t\t\t\t\t3.商品生产日期\n");
	printf("\t\t\t\t\t4.商品保质日期\n");
	printf("\t\t\t\t\t5.商品价格\n");
	printf("\t\t\t\t\t6.商品种类\n");
	printf("\t\t\t\t\t7.商品放置位置\n");
	printf("\t\t\t\t\t8.商品数量\n");
	printf("\t\t\t\t\t9.返回上一级\n"); 
	scanf("%d",&p);
	switch (p)//跳转到对应函数
	{
	    case 1:bh();//编号 
		    break;
	    case 2:mc();//名称 
		    break;
	    case 3:scrq();//生产日期 
		    break;
	    case 4:bzrq();//保质日期 
		    break;
		case 5:jg();//价格 
		    break;
		case 6:zl();//种类 
		    break;
		case 7:fzwz();//放置位置 
		    break;
		case 8:sl();//数量 
		    break;
		case 9:r2();//返回上一级 
		    break;
		default:mistake();//未知操作 
	}
}
void bh()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品编号是[%s],您要修改为：",book.count[i].number);
			char new_number[64]={0};
			scanf("%s",new_number);
		    strcpy(book.count[i].number,new_number);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的编号修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void mc()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品名称是[%s],您要修改为：",book.count[i].name);
			char new_name[64]={0};
			scanf("%s",new_name);
		    strcpy(book.count[i].name,new_name);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的名称修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void scrq()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品生产日期是[%s],您要修改为：",book.count[i].time);
			char new_time[64]={0};
			scanf("%s",new_time);
		    strcpy(book.count[i].time,new_time);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的生产日期修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void bzrq()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品保质日期是[%s],您要修改为：",book.count[i].endtime);
			char new_endtime[64]={0};
			scanf("%s",new_endtime);
		    strcpy(book.count[i].endtime,new_endtime);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的保质日期修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void jg()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品价格是[%s],您要修改为：",book.count[i].money);
			char new_money[64]={0};
			scanf("%s",new_money);
		    strcpy(book.count[i].money,new_money);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的价格修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void zl()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品种类是[%s],您要修改为：",book.count[i].sort);
			char new_sort[64]={0};
			scanf("%s",new_sort);
		    strcpy(book.count[i].sort,new_sort);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的种类修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void fzwz()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品放置位置是[%s],您要修改为：",book.count[i].place);
			char new_place[64]={0};
			scanf("%s",new_place);
		    strcpy(book.count[i].place,new_place);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的放置位置修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
	system("pause");
	xiugaisp();
}
void sl()
{
	system("cls");
	FILE*fp;
	fp=fopen("things.txt","r");
	fread(&book,sizeof(struct Book),1,fp);
	printf("\t\t\t\t\t请输入您要修改的商品名称:");
	char name[64]={0};
	scanf("%s",name);
	for(int i=0;i<book.size;i++)
	{
		if(strcmp(book.count[i].name,name)==NULL)
		{
			printf("\t\t\t\t\t您原来的商品数量是[%s],您要修改为：",book.count[i].amount);
			char new_amount[64]={0};
			scanf("%s",new_amount);
		    strcpy(book.count[i].amount,new_amount);
		    fp=fopen("things.txt","r+");
		    fwrite(&book,sizeof(struct Book),1,fp);
		    printf("\t\t\t\t\t商品的数量修改成功！\n");
		    fclose(fp);
		    break;
		}
	}
	printf("\t\t\t\t\t正在返回......\n");
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
	printf("\t\t\t\t\t欢迎来到删除商品页面\n");
	g:
	printf("\t\t\t\t\t请输入您要删除的商品名称："); 
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
		printf("\t\t\t\t\t您要删除的商品[%s]不存在\n",del_name);
		printf("\t\t\t\t\t请选择以下操作\n");
		printf("\t\t\t\t\t1.重新输入商品名称\n");
		printf("\t\t\t\t\t2.返回上一级\n"); 
		scanf("%d",&h);
		switch (h)//跳转到对应函数
	    {
	        case 1:goto g;//重新输入名称 
		        break;
	        case 2:r2();//返回上一级 
		        break;
		    default:mistake();//未知操作 
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
	printf("\t\t\t\t\t删除成功！");
	fclose(fp);
	printf("\t\t\t\t\t正在返回......\n");
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
	printf("编号\t名称\t生产日期\t保质日期\t价格\t种类\t放置位置\t数量\n");
	for(int i=0;i<book.size;i++)
	{
		printf("%s\t%s\t%s\t%s\t\t%s\t%s\t%s\t\t%s\n",book.count[i].number,book.count[i].name,book.count[i].time,book.count[i].endtime,book.count[i].money,book.count[i].sort,book.count[i].place,book.count[i].amount);
	}
	fclose(fp);
	printf("\t\t\t\t\t请选择以下操作\n");
	printf("\t\t\t\t\t1.返回上一级\n");
	printf("\t\t\t\t\t2.退出系统\n");
	scanf("%d", &k);
	switch (k)//跳转到对应函数
	{
	    case 1:r2();//返回上一级 
		    break;
	    case 2:fifth();//退出系统 
		    break;
		default:mistake();//未知操作 
	}
} 
void fifth()
{
	system("cls");
	printf("\t\t\t\t\t感谢使用本系统，欢迎下次使用！");
	system("pause");
	exit(0);
}
void mistake()
{
	int n; 
	system("cls");
	printf("\t\t\t\t\t您输入的操作暂不支持，请期待下一个版本");
	system("pause");
	system("cls");
	printf("\t\t\t\t\t您是否要返回上一级\n");
	printf("\t\t\t\t\t1.是\n");
	printf("\t\t\t\t\t2.否\n");
	scanf("%d", &n);
	switch (n)
	{
	    case 1:welcome();//回到主菜单 
		    break;
	    case 2:fifth();//退出系统 
		    break;
	}
}
