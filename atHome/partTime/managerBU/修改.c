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
void amend()                         /*��ҵ����Ϣ���޸�*/ 
  { 	 
	  int z=1,r=t,v1; 
	  char j[20];
	  char c1,c2,d1,d2,e1,e2,f1,f2;
	  char g1,g2,h1,h2,q1,q2,s1,s2;
	  int v;
	  system("cls");	 
	  printf("\n�޸ı�ҵ����Ϣ\n");	 
	  printf("������Ҫ�޸ı�ҵ����ѧ��:\n\n");
	  scanf("%s",j); 
	  v1=LXR1(j,&v);
      if(v1==-1)
	{ 			 
	printf("������ı�ҵ��������,�밴���������.\n"); 			 
			  _getch(); 			 
			  enter(); 		 
	} 		 
	 if(v1==1)
	 {

		  printf("\n��Ҫ�޸ĵı�ҵ��Ϊ:\n");      
	printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","ѧ��","����","�Ա�","�༶","QQ��","��ϵ�绰","�Ƿ��ҵ","��ҵ����");
    printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		  		 
		printf("\n�Ƿ�Ҫ�޸�ѧ��:���밴 y;�����밴 n.");
		  c1=getchar();
		  c2=getchar();
		  if(c2=='y'||c2=='Y')		 
		  { 			 
			  printf("\n��������ȷ��ѧ�ţ�");	
			  scanf("%s",stu[v].num);		 
		  } 		 

		   printf("\n�Ƿ�Ҫ�޸�����:���밴 y;�����밴 n."); 		 
		  d1=getchar(); 		 
		  d2=getchar();
		  if(d2=='y'||d2=='Y')		 
		  { 			 
			  printf("\n��������ȷ��������");	
			  scanf("%s",stu[v].name);		 

		  } 		 

		printf("\n�Ƿ�Ҫ�޸��Ա�:���밴 y;�����밴 n."); 		 
		  e1=getchar(); 		 
	      e2=getchar();
		  if(e2=='y'||e2=='Y')		 
		  { 			 
			  printf("\n��������ȷ���Ա�");
			  scanf("%s",stu[v].sex);		 
		  } 		 
 
		printf("\n�Ƿ�Ҫ�޸İ༶�����밴 y;�����밴 n."); 		 
		  f1=getchar(); 		  
		  f2=getchar();
		  if(f2=='y'||f2=='Y') 		 
		  { 			
			  printf("\n��������ȷ�İ༶��"); 
			  scanf("%s",stu[v].cla); 		
		  } 		 
 
		printf("\n�Ƿ�Ҫ�޸�QQ�ţ����밴 y;�����밴 n."); 		 
		  g1=getchar(); 		  
 		  g2=getchar();
		  if(g2=='y'||g2=='Y') 		 
		  { 			
			  printf("\n��������ȷ��QQ�ţ�");
			  scanf("%s",stu[v].QQ); 		
		  } 		 

 		printf("\n�Ƿ�Ҫ�޸ĵ绰�ţ����밴 y;�����밴 n."); 		 
		  h1=getchar();
		  h2=getchar();
		  if(h2=='y'||h2=='Y') 		 
		  { 			
			  printf("\n��������ȷ�ĵ绰�ţ�"); 
			  scanf("%s",stu[v].tele); 		
		  } 		 

 		printf("\n�Ƿ�Ҫ�޸ľ�ҵ��������밴 y;�����밴 n."); 		 
		  q1=getchar(); 		  
		  q2=getchar();
		  if(q2=='y'||q2=='Y') 		 
		  { 			
			  printf("\n��������ȷ�ľ�ҵ�����");
			  scanf("%s",stu[v].job); 		
		  } 		 

 		printf("\n�Ƿ�Ҫ�޸ľ�ҵ���У����밴 y;�����밴 n."); 		 
		  s1=getchar(); 		  
		  s2=getchar();
		  if(s2=='y'||s2=='Y') 		 
		  { 			
			  printf("\n��������ȷ�ľ�ҵ���У�"); 
			  scanf("%s",stu[v].city); 		
		  } 
	 }		 

			  printf("�밴���������.\n");			 
			  _getch();			 
			  enter(); 		
		  } 
