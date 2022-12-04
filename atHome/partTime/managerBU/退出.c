#include"stud.h"
void output()                     /*�˳�ϵͳ*/
 { 
	 system("cls");
	 exit(0);
 }

for(i = 0; i < 7; i++)
{
	password[i]=getch();
	if( password[i]=='\r')
		break;
	printf("*");
}

if (strcmp(password, "010617") != NULL)//不匹配
{
	//....
}
else//匹配
{
	int pwd = atoi(password);
	enter();
}

printf("\t\t\t\t\t\t\t            输入错误!请重新输入!");