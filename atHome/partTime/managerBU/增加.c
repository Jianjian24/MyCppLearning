#include"stud.h"
void add()                             /*��ҵ����Ϣ������*/
 {
	  int x; 
	  char a,w,r[20]; 
	  system("cls");
	  printf("\n\t\t\t���ӱ�ҵ����Ϣ.\n"); 
      do 
	  { 	
		printf("�������%d ����ҵ������Ϣ.\n\n",t+1);			  
		printf("ѧ��:");
 		scanf("%s",stu[t].num);
		printf("\n");
		printf("����:"); 
		scanf("%s",stu[t].name); 
		printf("\n");
    	printf("�Ա�:");
		scanf("%s",stu[t].sex);
		printf("\n");
		printf("�༶:"); 
		scanf("%s",stu[t].cla); 
		printf("\n");
		printf("QQ��:"); 
		scanf("%s",stu[t].QQ); 
		printf("\n");
		printf("��ϵ�绰:");
		scanf("%s",stu[t].tele);
		printf("\n");
		printf("�Ƿ��ҵ:"); 
		scanf("%s",stu[t].job); 
		printf("\n");
		printf("��ҵ����:"); 
		scanf("%s",stu[t].city); 
		printf("\n");
		a=getchar(); 	
	    printf("\n �Ƿ�Ҫ���������ҵ����Ϣ,������밴 y;�����밴 n.\n\n"); 	
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
		  printf("�����������.\n");
		  _getch();
		  enter();  
	  }
  }