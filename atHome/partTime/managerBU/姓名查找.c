#include"stud.h"
int LXR3(char x[20],int *v)
{
	int i;
    for (i=0;i<t+1; i++)
    {
		if (!strcmp(stu[i].name,x))
        {
			*v=i;
			return 1;
        }
    }
    return -1;
}
void find2()                      /*根据姓名查找毕业生信息*/
  {	 	 
	 int v;
	 char a,b[20];
	 int b1;
     system("cls");	 
	 printf("\n\t\t\t查找毕业生信息\n");			
	 printf(" 请输入要查找毕业生的姓名:\n\n");	 
	 scanf("%s",b);
	 b1=LXR3(b,&v);
		 if(b1==1)
		 {
		printf("\n 你要查找的毕业生为:\n");         
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","学号","姓名","性别","班级","QQ号","联系电话","是否就业","就业城市");
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		 

 }
		 if(b1==-1) 
		 {
			 printf("不存在该毕业生,请按任意键返回.\n\n");
			 a=getchar(); 
			 _getch(); 
			 enter();
		 }
	 printf("查找完毕后，请按任意键退出");
	 _getch(); 
	 enter();
}