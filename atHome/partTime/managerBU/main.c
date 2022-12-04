#include"stud.h"
int t=0;
int main()
 {
	
    char password[7];
	int i;
	system("mode con cols=160 lines=50");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t欢迎进入毕业生信息管理系统\n\n");            /*初始界面   输入验证密码*/

	for(i = 0; i < 7; i++)
	{
	password[i]=getch();
		if( password[i]=='\r')
	break;
		printf("*");
	}

	if (strcmp(password, "010617") != NULL)//不匹配
	{
	? ? //....
	}
	else//匹配
	{
	? ? int pwd = atoi(password);
	? ? enter();
	}

	/*for(i=1;i<=3;i++)
	{
		printf("\n\n");
		printf("\t\t\t\t\t\t\t请输入密码:");
		scanf("%d",&password);
		if(password==510617)
		{*/
			enter();
	//		break;
	//	}
	//	printf("\t\t\t\t\t\t\t            输入错误!请重新输入!");
	//}
	//printf("\t\t\t\t\t\t\t            密码输入三次有误！系统锁定！");
	return 0;
}