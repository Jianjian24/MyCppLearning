#include"stud.h"
void enter()                                  /*进入主菜单函数*/
{ 

	int choice,e=0;
	char k;
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t欢迎使用毕业生信息管理系统\t*\n");
    printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t      请选择功能列表      \t*\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t     1.录入毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     2.打印毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     3.增加毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     4.删除毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     5.修改毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     6.统计毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     7.查找毕业生信息  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     8.退出系统        \t\t*\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n\t\t\t\t\t\t   \t\t     请输入序号：");
	scanf_s("%d",&choice);
	printf("\n");
	switch(choice) 
	{
	case 1: input();break; 
	case 2: display(); break;
	case 3: add();break;
	case 4: delet();break;
	case 5: amend();break;
	case 6: preside(); break;
	case 7: find(); break;
	case 8: output();break;
	default: e=1; 
	}
	if(e==1) 
	{	 
		printf("\t\t\t\t\t\t 输入有误,按任意键重新选怿.\n");	 
		k=getchar(); 	 
		 _getch(); 	 
		enter(); 
	} 
} 