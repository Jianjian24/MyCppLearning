#include"stud.h"
void add()                             /*毕业生信息的增加*/
 {
	  int x; 
	  char a,w,r[20]; 
	  system("cls");
	  printf("\n\t\t\t增加毕业生信息.\n"); 
      do 
	  { 	
		printf("请输入第%d 个毕业生的信息.\n\n",t+1);			  
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
		a=getchar(); 	
	    printf("\n 是否要继续输入毕业生信息,如果是请按 y;不是请按 n.\n\n"); 	
		t++; 
		w=getchar();	

		  if(w=='y'||w=='Y') 	
		  {			
			  x=1; 	
		  } 	
		  if(w=='n'||w=='N') 	
		  { 		
			  x=0;		
			  break;
		  } 
	  }while(x==1) ;
	 
	  if(x==0)
	  {	 
		  printf("\n");
		  printf("按任意键返回.\n");
		  _getch();
		  enter();  
	  }
  }