#define _CRT_SECURE_NO_WARNINGS
#include"stud.h"
void input()                             /*��ҵ����Ϣ¼��ĺ���*/
{
	int x;
	char w,r[20],o; 
	system("cls");
	printf("\n\n");
	printf("\t\t   ��ҵ����Ϣ��¼��.\n\n"); 
	do
	{
		printf("�������%d����ҵ������Ϣ.\n\n",t+1);
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
		printf("\n�Ƿ�Ҫ���������ҵ����Ϣ,������밴 y;�����밴 n.\n");
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
				printf("�����������.\n");
				 _getch();
				enter(); 
		
}