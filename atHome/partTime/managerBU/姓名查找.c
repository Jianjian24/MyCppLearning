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
void find2()                      /*�����������ұ�ҵ����Ϣ*/
  {	 	 
	 int v;
	 char a,b[20];
	 int b1;
     system("cls");	 
	 printf("\n\t\t\t���ұ�ҵ����Ϣ\n");			
	 printf(" ������Ҫ���ұ�ҵ��������:\n\n");	 
	 scanf("%s",b);
	 b1=LXR3(b,&v);
		 if(b1==1)
		 {
		printf("\n ��Ҫ���ҵı�ҵ��Ϊ:\n");         
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n","ѧ��","����","�Ա�","�༶","QQ��","��ϵ�绰","�Ƿ��ҵ","��ҵ����");
		printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[v].num,stu[v].name,stu[v].sex,stu[v].cla,stu[v].QQ,stu[v].tele,stu[v].job,stu[v].city);		 

 }
		 if(b1==-1) 
		 {
			 printf("�����ڸñ�ҵ��,�밴���������.\n\n");
			 a=getchar(); 
			 _getch(); 
			 enter();
		 }
	 printf("������Ϻ��밴������˳�");
	 _getch(); 
	 enter();
}