#include"stud.h"
int t=0;
int main()
 {
	
    char password[7];
	int i;
	system("mode con cols=160 lines=50");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t��ӭ�����ҵ����Ϣ����ϵͳ\n\n");            /*��ʼ����   ������֤����*/

	for(i = 0; i < 7; i++)
	{
	password[i]=getch();
		if( password[i]=='\r')
	break;
		printf("*");
	}

	if (strcmp(password, "010617") != NULL)//��ƥ��
	{
	? ? //....
	}
	else//ƥ��
	{
	? ? int pwd = atoi(password);
	? ? enter();
	}

	/*for(i=1;i<=3;i++)
	{
		printf("\n\n");
		printf("\t\t\t\t\t\t\t����������:");
		scanf("%d",&password);
		if(password==510617)
		{*/
			enter();
	//		break;
	//	}
	//	printf("\t\t\t\t\t\t\t            �������!����������!");
	//}
	//printf("\t\t\t\t\t\t\t            ����������������ϵͳ������");
	return 0;
}