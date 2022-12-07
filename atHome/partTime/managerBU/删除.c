#include"stud.h"
int LXR(char x[20],int *v)
{
	int i;
    for (i=0;i<t+1; i++)
    {
		if (!strcmp(stu[i].num,x))
        {
			*v=i;
			return 1;
        }
    }
    return -1;
}
void delet()                           /*毕业生信息的删除*/
 {	 	 
	 int j=t;
	 int v;
	 char c,b[20];
	 int b1;
	 int i=0,now=0;
	 while(strlen(stu[i].num))
	 {
		 i++;
		 now++;
	 }
     system("cls");	 
	 printf("\n\t\t\t删除毕业生信息\n");			
	 printf(" 请输入要删除毕业生的学号:\n\n");	 
	 scanf("%s",b);
	 getchar();
	 b1=LXR(b,&v);
		 if(b1==1)
		 {
		printf("\n 你要删除的毕业生为:\n");         
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","学号","姓名","性别","班级","QQ号","联系电话","是否就业","就业城市");
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		 

		printf("\n你确定要删除吗?如是请输入 y;不是请输入 n.\n");			 
		 c=getchar();			
		 getchar();			
		 if(c=='y'||c=='Y') 			
		 {
			 for(i=v;i<now;i++)
			 {
				 stu[i]=stu[i+1];
			 }
			 t--;

		printf("系统已为你删除信息，请按任意键返回.\n");			 
			 _getch();			 
			 enter();
		 }
		 if(c=='n'||c=='N') 			 
		 { 				 
			 printf("删除信息取消！按任意键返回.\n");				 
			 _getch();	             
			 enter(); 			 
		 }
		 }
		 else if(b1==-1)	 		 
		 { 			 
	printf("你要删除的毕业生不存在,请按任意键返回.\n"); 
			 _getch(); 
			 enter(); 
		 } 		
			 
  }  