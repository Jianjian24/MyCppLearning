#include"stud.h"
int LXR1(char x[20],int *v)
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
void amend()                         /*毕业生信息的修改*/ 
  { 	 
	  int z=1,r=t,v1; 
	  char j[20];
	  char c1,c2,d1,d2,e1,e2,f1,f2;
	  char g1,g2,h1,h2,q1,q2,s1,s2;
	  int v;
	  system("cls");	 
	  printf("\n修改毕业生信息\n");	 
	  printf("请输入要修改毕业生的学号:\n\n");
	  scanf("%s",j); 
	  v1=LXR1(j,&v);
      if(v1==-1)
	{ 			 
	printf("你输入的毕业生不存在,请按任意键返回.\n"); 			 
			  _getch(); 			 
			  enter(); 		 
	} 		 
	 if(v1==1)
	 {

		  printf("\n你要修改的毕业生为:\n");      
	printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","学号","姓名","性别","班级","QQ号","联系电话","是否就业","就业城市");
    printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		  		 
		printf("\n是否要修改学号:是请按 y;不是请按 n.");
		  c1=getchar();
		  c2=getchar();
		  if(c2=='y'||c2=='Y')		 
		  { 			 
			  printf("\n请输入正确的学号：");	
			  scanf("%s",stu[v].num);		 
		  } 		 

		   printf("\n是否要修改姓名:是请按 y;不是请按 n."); 		 
		  d1=getchar(); 		 
		  d2=getchar();
		  if(d2=='y'||d2=='Y')		 
		  { 			 
			  printf("\n请输入正确的姓名：");	
			  scanf("%s",stu[v].name);		 

		  } 		 

		printf("\n是否要修改性别:是请按 y;不是请按 n."); 		 
		  e1=getchar(); 		 
	      e2=getchar();
		  if(e2=='y'||e2=='Y')		 
		  { 			 
			  printf("\n请输入正确的性别：");
			  scanf("%s",stu[v].sex);		 
		  } 		 
 
		printf("\n是否要修改班级：是请按 y;不是请按 n."); 		 
		  f1=getchar(); 		  
		  f2=getchar();
		  if(f2=='y'||f2=='Y') 		 
		  { 			
			  printf("\n请输入正确的班级："); 
			  scanf("%s",stu[v].cla); 		
		  } 		 
 
		printf("\n是否要修改QQ号：是请按 y;不是请按 n."); 		 
		  g1=getchar(); 		  
 		  g2=getchar();
		  if(g2=='y'||g2=='Y') 		 
		  { 			
			  printf("\n请输入正确的QQ号：");
			  scanf("%s",stu[v].QQ); 		
		  } 		 

 		printf("\n是否要修改电话号：是请按 y;不是请按 n."); 		 
		  h1=getchar();
		  h2=getchar();
		  if(h2=='y'||h2=='Y') 		 
		  { 			
			  printf("\n请输入正确的电话号："); 
			  scanf("%s",stu[v].tele); 		
		  } 		 

 		printf("\n是否要修改就业情况：是请按 y;不是请按 n."); 		 
		  q1=getchar(); 		  
		  q2=getchar();
		  if(q2=='y'||q2=='Y') 		 
		  { 			
			  printf("\n请输入正确的就业情况：");
			  scanf("%s",stu[v].job); 		
		  } 		 

 		printf("\n是否要修改就业城市：是请按 y;不是请按 n."); 		 
		  s1=getchar(); 		  
		  s2=getchar();
		  if(s2=='y'||s2=='Y') 		 
		  { 			
			  printf("\n请输入正确的就业城市："); 
			  scanf("%s",stu[v].city); 		
		  } 
	 }		 

			  printf("请按任意键返回.\n");			 
			  _getch();			 
			  enter(); 		
		  } 
