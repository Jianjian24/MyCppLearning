#include"stud.h"
void display()                        /*显示毕业生信息*/
{
	int j;
	FILE*fp;
	system("cls"); 
	printf("\n\n");
	printf("\t\t\t\t\t\t\t            毕业生信息显示.\n\n"); 
	printf("\t\t*******************************************************************************************************************\n\n");
	printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","学号","姓名","性别","班级","QQ号","联系电话","是否就业","就业城市");
	printf("\n");
	if((fp=fopen("lxr.dat","rb"))==NULL)
	{
		printf("\t\t\t\t\t\t\t            无法打开此文件\n");
		exit(0);
	}
	for(j=0;j<t;j++)		
	{ 	
    fread(&stu[j],sizeof(struct student),1,fp);
    printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[j].num,stu[j].name,stu[j].sex,stu[j].cla,stu[j].QQ,stu[j].tele,stu[j].job,stu[j].city);	
	} 
	printf("\t\t*******************************************************************************************************************\n\n");
	printf("\n 按任意键返回.\n");
	fclose(fp);
	_getch();	 
	enter();
}