#include"stud.h"
void enter()                                  /*�������˵�����*/
{ 

	int choice,e=0;
	char k;
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t��ӭʹ�ñ�ҵ����Ϣ����ϵͳ\t*\n");
    printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t      ��ѡ�����б�      \t*\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n");
	printf("\t\t\t\t\t\t\t*\t     1.¼���ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     2.��ӡ��ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     3.���ӱ�ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     4.ɾ����ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     5.�޸ı�ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     6.ͳ�Ʊ�ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     7.���ұ�ҵ����Ϣ  \t\t*\n");
	printf("\t\t\t\t\t\t\t*\t     8.�˳�ϵͳ        \t\t*\n");
	printf("\t\t\t\t\t\t   \t*****************************************\t\t\n\t\t\t\t\t\t   \t\t     ��������ţ�");
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
		printf("\t\t\t\t\t\t ��������,�����������ѡ��.\n");	 
		k=getchar(); 	 
		 _getch(); 	 
		enter(); 
	} 
} 