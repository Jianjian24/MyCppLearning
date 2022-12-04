#define _CRT_SECURE_NO_WARNINGS
#include"stud.h"
void input()                             /*毕业生信息录入的函数*/
{
	int x;
	char w,r[20],o; 
	system("cls");
	printf("\n\n");
	printf("\t\t   毕业生信息的录入.\n\n"); 
	do
	{
		printf("请输入第%d个毕业生的信息.\n\n",t+1);
		printf("学号:");
 		scanf("%s",stu[t].num);
		printf("\n");
		printf("姓名:"); 
		scanf("%s",stu[t].name); 
		printf("\n");
    	printf("性别:");
		scanf("%s",stu[t].sex);
		printf("\n");
		printf("班级:");
		scanf("%s",stu[t].cla); 
		printf("\n");
		printf("QQ号:");
		scanf("%s",stu[t].QQ); 
		printf("\n");
		printf("联系电话:");
		scanf("%s",stu[t].tele);
		printf("\n");
		printf("是否就业:"); 
		scanf("%s",stu[t].job); 
		printf("\n");
		printf("就业城市:"); 
		scanf("%s",stu[t].city); 
		printf("\n");
		printf("\n是否要继续输入毕业生信息,如果是请按 y;不是请按 n.\n");
		o=getchar(); 
		w=getchar();
		if(w=='y' || w=='Y')
		{ 
			t++;
			x=1;
		}  
		else 
		{
			t++;
			x=0;} 
	}while(x==1);
	save();
		if(w=='n' || w=='N') 
				printf("按任意键返回.\n");
				 _getch();
				enter(); 
		
}