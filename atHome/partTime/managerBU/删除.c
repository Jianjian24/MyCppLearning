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
void delet()                           /*��ҵ����Ϣ��ɾ��*/
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
	 printf("\n\t\t\tɾ����ҵ����Ϣ\n");			
	 printf(" ������Ҫɾ����ҵ����ѧ��:\n\n");	 
	 scanf("%s",b);
	 getchar();
	 b1=LXR(b,&v);
		 if(b1==1)
		 {
		printf("\n ��Ҫɾ���ı�ҵ��Ϊ:\n");         
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","ѧ��","����","�Ա�","�༶","QQ��","��ϵ�绰","�Ƿ��ҵ","��ҵ����");
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		 

		printf("\n��ȷ��Ҫɾ����?���������� y;���������� n.\n");			 
		 c=getchar();			
		 getchar();			
		 if(c=='y'||c=='Y') 			
		 {
			 for(i=v;i<now;i++)
			 {
				 stu[i]=stu[i+1];
			 }
			 t--;

		printf("ϵͳ��Ϊ��ɾ����Ϣ���밴���������.\n");			 
			 _getch();			 
			 enter();
		 }
		 if(c=='n'||c=='N') 			 
		 { 				 
			 printf("ɾ����Ϣȡ���������������.\n");				 
			 _getch();	             
			 enter(); 			 
		 }
		 }
		 else if(b1==-1)	 		 
		 { 			 
	printf("��Ҫɾ���ı�ҵ��������,�밴���������.\n"); 
			 _getch(); 
			 enter(); 
		 } 		
			 
  }  